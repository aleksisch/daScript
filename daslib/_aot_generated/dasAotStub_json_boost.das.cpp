#include "daScript/misc/platform.h"

#include "daScript/simulate/simulate.h"
#include "daScript/simulate/aot.h"
#include "daScript/simulate/aot_library.h"

 // require builtin
#include "daScript/simulate/bin_serializer.h"
#include "daScript/simulate/runtime_profile.h"
 // require rtti
#include "daScript/simulate/aot_builtin_rtti.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_handle.h"
 // require strings
#include "daScript/simulate/aot_builtin_string.h"
 // require ast
#include "daScript/ast/ast.h"
#include "daScript/simulate/aot_builtin_ast.h"
#include "daScript/ast/ast_generate.h"
 // require math
#include "daScript/simulate/aot_builtin_math.h"
 // require strings_boost
 // require ast_boost
 // require contracts
 // require templates
 // require array_boost
 // require algorithm
 // require templates_boost
 // require macro_boost
 // require defer
 // require json
 // require apply
 // require static_let
 // require enum_trait
 // require json_boost

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4100)   // unreferenced formal parameter
#pragma warning(disable:4189)   // local variable is initialized but not referenced
#pragma warning(disable:4244)   // conversion from 'int32_t' to 'float', possible loss of data
#pragma warning(disable:4114)   // same qualifier more than once
#pragma warning(disable:4623)   // default constructor was implicitly defined as deleted
#pragma warning(disable:4946)   // reinterpret_cast used between related classes
#pragma warning(disable:4269)   // 'const' automatic data initialized with compiler generated default constructor produces unreliable results
#pragma warning(disable:4555)   // result of expression not used
#endif
#if defined(__EDG__)
#pragma diag_suppress 826
#elif defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wreturn-local-addr"
#pragma GCC diagnostic ignored "-Wignored-qualifiers"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsubobject-linkage"
#endif
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wwritable-strings"
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-but-set-variable"
#pragma clang diagnostic ignored "-Wunsequenced"
#pragma clang diagnostic ignored "-Wunused-function"
#endif

