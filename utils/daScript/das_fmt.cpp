#include "daScript/daScript.h"
#include "daScript/simulate/fs_file_info.h"
#include <iostream>
#include <optional>

using namespace das;

void require_project_specific_modules();//link time resolved dependencies
das::FileAccessPtr get_file_access( char * pak );//link time resolved dependencies
static string projectFile;

TextPrinter tout;

void print_help () {
    tout
        << "daslang version " << DAS_VERSION_MAJOR << "." << DAS_VERSION_MINOR << "." << DAS_VERSION_PATCH << "\n"
        << "daslang scriptName1 {scriptName2} .. {-main mainFnName} {-log} {-pause} -- {script arguments}\n"
        << "    -v2syntax   enable version 2 syntax (experimental)\n"
        << "    -jit        enable JIT\n"
        << "    -project <path.das_project> path to project file\n"
        << "    -log        output program code\n"
        << "    -pause      pause after errors and pause again before exiting program\n"
        << "    -dry-run    compile and simulate script without execution\n"
        << "    -dasroot    set path to dascript root folder (with daslib)\n"
#if DAS_SMART_PTR_ID
        << "    -track-smart-ptr <id> track smart pointer with id\n"
#endif
        << "    -das-wait-debugger wait for debugger to attach\n"
        << "    -das-profiler enable profiler\n"
        << "    -das-profiler-log-file <file> set profiler log file\n"
        << "    -das-profiler-manual manual profiler control\n"
        << "    -das-profiler-memory memory profiler\n"
        << "daslang -aot <in_script.das> <out_script.das.cpp> {-q} {-p}\n"
        << "    -project <path.das_project> path to project file\n"
        << "    -p          paranoid validation of CPP AOT\n"
        << "    -q          suppress all output\n"
        << "    -dry-run    no changes will be written\n"
        << "    -dasroot    set path to dascript root folder (with daslib)\n"
    ;
}

enum class SyntaxType {
    V1,
    V2,
};

struct FmtCfg {
    SyntaxType inSyntax;
    SyntaxType outSyntax;
};

class FormatVisitor : public Visitor {
public:
    ~FormatVisitor() {}

    virtual void preVisitLet ( ExprLet * let, const VariablePtr & var, bool last ) { 
        std::cout << let->at.column << std::endl;
        // return var;
    }

    virtual void preVisitGlobalLet ( const VariablePtr & ) { 
        std::cout << "asd" << std::endl;
        // return var;
    }

    virtual void preVisitLetInit ( ExprLet * let, const VariablePtr & var, Expression * init ) {
        std::cout << "asd" << std::endl;
    }

    // Print to `loc`
    void flush(LineInfo loc) {

    }

    // print to end of file
    void flush() {

    }

private:
    LineInfo last_line;

};

void format(ProgramPtr program, const string & fn) {
    auto access = get_file_access((char*)(projectFile.empty() ? nullptr : projectFile.c_str()));
    FormatVisitor fmt_visitor;
    std::cout << "Here" << std::endl;
    program.get()->visit(fmt_visitor);
}

std::optional<ProgramPtr> get_program( const string & fn, const string & cppFn, bool dryRun, FmtCfg cfg ) {
    auto access = get_file_access((char*)(projectFile.empty() ? nullptr : projectFile.c_str()));
    bool success = false;
    ModuleGroup dummyGroup;
    CodeOfPolicies policies;
    policies.version_2_syntax = cfg.inSyntax == SyntaxType::V2;
    auto program = compileDaScript(fn,access,tout,dummyGroup,policies);
    if ( !program || program->failed() ) {
        tout << "failed to compile\n";
        for ( auto & err : program->errors ) {
            tout << reportError(err.at, err.what, err.extra, err.fixme, err.cerr);
        }
        return std::nullopt;
    }
    return program;
}

void InitModules() {
        // register modules
    if (!Module::require("$")) {
        NEED_MODULE(Module_BuiltIn);
    }
    if (!Module::require("math")) {
        NEED_MODULE(Module_Math);
    }
    if (!Module::require("raster")) {
        NEED_MODULE(Module_Raster);
    }
    if (!Module::require("strings")) {
        NEED_MODULE(Module_Strings);
    }
    if (!Module::require("rtti")) {
        NEED_MODULE(Module_Rtti);
    }
    if (!Module::require("ast")) {
        NEED_MODULE(Module_Ast);
    }
    if (!Module::require("jit")) {
        NEED_MODULE(Module_Jit);
    }
    if (!Module::require("debugapi")) {
        NEED_MODULE(Module_Debugger);
    }
    NEED_MODULE(Module_Network);
    NEED_MODULE(Module_UriParser);
    NEED_MODULE(Module_JobQue);
    NEED_MODULE(Module_FIO);
    NEED_MODULE(Module_DASBIND);
    require_project_specific_modules();
    #include "modules/external_need.inc"
    Module::Initialize();
    // compile and run

}


int main(int argc, char** argv) {
    vector<string> files;
    for ( int i=1; i < argc; ++i ) {
        files.emplace_back(argv[i]);
    }
    InitModules();
    for ( auto & file: files ) {
        auto prog = get_program(file, "main", false, FmtCfg { SyntaxType::V1, SyntaxType::V2 });
        format(prog.value(), file);
    }
}