namespace das {
namespace _anon_14538537767599647147 {

namespace json_boost { struct BetterJsonMacro; };
namespace json_boost { struct JsonReader; };
namespace json_boost { struct JsonFieldState; };
namespace ast { struct AstFunctionAnnotation; };
namespace ast { struct AstBlockAnnotation; };
namespace ast { struct AstStructureAnnotation; };
namespace ast { struct AstPassMacro; };
namespace ast { struct AstVariantMacro; };
namespace ast { struct AstForLoopMacro; };
namespace ast { struct AstCaptureMacro; };
namespace ast { struct AstTypeMacro; };
namespace ast { struct AstSimulateMacro; };
namespace ast { struct AstReaderMacro; };
namespace ast { struct AstCommentReader; };
namespace ast { struct AstCallMacro; };
namespace ast { struct AstTypeInfoMacro; };
namespace ast { struct AstEnumerationAnnotation; };
namespace ast { struct AstVisitor; };
namespace ast_boost { struct MacroMacro; };
namespace ast_boost { struct TagFunctionAnnotation; };
namespace ast_boost { struct TagStructureAnnotation; };
namespace ast_boost { struct SetupAnyAnnotation; };
namespace ast_boost { struct SetupFunctionAnnotation; };
namespace ast_boost { struct SetupBlockAnnotation; };
namespace ast_boost { struct SetupStructureAnnotation; };
namespace ast_boost { struct SetupEnumerationAnnotation; };
namespace ast_boost { struct SetupContractAnnotation; };
namespace ast_boost { struct SetupReaderMacro; };
namespace ast_boost { struct SetupCommentReader; };
namespace ast_boost { struct SetupVariantMacro; };
namespace ast_boost { struct SetupForLoopMacro; };
namespace ast_boost { struct SetupCaptureMacro; };
namespace ast_boost { struct SetupTypeMacro; };
namespace ast_boost { struct SetupSimulateMacro; };
namespace ast_boost { struct SetupCallMacro; };
namespace ast_boost { struct SetupTypeInfoMacro; };
namespace ast_boost { struct SetupInferMacro; };
namespace ast_boost { struct SetupDirtyInferMacro; };
namespace ast_boost { struct SetupLintMacro; };
namespace ast_boost { struct SetupGlobalLintMacro; };
namespace ast_boost { struct SetupOptimizationMacro; };
namespace ast_boost { struct TagFunctionMacro; };
namespace ast_boost { struct BetterRttiVisitor; };
namespace contracts { struct IsAnyType; };
namespace contracts { struct IsAnyArrayMacro; };
namespace contracts { struct IsAnyEnumMacro; };
namespace contracts { struct IsAnyBitfieldMacro; };
namespace contracts { struct IsAnyVectorType; };
namespace contracts { struct IsAnyStructMacro; };
namespace contracts { struct IsAnyNumericMacro; };
namespace contracts { struct IsAnyWorkhorse; };
namespace contracts { struct IsAnyWorkhorseNonPtrMacro; };
namespace contracts { struct IsAnyTupleNonPtrMacro; };
namespace contracts { struct IsAnyVariantNonPtrMacro; };
namespace contracts { struct IsAnyFunctionNonPtrMacro; };
namespace contracts { struct IsAnyLambdaMacro; };
namespace contracts { struct IsRefMacro; };
namespace contracts { struct IsPointer; };
namespace contracts { struct IsClass; };
namespace contracts { struct IsValueHandle; };
namespace templates { struct DecltypeMacro; };
namespace templates { struct DecltypeNoRefMacro; };
namespace templates { struct TemplateMacro; };
namespace templates_boost { struct Template; };
namespace templates_boost { struct TemplateVisitor; };
namespace templates_boost { struct RemoveDerefVisitor; };
namespace templates_boost { struct QRulesVisitor; };
namespace templates_boost { struct AstQCallMacro; };
namespace templates_boost { struct QMacro; };
namespace templates_boost { struct QBlockMacro; };
namespace templates_boost { struct QBlockToArrayMacro; };
namespace templates_boost { struct QBlockExprMacro; };
namespace templates_boost { struct QTypeMacro; };
namespace templates_boost { struct AstQNamedMacro; };
namespace templates_boost { struct AstQFunctionMacro; };
namespace templates_boost { struct AstQVariableMacro; };
namespace templates_boost { struct AstQNamedClassMacro; };
namespace templates_boost { struct AstQMethodMacro; };
namespace templates_boost { struct AstQNamedTemplateFunctionMacro; };
namespace templates_boost { struct AstQNamedTemplateClassMacro; };
namespace macro_boost { struct MacroVerifyMacro; };
namespace macro_boost { struct CaptureBlock; };
namespace macro_boost { struct CapturedVariable; };
namespace macro_boost { struct ColletFinally; };
namespace macro_boost { struct ColletLabels; };
namespace macro_boost { struct ReturnSkipLockcheck; };
namespace defer { struct DeferMacro; };
namespace defer { struct DeferDeleteMacro; };
namespace json { struct JsonValue; };
namespace json { struct TokenAt; };
namespace json { struct _lambda_json_180_1; };
namespace apply { struct ApplyMacro; };
namespace static_let { struct StaticLetMacro; };
namespace enum_trait { struct EnumFromStringConstruction; };
namespace enum_trait { struct TypeInfoGetEnumLength; };
namespace enum_trait { struct TypeInfoGetEnumNames; };
// unused enumeration CompilationError
// unused enumeration ConstMatters
// unused enumeration RefMatters
// unused enumeration TemporaryMatters
// unused enumeration Type
// unused enumeration ConversionResult
// unused enumeration CaptureMode
// unused enumeration SideEffects
// unused structure AstFunctionAnnotation
// unused structure AstBlockAnnotation
// unused structure AstStructureAnnotation
// unused structure AstPassMacro
namespace ast {

struct AstVariantMacro {
    void * __rtti;
    Func DAS_COMMENT((void,ast::AstVariantMacro)) __finalize;
    Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprIsVariant> const )) visitExprIsVariant;
    Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprAsVariant> const )) visitExprAsVariant;
    Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprSafeAsVariant> const )) visitExprSafeAsVariant;
};
static_assert(sizeof(AstVariantMacro)==40,"structure size mismatch with DAS");
static_assert(offsetof(AstVariantMacro,__rtti)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(AstVariantMacro,__finalize)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(AstVariantMacro,visitExprIsVariant)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(AstVariantMacro,visitExprAsVariant)==24,"structure field offset mismatch with DAS");
static_assert(offsetof(AstVariantMacro,visitExprSafeAsVariant)==32,"structure field offset mismatch with DAS");
}
// unused structure AstForLoopMacro
// unused structure AstCaptureMacro
// unused structure AstTypeMacro
// unused structure AstSimulateMacro
namespace ast {

struct AstReaderMacro {
    void * __rtti;
    Func DAS_COMMENT((void,ast::AstReaderMacro)) __finalize;
    Func DAS_COMMENT((bool,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,ExprReader * const ,int32_t,LineInfo const )) accept;
    Func DAS_COMMENT((char *,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,ExprReader * const ,LineInfo const ,int32_t &,FileInfo * &)) suffix;
    Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprReader> const )) visit;
};
static_assert(sizeof(AstReaderMacro)==40,"structure size mismatch with DAS");
static_assert(offsetof(AstReaderMacro,__rtti)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(AstReaderMacro,__finalize)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(AstReaderMacro,accept)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(AstReaderMacro,suffix)==24,"structure field offset mismatch with DAS");
static_assert(offsetof(AstReaderMacro,visit)==32,"structure field offset mismatch with DAS");
}
// unused structure AstCommentReader
// unused structure AstCallMacro
// unused structure AstTypeInfoMacro
// unused structure AstEnumerationAnnotation
// unused structure AstVisitor
// unused structure MacroMacro
// unused structure TagFunctionAnnotation
// unused structure TagStructureAnnotation
// unused structure SetupAnyAnnotation
// unused structure SetupFunctionAnnotation
// unused structure SetupBlockAnnotation
// unused structure SetupStructureAnnotation
// unused structure SetupEnumerationAnnotation
// unused structure SetupContractAnnotation
// unused structure SetupReaderMacro
// unused structure SetupCommentReader
// unused structure SetupVariantMacro
// unused structure SetupForLoopMacro
// unused structure SetupCaptureMacro
// unused structure SetupTypeMacro
// unused structure SetupSimulateMacro
// unused structure SetupCallMacro
// unused structure SetupTypeInfoMacro
// unused structure SetupInferMacro
// unused structure SetupDirtyInferMacro
// unused structure SetupLintMacro
// unused structure SetupGlobalLintMacro
// unused structure SetupOptimizationMacro
// unused structure TagFunctionMacro
// unused structure BetterRttiVisitor
// unused structure IsAnyType
// unused structure IsAnyArrayMacro
// unused structure IsAnyEnumMacro
// unused structure IsAnyBitfieldMacro
// unused structure IsAnyVectorType
// unused structure IsAnyStructMacro
// unused structure IsAnyNumericMacro
// unused structure IsAnyWorkhorse
// unused structure IsAnyWorkhorseNonPtrMacro
// unused structure IsAnyTupleNonPtrMacro
// unused structure IsAnyVariantNonPtrMacro
// unused structure IsAnyFunctionNonPtrMacro
// unused structure IsAnyLambdaMacro
// unused structure IsRefMacro
// unused structure IsPointer
// unused structure IsClass
// unused structure IsValueHandle
// unused structure DecltypeMacro
// unused structure DecltypeNoRefMacro
// unused structure TemplateMacro
// unused structure Template
// unused structure TemplateVisitor
// unused structure RemoveDerefVisitor
// unused structure QRulesVisitor
// unused structure AstQCallMacro
// unused structure QMacro
// unused structure QBlockMacro
// unused structure QBlockToArrayMacro
// unused structure QBlockExprMacro
// unused structure QTypeMacro
// unused structure AstQNamedMacro
// unused structure AstQFunctionMacro
// unused structure AstQVariableMacro
// unused structure AstQNamedClassMacro
// unused structure AstQMethodMacro
// unused structure AstQNamedTemplateFunctionMacro
// unused structure AstQNamedTemplateClassMacro
// unused structure MacroVerifyMacro
// unused structure CaptureBlock
// unused structure CapturedVariable
// unused structure ColletFinally
// unused structure ColletLabels
// unused structure ReturnSkipLockcheck
// unused structure DeferMacro
// unused structure DeferDeleteMacro
namespace json {

struct JsonValue {
    TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,int64_t,bool,void *> value;
};
static_assert(sizeof(JsonValue)==56,"structure size mismatch with DAS");
static_assert(offsetof(JsonValue,value)==0,"structure field offset mismatch with DAS");
}
// unused structure TokenAt
// unused structure _lambda_json_180_1
// unused structure ApplyMacro
// unused structure StaticLetMacro
// unused structure EnumFromStringConstruction
// unused structure TypeInfoGetEnumLength
// unused structure TypeInfoGetEnumNames
namespace json_boost {

struct BetterJsonMacro {
    void * __rtti;
    Func DAS_COMMENT((void,ast::AstVariantMacro)) __finalize;
    Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprIsVariant> const )) visitExprIsVariant;
    Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprAsVariant> const )) visitExprAsVariant;
    Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstVariantMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprSafeAsVariant> const )) visitExprSafeAsVariant;
};
static_assert(sizeof(BetterJsonMacro)==40,"structure size mismatch with DAS");
static_assert(offsetof(BetterJsonMacro,__rtti)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(BetterJsonMacro,__finalize)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(BetterJsonMacro,visitExprIsVariant)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(BetterJsonMacro,visitExprAsVariant)==24,"structure field offset mismatch with DAS");
static_assert(offsetof(BetterJsonMacro,visitExprSafeAsVariant)==32,"structure field offset mismatch with DAS");
}
namespace json_boost {

struct JsonReader {
    void * __rtti;
    Func DAS_COMMENT((void,ast::AstReaderMacro)) __finalize;
    Func DAS_COMMENT((bool,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,ExprReader * const ,int32_t,LineInfo const )) accept;
    Func DAS_COMMENT((char *,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,ExprReader * const ,LineInfo const ,int32_t &,FileInfo * &)) suffix;
    Func DAS_COMMENT((smart_ptr_raw<Expression>,ast::AstReaderMacro,smart_ptr_raw<Program> const ,Module * const ,smart_ptr_raw<ExprReader> const )) visit;
};
static_assert(sizeof(JsonReader)==40,"structure size mismatch with DAS");
static_assert(offsetof(JsonReader,__rtti)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonReader,__finalize)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonReader,accept)==16,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonReader,suffix)==24,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonReader,visit)==32,"structure field offset mismatch with DAS");
}
namespace json_boost {

struct JsonFieldState {
    char * argName;
    bool enumAsInt;
    bool unescape;
    bool embed;
    bool optional;
};
static_assert(sizeof(JsonFieldState)==16,"structure size mismatch with DAS");
static_assert(offsetof(JsonFieldState,argName)==0,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonFieldState,enumAsInt)==8,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonFieldState,unescape)==9,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonFieldState,embed)==10,"structure field offset mismatch with DAS");
static_assert(offsetof(JsonFieldState,optional)==11,"structure field offset mismatch with DAS");
}


static void resolveTypeInfoAnnotations()
{
    vector<TypeInfo> annotations = {};
    for (auto& ann : annotations) {
        ann.resolveAnnotation();
    }
}


inline void _FuncbuiltinTickpushTick10769833213962245646_6c6993f52ef9a438 ( Context * __context__, TArray<ast::AstVariantMacro *> & __Arr_rename_at_193_0, ast::AstVariantMacro * __value_rename_at_193_1 );
inline StructInfo const  * _FuncrttiTickclass_infoTick15801393167907430156_43d1c02f15d88b09 ( Context * __context__, json_boost::BetterJsonMacro const  & __cl_rename_at_116_2 );
inline void _FuncbuiltinTickpushTick10769833213962245646_7f48da5eed240807 ( Context * __context__, TArray<ast::AstReaderMacro *> & __Arr_rename_at_193_3, ast::AstReaderMacro * __value_rename_at_193_4 );
inline StructInfo const  * _FuncrttiTickclass_infoTick15801393167907430156_180ff594216ab82f ( Context * __context__, json_boost::JsonReader const  & __cl_rename_at_116_5 );
inline double _Funcjson_boostTicknull_coalescingTick1995797521634879908_7f1128b71d01d238 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_6, double __val_rename_at_59_7 );
inline float _Funcjson_boostTicknull_coalescingTick1995797521634879908_9fccb39a77658963 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_8, float __val_rename_at_59_9 );
inline int8_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_c86cf3c97f89733b ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_10, int8_t __val_rename_at_59_11 );
inline int16_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_2e868b17eacf5d5a ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_12, int16_t __val_rename_at_59_13 );
inline int32_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_2f7db68220ccd39e ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_14, int32_t __val_rename_at_59_15 );
inline int64_t _Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_3f851a94af2dbd6a ( Context * __context__, json::JsonValue const  * const  __a_rename_at_71_16, int64_t __val_rename_at_71_17 );
inline uint8_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_3ae4793671dea8da ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_18, uint8_t __val_rename_at_59_19 );
inline uint16_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_7acdfbfbcb894985 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_20, uint16_t __val_rename_at_59_21 );
inline uint32_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_cabd6fed616201a8 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_22, uint32_t __val_rename_at_59_23 );
inline uint64_t _Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_ab1b0bd4ac0339d8 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_71_24, uint64_t __val_rename_at_71_25 );
inline json::JsonValue * _FuncQmarkSqblSqbr_850c72a61124f7d9 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_29_30, char * const  __key_rename_at_29_31 );
inline json::JsonValue * _FuncQmarkSqblSqbr_10228bca30c0e9e ( Context * __context__, json::JsonValue * __a_rename_at_34_32, char * const  __key_rename_at_34_33 );
inline json::JsonValue * _FuncQmarkDot_850c72a61124f7d9 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_39_34, char * const  __key_rename_at_39_35 );
inline json::JsonValue * _FuncQmarkDot_10228bca30c0e9e ( Context * __context__, json::JsonValue * __a_rename_at_44_36, char * const  __key_rename_at_44_37 );
inline json::JsonValue * _FuncQmarkSqblSqbr_ec96f834d9e351cd ( Context * __context__, json::JsonValue const  * const  __a_rename_at_49_38, int32_t __idx_rename_at_49_39 );
inline json::JsonValue * _FuncQmarkSqblSqbr_971e7ca2cc1e757a ( Context * __context__, json::JsonValue * __a_rename_at_54_40, int32_t __idx_rename_at_54_41 );
inline double _FuncQmarkQmark_863d72a25223154e ( Context * __context__, json::JsonValue const  * const  __a_rename_at_85_42, double __val_rename_at_85_43 );
inline float _FuncQmarkQmark_2ab1d2f8767b75bc ( Context * __context__, json::JsonValue const  * const  __a_rename_at_90_44, float __val_rename_at_90_45 );
inline int8_t _FuncQmarkQmark_388cb6d6e2bf8651 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_95_46, int8_t __val_rename_at_95_47 );
inline int16_t _FuncQmarkQmark_9e43bb6636ca112 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_100_48, int16_t __val_rename_at_100_49 );
inline int32_t _FuncQmarkQmark_295897248e5215b1 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_105_50, int32_t __val_rename_at_105_51 );
inline int64_t _FuncQmarkQmark_94ec862d0c868973 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_110_52, int64_t __val_rename_at_110_53 );
inline uint8_t _FuncQmarkQmark_35cb4622a32fe51d ( Context * __context__, json::JsonValue const  * const  __a_rename_at_115_54, uint8_t __val_rename_at_115_55 );
inline uint16_t _FuncQmarkQmark_5eeed4691e151b6a ( Context * __context__, json::JsonValue const  * const  __a_rename_at_120_56, uint16_t __val_rename_at_120_57 );
inline uint32_t _FuncQmarkQmark_8e0b9f136322488d ( Context * __context__, json::JsonValue const  * const  __a_rename_at_125_58, uint32_t __val_rename_at_125_59 );
inline uint64_t _FuncQmarkQmark_aa829e0f9027a2ff ( Context * __context__, json::JsonValue const  * const  __a_rename_at_130_60, uint64_t __val_rename_at_130_61 );
inline bool _FuncQmarkQmark_ca96bf9fe6529e62 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_135_62, bool __val_rename_at_135_63 );
inline char * _FuncQmarkQmark_844f4d981a373600 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_140_64, char * const  __val_rename_at_140_65 );
inline TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,int64_t,bool,void *> const  * _FuncQmarkDotTickvalue_5189e68ec5a54919 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_145_66 );
inline TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,int64_t,bool,void *> * _FuncQmarkDotTickvalue_9c3125530216994c ( Context * __context__, json::JsonValue * __a_rename_at_150_67 );
inline json_boost::JsonFieldState parse_json_annotation_1a187f6166ca89d1 ( Context * __context__, char * const  __name_rename_at_433_68, TArray<TTuple<48,char *,TVariant<32,16,bool,int32_t,uint32_t,int64_t,uint64_t,float,double,char *,vec4f>>> const  & __annotation_rename_at_433_69 );

void __init_script ( Context * __context__, bool __init_shared )
{
}

inline void _FuncbuiltinTickpushTick10769833213962245646_6c6993f52ef9a438 ( Context * __context__, TArray<ast::AstVariantMacro *> &  __Arr_rename_at_193_0, ast::AstVariantMacro * __value_rename_at_193_1 )
{
    das_copy(__Arr_rename_at_193_0(builtin_array_push_back(das_arg<TArray<ast::AstVariantMacro *>>::pass(__Arr_rename_at_193_0),8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))),__context__),__value_rename_at_193_1);
}

inline StructInfo const  * _FuncrttiTickclass_infoTick15801393167907430156_43d1c02f15d88b09 ( Context * __context__, json_boost::BetterJsonMacro const  &  __cl_rename_at_116_2 )
{
    return das_auto_cast<StructInfo const  *>::cast(das_cast<StructInfo const  *>::cast(((das_deref(__context__,das_cast<TypeInfo const  *>::cast(__cl_rename_at_116_2.__rtti),__FILE__,__LINE__)).getStructType())));
}

inline void _FuncbuiltinTickpushTick10769833213962245646_7f48da5eed240807 ( Context * __context__, TArray<ast::AstReaderMacro *> &  __Arr_rename_at_193_3, ast::AstReaderMacro * __value_rename_at_193_4 )
{
    das_copy(__Arr_rename_at_193_3(builtin_array_push_back(das_arg<TArray<ast::AstReaderMacro *>>::pass(__Arr_rename_at_193_3),8,__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))),__context__),__value_rename_at_193_4);
}

inline StructInfo const  * _FuncrttiTickclass_infoTick15801393167907430156_180ff594216ab82f ( Context * __context__, json_boost::JsonReader const  &  __cl_rename_at_116_5 )
{
    return das_auto_cast<StructInfo const  *>::cast(das_cast<StructInfo const  *>::cast(((das_deref(__context__,das_cast<TypeInfo const  *>::cast(__cl_rename_at_116_5.__rtti),__FILE__,__LINE__)).getStructType())));
}

inline double _Funcjson_boostTicknull_coalescingTick1995797521634879908_7f1128b71d01d238 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_6, double __val_rename_at_59_7 )
{
    if ( __a_rename_at_59_6 != nullptr )
    {
        if ( das_get_variant_field<double,8,3>::is(__a_rename_at_59_6->value) )
        {
            return das_auto_cast<double>::cast(double(das_get_variant_field<double,8,3>::as(__a_rename_at_59_6->value,__context__)));
        } else if ( das_get_variant_field<int64_t,8,4>::is(__a_rename_at_59_6->value) )
        {
            return das_auto_cast<double>::cast(double(das_get_variant_field<int64_t,8,4>::as(__a_rename_at_59_6->value,__context__)));
        };
    };
    return das_auto_cast<double>::cast(__val_rename_at_59_7);
}

inline float _Funcjson_boostTicknull_coalescingTick1995797521634879908_9fccb39a77658963 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_8, float __val_rename_at_59_9 )
{
    if ( __a_rename_at_59_8 != nullptr )
    {
        if ( das_get_variant_field<double,8,3>::is(__a_rename_at_59_8->value) )
        {
            return das_auto_cast<float>::cast(float(das_get_variant_field<double,8,3>::as(__a_rename_at_59_8->value,__context__)));
        } else if ( das_get_variant_field<int64_t,8,4>::is(__a_rename_at_59_8->value) )
        {
            return das_auto_cast<float>::cast(float(das_get_variant_field<int64_t,8,4>::as(__a_rename_at_59_8->value,__context__)));
        };
    };
    return das_auto_cast<float>::cast(__val_rename_at_59_9);
}

inline int8_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_c86cf3c97f89733b ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_10, int8_t __val_rename_at_59_11 )
{
    if ( __a_rename_at_59_10 != nullptr )
    {
        if ( das_get_variant_field<double,8,3>::is(__a_rename_at_59_10->value) )
        {
            return das_auto_cast<int8_t>::cast(int8_t(das_get_variant_field<double,8,3>::as(__a_rename_at_59_10->value,__context__)));
        } else if ( das_get_variant_field<int64_t,8,4>::is(__a_rename_at_59_10->value) )
        {
            return das_auto_cast<int8_t>::cast(int8_t(das_get_variant_field<int64_t,8,4>::as(__a_rename_at_59_10->value,__context__)));
        };
    };
    return das_auto_cast<int8_t>::cast(__val_rename_at_59_11);
}

inline int16_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_2e868b17eacf5d5a ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_12, int16_t __val_rename_at_59_13 )
{
    if ( __a_rename_at_59_12 != nullptr )
    {
        if ( das_get_variant_field<double,8,3>::is(__a_rename_at_59_12->value) )
        {
            return das_auto_cast<int16_t>::cast(int16_t(das_get_variant_field<double,8,3>::as(__a_rename_at_59_12->value,__context__)));
        } else if ( das_get_variant_field<int64_t,8,4>::is(__a_rename_at_59_12->value) )
        {
            return das_auto_cast<int16_t>::cast(int16_t(das_get_variant_field<int64_t,8,4>::as(__a_rename_at_59_12->value,__context__)));
        };
    };
    return das_auto_cast<int16_t>::cast(__val_rename_at_59_13);
}

inline int32_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_2f7db68220ccd39e ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_14, int32_t __val_rename_at_59_15 )
{
    if ( __a_rename_at_59_14 != nullptr )
    {
        if ( das_get_variant_field<double,8,3>::is(__a_rename_at_59_14->value) )
        {
            return das_auto_cast<int32_t>::cast(int32_t(das_get_variant_field<double,8,3>::as(__a_rename_at_59_14->value,__context__)));
        } else if ( das_get_variant_field<int64_t,8,4>::is(__a_rename_at_59_14->value) )
        {
            return das_auto_cast<int32_t>::cast(int32_t(das_get_variant_field<int64_t,8,4>::as(__a_rename_at_59_14->value,__context__)));
        };
    };
    return das_auto_cast<int32_t>::cast(__val_rename_at_59_15);
}

inline int64_t _Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_3f851a94af2dbd6a ( Context * __context__, json::JsonValue const  * const  __a_rename_at_71_16, int64_t __val_rename_at_71_17 )
{
    if ( __a_rename_at_71_16 != nullptr )
    {
        if ( das_get_variant_field<double,8,3>::is(__a_rename_at_71_16->value) )
        {
            return das_auto_cast<int64_t>::cast(int64_t(das_get_variant_field<double,8,3>::as(__a_rename_at_71_16->value,__context__)));
        } else if ( das_get_variant_field<int64_t,8,4>::is(__a_rename_at_71_16->value) )
        {
            return das_auto_cast<int64_t>::cast(int64_t(das_get_variant_field<int64_t,8,4>::as(__a_rename_at_71_16->value,__context__)));
        } else if ( das_get_variant_field<char *,8,2>::is(__a_rename_at_71_16->value) )
        {
            return das_auto_cast<int64_t>::cast(string_to_int64(das_get_variant_field<char *,8,2>::as(__a_rename_at_71_16->value,__context__),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))));
        };
    };
    return das_auto_cast<int64_t>::cast(__val_rename_at_71_17);
}

inline uint8_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_3ae4793671dea8da ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_18, uint8_t __val_rename_at_59_19 )
{
    if ( __a_rename_at_59_18 != nullptr )
    {
        if ( das_get_variant_field<double,8,3>::is(__a_rename_at_59_18->value) )
        {
            return das_auto_cast<uint8_t>::cast(uint8_t(das_get_variant_field<double,8,3>::as(__a_rename_at_59_18->value,__context__)));
        } else if ( das_get_variant_field<int64_t,8,4>::is(__a_rename_at_59_18->value) )
        {
            return das_auto_cast<uint8_t>::cast(uint8_t(das_get_variant_field<int64_t,8,4>::as(__a_rename_at_59_18->value,__context__)));
        };
    };
    return das_auto_cast<uint8_t>::cast(__val_rename_at_59_19);
}

inline uint16_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_7acdfbfbcb894985 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_20, uint16_t __val_rename_at_59_21 )
{
    if ( __a_rename_at_59_20 != nullptr )
    {
        if ( das_get_variant_field<double,8,3>::is(__a_rename_at_59_20->value) )
        {
            return das_auto_cast<uint16_t>::cast(uint16_t(das_get_variant_field<double,8,3>::as(__a_rename_at_59_20->value,__context__)));
        } else if ( das_get_variant_field<int64_t,8,4>::is(__a_rename_at_59_20->value) )
        {
            return das_auto_cast<uint16_t>::cast(uint16_t(das_get_variant_field<int64_t,8,4>::as(__a_rename_at_59_20->value,__context__)));
        };
    };
    return das_auto_cast<uint16_t>::cast(__val_rename_at_59_21);
}

inline uint32_t _Funcjson_boostTicknull_coalescingTick1995797521634879908_cabd6fed616201a8 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_59_22, uint32_t __val_rename_at_59_23 )
{
    if ( __a_rename_at_59_22 != nullptr )
    {
        if ( das_get_variant_field<double,8,3>::is(__a_rename_at_59_22->value) )
        {
            return das_auto_cast<uint32_t>::cast(uint32_t(das_get_variant_field<double,8,3>::as(__a_rename_at_59_22->value,__context__)));
        } else if ( das_get_variant_field<int64_t,8,4>::is(__a_rename_at_59_22->value) )
        {
            return das_auto_cast<uint32_t>::cast(uint32_t(das_get_variant_field<int64_t,8,4>::as(__a_rename_at_59_22->value,__context__)));
        };
    };
    return das_auto_cast<uint32_t>::cast(__val_rename_at_59_23);
}

inline uint64_t _Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_ab1b0bd4ac0339d8 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_71_24, uint64_t __val_rename_at_71_25 )
{
    if ( __a_rename_at_71_24 != nullptr )
    {
        if ( das_get_variant_field<double,8,3>::is(__a_rename_at_71_24->value) )
        {
            return das_auto_cast<uint64_t>::cast(uint64_t(das_get_variant_field<double,8,3>::as(__a_rename_at_71_24->value,__context__)));
        } else if ( das_get_variant_field<int64_t,8,4>::is(__a_rename_at_71_24->value) )
        {
            return das_auto_cast<uint64_t>::cast(uint64_t(das_get_variant_field<int64_t,8,4>::as(__a_rename_at_71_24->value,__context__)));
        } else if ( das_get_variant_field<char *,8,2>::is(__a_rename_at_71_24->value) )
        {
            return das_auto_cast<uint64_t>::cast(string_to_uint64(das_get_variant_field<char *,8,2>::as(__a_rename_at_71_24->value,__context__),__context__,((LineInfoArg *)(&LineInfo::g_LineInfoNULL))));
        };
    };
    return das_auto_cast<uint64_t>::cast(__val_rename_at_71_25);
}

inline json::JsonValue * _FuncQmarkSqblSqbr_850c72a61124f7d9 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_29_30, char * const  __key_rename_at_29_31 )
{
    return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_29_30 != nullptr) && das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::is(__a_rename_at_29_30->value)) ? das_auto_cast<json::JsonValue * const >::cast(das_null_coalescing<json::JsonValue *>::get(TTable<char *,json::JsonValue *>::safe_index(&(das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::as(__a_rename_at_29_30->value,__context__)),__key_rename_at_29_31,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877))))) : das_auto_cast<json::JsonValue * const >::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877)))));
}

inline json::JsonValue * _FuncQmarkSqblSqbr_10228bca30c0e9e ( Context * __context__, json::JsonValue * __a_rename_at_34_32, char * const  __key_rename_at_34_33 )
{
    return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_34_32 != nullptr) && das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::is(__a_rename_at_34_32->value)) ? das_auto_cast<json::JsonValue *>::cast(das_null_coalescing<json::JsonValue *>::get(TTable<char *,json::JsonValue *>::safe_index(&(das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::as(__a_rename_at_34_32->value,__context__)),__key_rename_at_34_33,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877))))) : das_auto_cast<json::JsonValue *>::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877)))));
}

inline json::JsonValue * _FuncQmarkDot_850c72a61124f7d9 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_39_34, char * const  __key_rename_at_39_35 )
{
    return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_39_34 != nullptr) && das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::is(__a_rename_at_39_34->value)) ? das_auto_cast<json::JsonValue * const >::cast(das_null_coalescing<json::JsonValue *>::get(TTable<char *,json::JsonValue *>::safe_index(&(das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::as(__a_rename_at_39_34->value,__context__)),__key_rename_at_39_35,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877))))) : das_auto_cast<json::JsonValue * const >::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877)))));
}

inline json::JsonValue * _FuncQmarkDot_10228bca30c0e9e ( Context * __context__, json::JsonValue * __a_rename_at_44_36, char * const  __key_rename_at_44_37 )
{
    return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_44_36 != nullptr) && das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::is(__a_rename_at_44_36->value)) ? das_auto_cast<json::JsonValue *>::cast(das_null_coalescing<json::JsonValue *>::get(TTable<char *,json::JsonValue *>::safe_index(&(das_get_variant_field<TTable<char *,json::JsonValue *>,8,0>::as(__a_rename_at_44_36->value,__context__)),__key_rename_at_44_37,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877))))) : das_auto_cast<json::JsonValue *>::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877)))));
}

inline json::JsonValue * _FuncQmarkSqblSqbr_ec96f834d9e351cd ( Context * __context__, json::JsonValue const  * const  __a_rename_at_49_38, int32_t __idx_rename_at_49_39 )
{
    return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_49_38 != nullptr) && das_get_variant_field<TArray<json::JsonValue *>,8,1>::is(__a_rename_at_49_38->value)) ? das_auto_cast<json::JsonValue * const >::cast(das_null_coalescing<json::JsonValue *>::get(TArray<json::JsonValue *>::safe_index(&(das_get_variant_field<TArray<json::JsonValue *>,8,1>::as(__a_rename_at_49_38->value,__context__)),__idx_rename_at_49_39,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877))))) : das_auto_cast<json::JsonValue * const >::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877)))));
}

inline json::JsonValue * _FuncQmarkSqblSqbr_971e7ca2cc1e757a ( Context * __context__, json::JsonValue * __a_rename_at_54_40, int32_t __idx_rename_at_54_41 )
{
    return das_auto_cast<json::JsonValue *>::cast(((__a_rename_at_54_40 != nullptr) && das_get_variant_field<TArray<json::JsonValue *>,8,1>::is(__a_rename_at_54_40->value)) ? das_auto_cast<json::JsonValue *>::cast(das_null_coalescing<json::JsonValue *>::get(TArray<json::JsonValue *>::safe_index(&(das_get_variant_field<TArray<json::JsonValue *>,8,1>::as(__a_rename_at_54_40->value,__context__)),__idx_rename_at_54_41,__context__),das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877))))) : das_auto_cast<json::JsonValue *>::cast(das_invoke_function<json::JsonValue *>::invoke(__context__,nullptr,Func(__context__->fnByMangledName(/*@json::JVNull*/ 0xf1223cf59835e877)))));
}

inline double _FuncQmarkQmark_863d72a25223154e ( Context * __context__, json::JsonValue const  * const  __a_rename_at_85_42, double __val_rename_at_85_43 )
{
    return das_auto_cast<double>::cast(_Funcjson_boostTicknull_coalescingTick1995797521634879908_7f1128b71d01d238(__context__,__a_rename_at_85_42,__val_rename_at_85_43));
}

inline float _FuncQmarkQmark_2ab1d2f8767b75bc ( Context * __context__, json::JsonValue const  * const  __a_rename_at_90_44, float __val_rename_at_90_45 )
{
    return das_auto_cast<float>::cast(_Funcjson_boostTicknull_coalescingTick1995797521634879908_9fccb39a77658963(__context__,__a_rename_at_90_44,__val_rename_at_90_45));
}

inline int8_t _FuncQmarkQmark_388cb6d6e2bf8651 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_95_46, int8_t __val_rename_at_95_47 )
{
    return das_auto_cast<int8_t>::cast(_Funcjson_boostTicknull_coalescingTick1995797521634879908_c86cf3c97f89733b(__context__,__a_rename_at_95_46,__val_rename_at_95_47));
}

inline int16_t _FuncQmarkQmark_9e43bb6636ca112 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_100_48, int16_t __val_rename_at_100_49 )
{
    return das_auto_cast<int16_t>::cast(_Funcjson_boostTicknull_coalescingTick1995797521634879908_2e868b17eacf5d5a(__context__,__a_rename_at_100_48,__val_rename_at_100_49));
}

inline int32_t _FuncQmarkQmark_295897248e5215b1 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_105_50, int32_t __val_rename_at_105_51 )
{
    return das_auto_cast<int32_t>::cast(_Funcjson_boostTicknull_coalescingTick1995797521634879908_2f7db68220ccd39e(__context__,__a_rename_at_105_50,__val_rename_at_105_51));
}

inline int64_t _FuncQmarkQmark_94ec862d0c868973 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_110_52, int64_t __val_rename_at_110_53 )
{
    return das_auto_cast<int64_t>::cast(_Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_3f851a94af2dbd6a(__context__,__a_rename_at_110_52,__val_rename_at_110_53));
}

inline uint8_t _FuncQmarkQmark_35cb4622a32fe51d ( Context * __context__, json::JsonValue const  * const  __a_rename_at_115_54, uint8_t __val_rename_at_115_55 )
{
    return das_auto_cast<uint8_t>::cast(_Funcjson_boostTicknull_coalescingTick1995797521634879908_3ae4793671dea8da(__context__,__a_rename_at_115_54,__val_rename_at_115_55));
}

inline uint16_t _FuncQmarkQmark_5eeed4691e151b6a ( Context * __context__, json::JsonValue const  * const  __a_rename_at_120_56, uint16_t __val_rename_at_120_57 )
{
    return das_auto_cast<uint16_t>::cast(_Funcjson_boostTicknull_coalescingTick1995797521634879908_7acdfbfbcb894985(__context__,__a_rename_at_120_56,__val_rename_at_120_57));
}

inline uint32_t _FuncQmarkQmark_8e0b9f136322488d ( Context * __context__, json::JsonValue const  * const  __a_rename_at_125_58, uint32_t __val_rename_at_125_59 )
{
    return das_auto_cast<uint32_t>::cast(_Funcjson_boostTicknull_coalescingTick1995797521634879908_cabd6fed616201a8(__context__,__a_rename_at_125_58,__val_rename_at_125_59));
}

inline uint64_t _FuncQmarkQmark_aa829e0f9027a2ff ( Context * __context__, json::JsonValue const  * const  __a_rename_at_130_60, uint64_t __val_rename_at_130_61 )
{
    return das_auto_cast<uint64_t>::cast(_Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_ab1b0bd4ac0339d8(__context__,__a_rename_at_130_60,__val_rename_at_130_61));
}

inline bool _FuncQmarkQmark_ca96bf9fe6529e62 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_135_62, bool __val_rename_at_135_63 )
{
    return das_auto_cast<bool>::cast(((__a_rename_at_135_62 != nullptr) && das_get_variant_field<bool,8,5>::is(__a_rename_at_135_62->value)) ? das_auto_cast<bool>::cast(das_get_variant_field<bool,8,5>::as(__a_rename_at_135_62->value,__context__)) : das_auto_cast<bool>::cast(__val_rename_at_135_63));
}

inline char * _FuncQmarkQmark_844f4d981a373600 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_140_64, char * const  __val_rename_at_140_65 )
{
    return das_auto_cast<char *>::cast(((__a_rename_at_140_64 != nullptr) && das_get_variant_field<char *,8,2>::is(__a_rename_at_140_64->value)) ? das_auto_cast<char * const >::cast(das_get_variant_field<char *,8,2>::as(__a_rename_at_140_64->value,__context__)) : das_auto_cast<char * const >::cast(__val_rename_at_140_65));
}

inline TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,int64_t,bool,void *> const  * _FuncQmarkDotTickvalue_5189e68ec5a54919 ( Context * __context__, json::JsonValue const  * const  __a_rename_at_145_66 )
{
    return das_auto_cast<TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,int64_t,bool,void *> const  *>::cast(das_safe_navigation<json::JsonValue const ,TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,int64_t,bool,void *>,&json::JsonValue::value>::get(__a_rename_at_145_66));
}

inline TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,int64_t,bool,void *> * _FuncQmarkDotTickvalue_9c3125530216994c ( Context * __context__, json::JsonValue * __a_rename_at_150_67 )
{
    return das_auto_cast<TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,int64_t,bool,void *> *>::cast(das_safe_navigation<json::JsonValue,TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,int64_t,bool,void *>,&json::JsonValue::value>::get(__a_rename_at_150_67));
}

inline json_boost::JsonFieldState parse_json_annotation_1a187f6166ca89d1 ( Context * __context__, char * const  __name_rename_at_433_68, TArray<TTuple<48,char *,TVariant<32,16,bool,int32_t,uint32_t,int64_t,uint64_t,float,double,char *,vec4f>>> const  &  __annotation_rename_at_433_69 )
{
    json_boost::JsonFieldState __fieldState_rename_at_435_70;das_zero(__fieldState_rename_at_435_70);
    das_copy(__fieldState_rename_at_435_70.argName,__name_rename_at_433_68);
    {
        bool __need_loop_437 = true;
        // ann: tuple<name:string;data:variant<tBool:bool;tInt:int;tUInt:uint;tInt64:int64;tUInt64:uint64;tFloat:float;tDouble:double;tString:string;nothing:any> aka RttiValue> const&
        das_iterator<TArray<TTuple<48,char *,TVariant<32,16,bool,int32_t,uint32_t,int64_t,uint64_t,float,double,char *,vec4f>>> const > __ann_iterator(__annotation_rename_at_433_69);
        TTuple<48,char *,TVariant<32,16,bool,int32_t,uint32_t,int64_t,uint64_t,float,double,char *,vec4f>> const  * __ann_rename_at_437_71;
        __need_loop_437 = __ann_iterator.first(__context__,(__ann_rename_at_437_71)) && __need_loop_437;
        for ( ; __need_loop_437 ; __need_loop_437 = __ann_iterator.next(__context__,(__ann_rename_at_437_71)) )
        {
            if ( SimPolicy<char *>::Equ(cast<char *>::from(das_get_tuple_field<char *,0>::get((*__ann_rename_at_437_71))),cast<char *>::from(((char *) "rename")),*__context__,nullptr) )
            {
                das_copy(__fieldState_rename_at_435_70.argName,das_get_variant_field<char *,16,7>::as(das_get_tuple_field<TVariant<32,16,bool,int32_t,uint32_t,int64_t,uint64_t,float,double,char *,vec4f>,16>::get((*__ann_rename_at_437_71)),__context__));
            } else if ( (SimPolicy<char *>::Equ(cast<char *>::from(das_get_tuple_field<char *,0>::get((*__ann_rename_at_437_71))),cast<char *>::from(((char *) "enum_as_int")),*__context__,nullptr)) && false )
            {
                das_copy(__fieldState_rename_at_435_70.enumAsInt,das_get_variant_field<bool,16,0>::as(das_get_tuple_field<TVariant<32,16,bool,int32_t,uint32_t,int64_t,uint64_t,float,double,char *,vec4f>,16>::get((*__ann_rename_at_437_71)),__context__));
            } else if ( (SimPolicy<char *>::Equ(cast<char *>::from(das_get_tuple_field<char *,0>::get((*__ann_rename_at_437_71))),cast<char *>::from(((char *) "unescape")),*__context__,nullptr)) && false )
            {
                das_copy(__fieldState_rename_at_435_70.unescape,das_get_variant_field<bool,16,0>::as(das_get_tuple_field<TVariant<32,16,bool,int32_t,uint32_t,int64_t,uint64_t,float,double,char *,vec4f>,16>::get((*__ann_rename_at_437_71)),__context__));
            } else if ( (SimPolicy<char *>::Equ(cast<char *>::from(das_get_tuple_field<char *,0>::get((*__ann_rename_at_437_71))),cast<char *>::from(((char *) "embed")),*__context__,nullptr)) && false )
            {
                das_copy(__fieldState_rename_at_435_70.embed,das_get_variant_field<bool,16,0>::as(das_get_tuple_field<TVariant<32,16,bool,int32_t,uint32_t,int64_t,uint64_t,float,double,char *,vec4f>,16>::get((*__ann_rename_at_437_71)),__context__));
            } else if ( (SimPolicy<char *>::Equ(cast<char *>::from(das_get_tuple_field<char *,0>::get((*__ann_rename_at_437_71))),cast<char *>::from(((char *) "optional")),*__context__,nullptr)) && false )
            {
                das_copy(__fieldState_rename_at_435_70.optional,das_get_variant_field<bool,16,0>::as(das_get_tuple_field<TVariant<32,16,bool,int32_t,uint32_t,int64_t,uint64_t,float,double,char *,vec4f>,16>::get((*__ann_rename_at_437_71)),__context__));
            };
        }
        __ann_iterator.close(__context__,(__ann_rename_at_437_71));
    };
    return /* <- */ das_auto_cast_move<json_boost::JsonFieldState>::cast(__fieldState_rename_at_435_70);
}
static vec4f __wrap__FuncbuiltinTickpushTick10769833213962245646_6c6993f52ef9a438 ( Context * __context__ ) {
    TArray<ast::AstVariantMacro *> &  arg_Arr = cast_aot_arg<TArray<ast::AstVariantMacro *> & >::to(*__context__,__context__->abiArguments()[0]);
    ast::AstVariantMacro * arg_value = cast_aot_arg<ast::AstVariantMacro *>::to(*__context__,__context__->abiArguments()[1]);
    _FuncbuiltinTickpushTick10769833213962245646_6c6993f52ef9a438(__context__, arg_Arr, arg_value);
    return v_zero();
}
static vec4f __wrap__FuncrttiTickclass_infoTick15801393167907430156_43d1c02f15d88b09 ( Context * __context__ ) {
    json_boost::BetterJsonMacro const  &  arg_cl = cast_aot_arg<json_boost::BetterJsonMacro const  & >::to(*__context__,__context__->abiArguments()[0]);
    return cast<StructInfo const  *>::from(_FuncrttiTickclass_infoTick15801393167907430156_43d1c02f15d88b09(__context__, arg_cl));
}
static vec4f __wrap__FuncbuiltinTickpushTick10769833213962245646_7f48da5eed240807 ( Context * __context__ ) {
    TArray<ast::AstReaderMacro *> &  arg_Arr = cast_aot_arg<TArray<ast::AstReaderMacro *> & >::to(*__context__,__context__->abiArguments()[0]);
    ast::AstReaderMacro * arg_value = cast_aot_arg<ast::AstReaderMacro *>::to(*__context__,__context__->abiArguments()[1]);
    _FuncbuiltinTickpushTick10769833213962245646_7f48da5eed240807(__context__, arg_Arr, arg_value);
    return v_zero();
}
static vec4f __wrap__FuncrttiTickclass_infoTick15801393167907430156_180ff594216ab82f ( Context * __context__ ) {
    json_boost::JsonReader const  &  arg_cl = cast_aot_arg<json_boost::JsonReader const  & >::to(*__context__,__context__->abiArguments()[0]);
    return cast<StructInfo const  *>::from(_FuncrttiTickclass_infoTick15801393167907430156_180ff594216ab82f(__context__, arg_cl));
}
static vec4f __wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_7f1128b71d01d238 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    double arg_val = cast_aot_arg<double>::to(*__context__,__context__->abiArguments()[1]);
    return cast<double>::from(_Funcjson_boostTicknull_coalescingTick1995797521634879908_7f1128b71d01d238(__context__, arg_a, arg_val));
}
static vec4f __wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_9fccb39a77658963 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    float arg_val = cast_aot_arg<float>::to(*__context__,__context__->abiArguments()[1]);
    return cast<float>::from(_Funcjson_boostTicknull_coalescingTick1995797521634879908_9fccb39a77658963(__context__, arg_a, arg_val));
}
static vec4f __wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_c86cf3c97f89733b ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    int8_t arg_val = cast_aot_arg<int8_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<int8_t>::from(_Funcjson_boostTicknull_coalescingTick1995797521634879908_c86cf3c97f89733b(__context__, arg_a, arg_val));
}
static vec4f __wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_2e868b17eacf5d5a ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    int16_t arg_val = cast_aot_arg<int16_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<int16_t>::from(_Funcjson_boostTicknull_coalescingTick1995797521634879908_2e868b17eacf5d5a(__context__, arg_a, arg_val));
}
static vec4f __wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_2f7db68220ccd39e ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    int32_t arg_val = cast_aot_arg<int32_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<int32_t>::from(_Funcjson_boostTicknull_coalescingTick1995797521634879908_2f7db68220ccd39e(__context__, arg_a, arg_val));
}
static vec4f __wrap__Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_3f851a94af2dbd6a ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    int64_t arg_val = cast_aot_arg<int64_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<int64_t>::from(_Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_3f851a94af2dbd6a(__context__, arg_a, arg_val));
}
static vec4f __wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_3ae4793671dea8da ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    uint8_t arg_val = cast_aot_arg<uint8_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<uint8_t>::from(_Funcjson_boostTicknull_coalescingTick1995797521634879908_3ae4793671dea8da(__context__, arg_a, arg_val));
}
static vec4f __wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_7acdfbfbcb894985 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    uint16_t arg_val = cast_aot_arg<uint16_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<uint16_t>::from(_Funcjson_boostTicknull_coalescingTick1995797521634879908_7acdfbfbcb894985(__context__, arg_a, arg_val));
}
static vec4f __wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_cabd6fed616201a8 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    uint32_t arg_val = cast_aot_arg<uint32_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<uint32_t>::from(_Funcjson_boostTicknull_coalescingTick1995797521634879908_cabd6fed616201a8(__context__, arg_a, arg_val));
}
static vec4f __wrap__Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_ab1b0bd4ac0339d8 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    uint64_t arg_val = cast_aot_arg<uint64_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<uint64_t>::from(_Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_ab1b0bd4ac0339d8(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkSqblSqbr_850c72a61124f7d9 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    char * const  arg_key = cast_aot_arg<char * const >::to(*__context__,__context__->abiArguments()[1]);
    return cast<json::JsonValue *>::from(_FuncQmarkSqblSqbr_850c72a61124f7d9(__context__, arg_a, arg_key));
}
static vec4f __wrap__FuncQmarkSqblSqbr_10228bca30c0e9e ( Context * __context__ ) {
    json::JsonValue * arg_a = cast_aot_arg<json::JsonValue *>::to(*__context__,__context__->abiArguments()[0]);
    char * const  arg_key = cast_aot_arg<char * const >::to(*__context__,__context__->abiArguments()[1]);
    return cast<json::JsonValue *>::from(_FuncQmarkSqblSqbr_10228bca30c0e9e(__context__, arg_a, arg_key));
}
static vec4f __wrap__FuncQmarkDot_850c72a61124f7d9 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    char * const  arg_key = cast_aot_arg<char * const >::to(*__context__,__context__->abiArguments()[1]);
    return cast<json::JsonValue *>::from(_FuncQmarkDot_850c72a61124f7d9(__context__, arg_a, arg_key));
}
static vec4f __wrap__FuncQmarkDot_10228bca30c0e9e ( Context * __context__ ) {
    json::JsonValue * arg_a = cast_aot_arg<json::JsonValue *>::to(*__context__,__context__->abiArguments()[0]);
    char * const  arg_key = cast_aot_arg<char * const >::to(*__context__,__context__->abiArguments()[1]);
    return cast<json::JsonValue *>::from(_FuncQmarkDot_10228bca30c0e9e(__context__, arg_a, arg_key));
}
static vec4f __wrap__FuncQmarkSqblSqbr_ec96f834d9e351cd ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    int32_t arg_idx = cast_aot_arg<int32_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<json::JsonValue *>::from(_FuncQmarkSqblSqbr_ec96f834d9e351cd(__context__, arg_a, arg_idx));
}
static vec4f __wrap__FuncQmarkSqblSqbr_971e7ca2cc1e757a ( Context * __context__ ) {
    json::JsonValue * arg_a = cast_aot_arg<json::JsonValue *>::to(*__context__,__context__->abiArguments()[0]);
    int32_t arg_idx = cast_aot_arg<int32_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<json::JsonValue *>::from(_FuncQmarkSqblSqbr_971e7ca2cc1e757a(__context__, arg_a, arg_idx));
}
static vec4f __wrap__FuncQmarkQmark_863d72a25223154e ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    double arg_val = cast_aot_arg<double>::to(*__context__,__context__->abiArguments()[1]);
    return cast<double>::from(_FuncQmarkQmark_863d72a25223154e(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkQmark_2ab1d2f8767b75bc ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    float arg_val = cast_aot_arg<float>::to(*__context__,__context__->abiArguments()[1]);
    return cast<float>::from(_FuncQmarkQmark_2ab1d2f8767b75bc(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkQmark_388cb6d6e2bf8651 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    int8_t arg_val = cast_aot_arg<int8_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<int8_t>::from(_FuncQmarkQmark_388cb6d6e2bf8651(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkQmark_9e43bb6636ca112 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    int16_t arg_val = cast_aot_arg<int16_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<int16_t>::from(_FuncQmarkQmark_9e43bb6636ca112(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkQmark_295897248e5215b1 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    int32_t arg_val = cast_aot_arg<int32_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<int32_t>::from(_FuncQmarkQmark_295897248e5215b1(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkQmark_94ec862d0c868973 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    int64_t arg_val = cast_aot_arg<int64_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<int64_t>::from(_FuncQmarkQmark_94ec862d0c868973(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkQmark_35cb4622a32fe51d ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    uint8_t arg_val = cast_aot_arg<uint8_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<uint8_t>::from(_FuncQmarkQmark_35cb4622a32fe51d(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkQmark_5eeed4691e151b6a ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    uint16_t arg_val = cast_aot_arg<uint16_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<uint16_t>::from(_FuncQmarkQmark_5eeed4691e151b6a(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkQmark_8e0b9f136322488d ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    uint32_t arg_val = cast_aot_arg<uint32_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<uint32_t>::from(_FuncQmarkQmark_8e0b9f136322488d(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkQmark_aa829e0f9027a2ff ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    uint64_t arg_val = cast_aot_arg<uint64_t>::to(*__context__,__context__->abiArguments()[1]);
    return cast<uint64_t>::from(_FuncQmarkQmark_aa829e0f9027a2ff(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkQmark_ca96bf9fe6529e62 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    bool arg_val = cast_aot_arg<bool>::to(*__context__,__context__->abiArguments()[1]);
    return cast<bool>::from(_FuncQmarkQmark_ca96bf9fe6529e62(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkQmark_844f4d981a373600 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    char * const  arg_val = cast_aot_arg<char * const >::to(*__context__,__context__->abiArguments()[1]);
    return cast<char *>::from(_FuncQmarkQmark_844f4d981a373600(__context__, arg_a, arg_val));
}
static vec4f __wrap__FuncQmarkDotTickvalue_5189e68ec5a54919 ( Context * __context__ ) {
    json::JsonValue const  * const  arg_a = cast_aot_arg<json::JsonValue const  * const >::to(*__context__,__context__->abiArguments()[0]);
    return cast<TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,int64_t,bool,void *> const  *>::from(_FuncQmarkDotTickvalue_5189e68ec5a54919(__context__, arg_a));
}
static vec4f __wrap__FuncQmarkDotTickvalue_9c3125530216994c ( Context * __context__ ) {
    json::JsonValue * arg_a = cast_aot_arg<json::JsonValue *>::to(*__context__,__context__->abiArguments()[0]);
    return cast<TVariant<56,8,TTable<char *,json::JsonValue *>,TArray<json::JsonValue *>,char *,double,int64_t,bool,void *> *>::from(_FuncQmarkDotTickvalue_9c3125530216994c(__context__, arg_a));
}
static vec4f __wrap_parse_json_annotation_1a187f6166ca89d1 ( Context * __context__ ) {
    char * const  arg_name = cast_aot_arg<char * const >::to(*__context__,__context__->abiArguments()[0]);
    TArray<TTuple<48,char *,TVariant<32,16,bool,int32_t,uint32_t,int64_t,uint64_t,float,double,char *,vec4f>>> const  &  arg_annotation = cast_aot_arg<TArray<TTuple<48,char *,TVariant<32,16,bool,int32_t,uint32_t,int64_t,uint64_t,float,double,char *,vec4f>>> const  & >::to(*__context__,__context__->abiArguments()[1]);
    *((json_boost::JsonFieldState *) __context__->abiCMRES) = parse_json_annotation_1a187f6166ca89d1(__context__, arg_name, arg_annotation);
    return v_zero();
}

#pragma optimize("", off)
struct AotFunction { uint64_t hash; bool is_cmres; void * fn; vec4f (*wrappedFn)(Context*); };
static AotFunction functions[] = {
    { 0x1e90329a55e70411, false, (void*)&_FuncbuiltinTickpushTick10769833213962245646_6c6993f52ef9a438, &__wrap__FuncbuiltinTickpushTick10769833213962245646_6c6993f52ef9a438 },
    { 0x420537fd9e91a9e, false, (void*)&_FuncrttiTickclass_infoTick15801393167907430156_43d1c02f15d88b09, &__wrap__FuncrttiTickclass_infoTick15801393167907430156_43d1c02f15d88b09 },
    { 0xb1b7b60123001d90, false, (void*)&_FuncbuiltinTickpushTick10769833213962245646_7f48da5eed240807, &__wrap__FuncbuiltinTickpushTick10769833213962245646_7f48da5eed240807 },
    { 0x35b82a2fb7056792, false, (void*)&_FuncrttiTickclass_infoTick15801393167907430156_180ff594216ab82f, &__wrap__FuncrttiTickclass_infoTick15801393167907430156_180ff594216ab82f },
    { 0x6da2910608090416, false, (void*)&_Funcjson_boostTicknull_coalescingTick1995797521634879908_7f1128b71d01d238, &__wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_7f1128b71d01d238 },
    { 0xcf9db2bdd5140896, false, (void*)&_Funcjson_boostTicknull_coalescingTick1995797521634879908_9fccb39a77658963, &__wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_9fccb39a77658963 },
    { 0x137cc6aa91e46b16, false, (void*)&_Funcjson_boostTicknull_coalescingTick1995797521634879908_c86cf3c97f89733b, &__wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_c86cf3c97f89733b },
    { 0xe461a082b7d2d65, false, (void*)&_Funcjson_boostTicknull_coalescingTick1995797521634879908_2e868b17eacf5d5a, &__wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_2e868b17eacf5d5a },
    { 0x433099b46f716b3b, false, (void*)&_Funcjson_boostTicknull_coalescingTick1995797521634879908_2f7db68220ccd39e, &__wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_2f7db68220ccd39e },
    { 0x55d2ec298e67acad, false, (void*)&_Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_3f851a94af2dbd6a, &__wrap__Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_3f851a94af2dbd6a },
    { 0x17f2b62a89f70a55, false, (void*)&_Funcjson_boostTicknull_coalescingTick1995797521634879908_3ae4793671dea8da, &__wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_3ae4793671dea8da },
    { 0xb67a3800064ffef5, false, (void*)&_Funcjson_boostTicknull_coalescingTick1995797521634879908_7acdfbfbcb894985, &__wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_7acdfbfbcb894985 },
    { 0x4a81289eab6c7cea, false, (void*)&_Funcjson_boostTicknull_coalescingTick1995797521634879908_cabd6fed616201a8, &__wrap__Funcjson_boostTicknull_coalescingTick1995797521634879908_cabd6fed616201a8 },
    { 0x72d5b7bd042dea6a, false, (void*)&_Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_ab1b0bd4ac0339d8, &__wrap__Funcjson_boostTicknull_coalescing_with_stringTick3281489010087647503_ab1b0bd4ac0339d8 },
    { 0x448b36129f9c4cdf, false, (void*)&_FuncQmarkSqblSqbr_850c72a61124f7d9, &__wrap__FuncQmarkSqblSqbr_850c72a61124f7d9 },
    { 0xb7fab6d9d4421099, false, (void*)&_FuncQmarkSqblSqbr_10228bca30c0e9e, &__wrap__FuncQmarkSqblSqbr_10228bca30c0e9e },
    { 0x448b36129f9c4cdf, false, (void*)&_FuncQmarkDot_850c72a61124f7d9, &__wrap__FuncQmarkDot_850c72a61124f7d9 },
    { 0xb7fab6d9d4421099, false, (void*)&_FuncQmarkDot_10228bca30c0e9e, &__wrap__FuncQmarkDot_10228bca30c0e9e },
    { 0x4e81b989d39adf82, false, (void*)&_FuncQmarkSqblSqbr_ec96f834d9e351cd, &__wrap__FuncQmarkSqblSqbr_ec96f834d9e351cd },
    { 0x56c5a4867e8a93df, false, (void*)&_FuncQmarkSqblSqbr_971e7ca2cc1e757a, &__wrap__FuncQmarkSqblSqbr_971e7ca2cc1e757a },
    { 0xdcb56f21869addac, false, (void*)&_FuncQmarkQmark_863d72a25223154e, &__wrap__FuncQmarkQmark_863d72a25223154e },
    { 0xe50cdfa92cde37c8, false, (void*)&_FuncQmarkQmark_2ab1d2f8767b75bc, &__wrap__FuncQmarkQmark_2ab1d2f8767b75bc },
    { 0x8cfdac7edc3b7e89, false, (void*)&_FuncQmarkQmark_388cb6d6e2bf8651, &__wrap__FuncQmarkQmark_388cb6d6e2bf8651 },
    { 0x6e8829399ba8f8e5, false, (void*)&_FuncQmarkQmark_9e43bb6636ca112, &__wrap__FuncQmarkQmark_9e43bb6636ca112 },
    { 0x89028e6445b04a7c, false, (void*)&_FuncQmarkQmark_295897248e5215b1, &__wrap__FuncQmarkQmark_295897248e5215b1 },
    { 0x7af57baf9dffcfbc, false, (void*)&_FuncQmarkQmark_94ec862d0c868973, &__wrap__FuncQmarkQmark_94ec862d0c868973 },
    { 0x792573c07f45180f, false, (void*)&_FuncQmarkQmark_35cb4622a32fe51d, &__wrap__FuncQmarkQmark_35cb4622a32fe51d },
    { 0x5d2828b3a48cd85d, false, (void*)&_FuncQmarkQmark_5eeed4691e151b6a, &__wrap__FuncQmarkQmark_5eeed4691e151b6a },
    { 0xb50255773bbf9842, false, (void*)&_FuncQmarkQmark_8e0b9f136322488d, &__wrap__FuncQmarkQmark_8e0b9f136322488d },
    { 0xbcc059caa0d1c5d1, false, (void*)&_FuncQmarkQmark_aa829e0f9027a2ff, &__wrap__FuncQmarkQmark_aa829e0f9027a2ff },
    { 0x73ca13f7c9a99421, false, (void*)&_FuncQmarkQmark_ca96bf9fe6529e62, &__wrap__FuncQmarkQmark_ca96bf9fe6529e62 },
    { 0xcf608b94af2f94c, false, (void*)&_FuncQmarkQmark_844f4d981a373600, &__wrap__FuncQmarkQmark_844f4d981a373600 },
    { 0xc33c470a5a27fd54, false, (void*)&_FuncQmarkDotTickvalue_5189e68ec5a54919, &__wrap__FuncQmarkDotTickvalue_5189e68ec5a54919 },
    { 0x899e617ee4a7f78f, false, (void*)&_FuncQmarkDotTickvalue_9c3125530216994c, &__wrap__FuncQmarkDotTickvalue_9c3125530216994c },
    { 0x88145853f58d687f, true, (void*)&parse_json_annotation_1a187f6166ca89d1, &__wrap_parse_json_annotation_1a187f6166ca89d1 },
};
#pragma optimize("", on)

static void registerAotFunctions ( AotLibrary & aotLib ) {
    for (const auto &[hash, cmres, fn1, fn2] : functions) {
        aotLib.emplace(hash, AotFactory(cmres, fn1, fn2));
    }
    resolveTypeInfoAnnotations();
}

} // namespace _anon_14538537767599647147
AotListBase impl_aot_json_boost(_anon_14538537767599647147::registerAotFunctions);
} // namespace das

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
#if defined(__EDG__)
#pragma diag_default 826
#elif defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
