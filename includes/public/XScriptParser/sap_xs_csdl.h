// Generated by SAP AFX Compiler (Tue Mar 10 11:04:40 CET 2015)

#ifndef SAP_XS_CSDL_H
#define SAP_XS_CSDL_H

#include "sap_xs_runtime.h"

@class XS_CsdlException;
@class XS_CsdlDocument;
@class XS_CsdlFetcher;
@class XS_CsdlParser;
@class XS_CsdlNavigationV3;
@class XS_CsdlAssociationV3;

@interface XS_CsdlException : NSException
{
    @protected NSException* cause_;
    @protected NSString* message_;
}
/* public */ @property (readonly, strong) NSException* cause;
/* public */ @property (readonly, strong) NSString* message;
/* private */ - (id) init;
/* public */ - (NSException*) cause;
/* public */ - (NSString*) message;
+ (XS_CsdlException*) new;
/* private */ - (void) privateInit;
/* public */ + (XS_CsdlException*) withCause :(NSException*)param_cause;
/* public */ + (XS_CsdlException*) withMessage :(NSString*)param_message;
/* public */ + (XS_CsdlException*) withCauseAndMessage :(NSException*)param_cause :(NSString*)param_message;
/* private */ + (XS_CsdlException*) DC1 :(NSException*)p1;
/* private */ + (XS_CsdlException*) DC3 :(NSException*)p1 :(NSString*)p2;
/* private */ + (XS_CsdlException*) DC2 :(NSString*)p1;
@end

@interface XS_CsdlDocument : NSObject
{
    @private NSString* versionText_;
    @private xs_int versionCode_;
    @protected XS_DataSchemaMap* dataSchemas_;
    @protected XS_DataMethodMap* dataMethods_;
    @protected XS_DataTypeMap* builtinTypes_;
    @protected XS_SimpleTypeMap* simpleTypes_;
    @protected XS_ComplexTypeMap* complexTypes_;
    @protected XS_EntityTypeMap* entityTypes_;
    @protected XS_EntitySetMap* entitySets_;
    @protected XS_AnnotationTermMap* annotationTerms_;
    @protected XS_EntityContainerMap* entityContainers_;
    @protected XS_StringMap* xmlNamespaces_;
    @protected XS_EntitySetMap* lookupSets_;
}
/* public */ @property (strong) NSString* versionText;
/* public */ @property xs_int versionCode;
/* public */ @property (readonly, strong) XS_DataSchemaMap* dataSchemas;
/* public */ @property (readonly, strong) XS_DataMethodMap* dataMethods;
/* public */ @property (readonly, strong) XS_DataTypeMap* builtinTypes;
/* public */ @property (readonly, strong) XS_SimpleTypeMap* simpleTypes;
/* public */ @property (readonly, strong) XS_ComplexTypeMap* complexTypes;
/* public */ @property (readonly, strong) XS_EntityTypeMap* entityTypes;
/* public */ @property (readonly, strong) XS_EntitySetMap* entitySets;
/* public */ @property (readonly, strong) XS_AnnotationTermMap* annotationTerms;
/* public */ @property (readonly, strong) XS_EntityContainerMap* entityContainers;
/* public */ @property (readonly, strong) XS_StringMap* xmlNamespaces;
/* public */ @property (readonly, strong) XS_EntitySetMap* lookupSets;
/* private */ - (id) init;
/* public */ + (XS_CsdlDocument*) new;
/* public */ - (NSString*) versionText;
/* public */ - (void) setVersionText :(NSString*)value;
/* public */ - (xs_int) versionCode;
/* public */ - (void) setVersionCode :(xs_int)value;
/* public */ - (XS_DataSchemaMap*) dataSchemas;
/* public */ - (XS_DataMethodMap*) dataMethods;
/* public */ - (XS_DataTypeMap*) builtinTypes;
/* public */ - (XS_SimpleTypeMap*) simpleTypes;
/* public */ - (XS_ComplexTypeMap*) complexTypes;
/* public */ - (XS_EntityTypeMap*) entityTypes;
/* public */ - (XS_EntitySetMap*) entitySets;
/* public */ - (XS_AnnotationTermMap*) annotationTerms;
/* public */ - (XS_EntityContainerMap*) entityContainers;
/* public */ - (XS_StringMap*) xmlNamespaces;
/* public */ - (XS_EntitySetMap*) lookupSets;
/* public */ - (XS_DataSchema*) getDataSchema :(NSString*)name;
/* public */ - (XS_DataMethod*) getDataMethod :(NSString*)name;
/* public */ - (XS_DataType*) getSimpleType :(NSString*)name;
/* public */ - (XS_ComplexType*) getComplexType :(NSString*)name;
/* public */ - (XS_EntityType*) getEntityType :(NSString*)name;
/* public */ - (XS_EntitySet*) getEntitySet :(NSString*)name;
@end

@interface XS_CsdlFetcher : NSObject
/* public */ + (XS_CsdlFetcher*) new;
/* public */ - (NSString*) fetch :(NSString*)url;
@end

@interface XS_CsdlParser : NSObject
{
    @private XS_XmlElement* rootElement;
    @private XS_CsdlDocument* document;
    @private xs_int phase;
    @private XS_DataSchema* schema;
    @private XS_StringMap* nsAliases;
    @private XS_DataTypeMap* primitives;
    @private XS_ComplexTypeMap* finalComplex;
    @private XS_EntityTypeMap* finalEntity;
    @private XS_EntityContainerMap* finalContainer;
    @private xs_boolean fixedPoint;
    @private XS_ObjectMap* v3Associations;
    @private XS_StringMap* alreadyLoaded;
    @private NSString* myURL;
    @private XS_CsdlFetcher* csdlFetcher_;
    @private xs_boolean retainXML_;
    @private NSString* retainedXML_;
}
/* public */ @property (strong) XS_CsdlFetcher* csdlFetcher;
/* public */ @property xs_boolean retainXML;
/* public */ @property (strong) NSString* retainedXML;
/* private */ - (id) init;
/* public */ + (XS_CsdlParser*) new;
/* public */ - (XS_CsdlFetcher*) csdlFetcher;
/* public */ - (void) setCsdlFetcher :(XS_CsdlFetcher*)value;
/* public */ - (xs_boolean) retainXML;
/* public */ - (void) setRetainXML :(xs_boolean)value;
/* public */ - (NSString*) retainedXML;
/* public */ - (void) setRetainedXML :(NSString*)value;
/* public */ - (XS_CsdlDocument*) parse :(NSString*)csdl :(NSString*)url;
/* private */ - (void) parseEdmx :(XS_XmlElement*)edmx;
/* private */ - (void) resolveReferences :(XS_XmlElement*)root :(NSString*)url;
/* private */ - (void) resolveReference :(XS_XmlElement*)element;
/* private */ - (void) parseReference :(XS_XmlElement*)element;
/* private */ - (void) parseInclude :(XS_XmlElement*)element;
/* private */ - (void) parseIncludeAnnotations :(XS_XmlElement*)element;
/* private */ - (void) processInPhases :(XS_XmlElement*)edmx;
/* private */ - (void) parseDataServices :(XS_XmlElement*)element;
/* private */ - (void) parseSchema :(XS_XmlElement*)element;
/* private */ - (void) parseSimpleType :(XS_SimpleType*)st :(XS_XmlElement*)element;
/* private */ - (void) parseEnumType :(XS_EnumType*)enumType :(XS_XmlElement*)element;
/* private */ - (void) parseComplexType :(XS_ComplexType*)ct :(XS_XmlElement*)element;
/* private */ - (void) parseEntityType :(XS_EntityType*)et :(XS_XmlElement*)element;
/* private */ - (void) parseEntityContainer :(XS_EntityContainer*)ec :(XS_XmlElement*)element;
/* private */ - (void) parseEntitySet :(XS_EntitySet*)es :(XS_XmlElement*)element;
/* private */ - (XS_TypeFacets*) parseFacets :(XS_XmlElement*)element :(NSString*)refKind :(NSString*)refName :(XS_DataType*)dt;
/* private */ - (XS_PropertyInfo*) parseProperty :(XS_XmlElement*)element :(NSString*)refKind :(NSString*)refName;
/* private */ - (XS_PropertyInfo*) parseNavigationProperty :(XS_XmlElement*)element :(NSString*)refKind :(NSString*)refName;
/* private */ - (XS_CsdlAssociationV3*) parseAssociationV3 :(XS_XmlElement*)element;
/* private */ - (void) parseAssociationSetV3 :(XS_XmlElement*)element;
/* private */ - (XS_DataMethod*) parseDataMethod :(XS_DataMethod*)dm :(XS_XmlElement*)element :(xs_boolean)isAction;
/* private */ - (void) copyDataMethods;
/* private */ - (XS_Parameter*) parseParameter :(XS_XmlElement*)element :(NSString*)refKind :(NSString*)refName;
/* private */ - (XS_AnnotationMap*) processAnnotations :(XS_AnnotationList*)list :(XS_AnnotationMap*)map :(XS_XmlElement*)element;
/* private */ - (void) parseAnnotations :(XS_XmlElement*)element;
/* private */ - (XS_Annotation*) parseAnnotation :(XS_XmlElement*)element;
/* private */ - (void) parseAnnotationTerm :(XS_AnnotationTerm*)term :(XS_XmlElement*)element;
/* private */ - (xs_boolean) isCustomAttribute :(XS_XmlAttribute*)attribute;
/* private */ - (XS_Annotation*) parseCustomAttribute :(XS_XmlAttribute*)attribute;
/* private */ - (XS_DataValue*) parseDefaultValue :(NSString*)refKind :(NSString*)refName :(XS_DataType*)type :(NSString*)value;
/* private */ - (XS_DataValue*) parseTermElement :(XS_XmlElement*)element :(XS_DataType*)type;
/* private */ - (XS_DataValue*) parseTermLiteral :(NSString*)name :(XS_DataType*)type :(NSString*)value;
/* private */ - (XS_PathValue*) parsePath :(NSString*)text;
/* private */ - (NSString*) getOptionalAttribute :(XS_XmlElement*)element :(NSString*)name;
/* private */ - (NSString*) getRequiredAttribute :(XS_XmlElement*)element :(NSString*)name;
/* private */ - (NSString*) getRequiredAttributeIn :(XS_XmlElement*)element :(NSString*)name :(NSString*)refKind :(NSString*)refName;
/* private */ - (XS_AnnotationList*) copyAnnotationList :(XS_AnnotationList*)list;
/* private */ - (XS_PropertyInfoList*) copyPropertyList :(XS_PropertyInfoList*)list;
/* private */ - (XS_PropertyInfoList*) getComplexProperties :(XS_PropertyInfoList*)list;
/* private */ - (XS_PropertyInfoList*) getStreamProperties :(XS_PropertyInfoList*)list;
/* private */ - (XS_DataTypeMap*) getPrimitiveTypes;
/* private */ - (void) addPrimitiveType :(XS_DataTypeMap*)map :(NSString*)name :(xs_int)code;
/* private */ - (void) addXmlNamespaces :(XS_XmlElement*)element;
/* private */ - (NSString*) resolveAlias :(NSString*)name;
/* private */ - (XS_AnnotationTerm*) resolveTerm :(NSString*)name :(NSString*)refKind :(NSString*)refName;
/* private */ - (XS_DataType*) resolveDataType :(NSString*)name :(NSString*)refKind :(NSString*)refName;
/* private */ - (XS_ComplexType*) resolveComplexType :(NSString*)name :(NSString*)refKind :(NSString*)refName;
/* private */ - (XS_EntityType*) resolveEntityType :(NSString*)name :(NSString*)refKind :(NSString*)refName;
/* private */ - (XS_EntitySet*) resolveEntitySet :(NSString*)name :(NSString*)refKind :(NSString*)refName;
/* private */ - (id) resolveTargetPath :(XS_PathValue*)target;
/* private */ - (NSString*) fetch :(NSString*)url;
/* private */ - (XS_CsdlException*) errorWithCause :(NSException*)cause;
/* private */ - (XS_CsdlException*) errorWithMessage :(NSString*)message;
/* private */ + (XS_Annotation*) DC16 :(NSString*)p1 :(XS_AnnotationTerm*)p2 :(XS_DataValue*)p3;
/* private */ + (XS_Annotation*) DC18 :(XS_AnnotationTerm*)p1 :(XS_DataValue*)p2;
/* private */ + (XS_AnnotationPath*) DC19 :(XS_PathValue*)p1;
/* private */ + (XS_AnnotationTerm*) DC24 :(XS_StringList*)p1 :(NSString*)p2 :(NSString*)p3 :(XS_DataType*)p4;
/* private */ + (XS_AnnotationTerm*) DC6 :(NSString*)p1 :(NSString*)p2;
/* private */ + (XS_AnnotationTerm*) DC17 :(NSString*)p1 :(NSString*)p2 :(XS_DataType*)p3;
/* private */ + (XS_ComplexType*) DC4 :(NSString*)p1 :(NSString*)p2;
/* private */ + (XS_CsdlAssociationV3*) DC14 :(NSString*)p1;
/* private */ + (XS_CsdlNavigationV3*) DC12 :(NSString*)p1 :(NSString*)p2 :(NSString*)p3 :(NSString*)p4 :(XS_DataType*)p5;
/* private */ + (XS_DataMethod*) DC10 :(NSString*)p1 :(xs_boolean)p2;
/* private */ + (XS_DataMethod*) DC7 :(NSString*)p1 :(NSString*)p2;
/* private */ + (XS_DataSchema*) DC1 :(NSString*)p1 :(NSString*)p2;
/* private */ + (XS_EntityContainer*) DC8 :(NSString*)p1 :(XS_DataSchema*)p2 :(NSString*)p3;
/* private */ + (XS_EntitySet*) DC9 :(NSString*)p1 :(NSString*)p2;
/* private */ + (XS_EntityType*) DC5 :(NSString*)p1 :(NSString*)p2;
/* private */ + (XS_EnumType*) DC3 :(NSString*)p1 :(NSString*)p2;
/* private */ + (XS_NavigationPropertyPath*) DC21 :(XS_PathValue*)p1;
/* private */ + (XS_Parameter*) DC15 :(xs_int)p1 :(NSString*)p2 :(XS_DataType*)p3 :(XS_TypeFacets*)p4;
/* private */ + (XS_PathValue*) DC23 :(XS_PathValue*)p1 :(NSString*)p2;
/* private */ + (XS_PathValue*) DC22 :(NSString*)p1;
/* private */ + (XS_PropertyInfo*) DC13 :(NSString*)p1 :(XS_DataType*)p2;
/* private */ + (XS_PropertyInfo*) DC11 :(NSString*)p1 :(XS_DataType*)p2 :(XS_TypeFacets*)p3;
/* private */ + (XS_SimpleType*) DC2 :(NSString*)p1 :(NSString*)p2;
/* private */ + (XS_StructuralPropertyPath*) DC20 :(XS_PathValue*)p1;
@end

#define XS_CsdlParser_ABSTRACT @"Abstract"
#define XS_CsdlParser_ACTION @"Action"
#define XS_CsdlParser_ACTION_IMPORT @"ActionImport"
#define XS_CsdlParser_ALIAS @"Alias"
#define XS_CsdlParser_ANNOTATION @"Annotation"
#define XS_CsdlParser_ANNOTATIONS @"Annotations"
#define XS_CsdlParser_ASSOCIATION @"Association"
#define XS_CsdlParser_ASSOCIATION_SET @"AssociationSet"
#define XS_CsdlParser_BASE_TYPE @"BaseType"
#define XS_CsdlParser_COMPLEX_TYPE @"ComplexType"
#define XS_CsdlParser_DATA_SERVICES @"DataServices"
#define XS_CsdlParser_END @"End"
#define XS_CsdlParser_ENTITY @"Entity"
#define XS_CsdlParser_ENTITY_CONTAINER @"EntityContainer"
#define XS_CsdlParser_ENTITY_SET @"EntitySet"
#define XS_CsdlParser_ENTITY_TYPE @"EntityType"
#define XS_CsdlParser_ENUM_TYPE @"EnumType"
#define XS_CsdlParser_ERROR_URL @"$URL"
#define XS_CsdlParser_EXTENDS @"Extends"
#define XS_CsdlParser_FROM_ROLE @"FromRole"
#define XS_CsdlParser_FUNCTION @"Function"
#define XS_CsdlParser_FUNCTION_IMPORT @"FunctionImport"
#define XS_CsdlParser_MEMBER @"Member"
#define XS_CsdlParser_MODE @"Mode"
#define XS_CsdlParser_MULTIPLICITY @"Multiplicity"
#define XS_CsdlParser_KEY @"Key"
#define XS_CsdlParser_NAME @"Name"
#define XS_CsdlParser_NAMESPACE @"Namespace"
#define XS_CsdlParser_NAVIGATION_PROPERTY @"NavigationProperty"
#define XS_CsdlParser_NAVIGATION_PROPERTY_BINDING @"NavigationPropertyBinding"
#define XS_CsdlParser_OPEN_TYPE @"OpenType"
#define XS_CsdlParser_PARAMETER @"Parameter"
#define XS_CsdlParser_PATH @"Path"
#define XS_CsdlParser_PROPERTY @"Property"
#define XS_CsdlParser_PROPERTY_REF @"PropertyRef"
#define XS_CsdlParser_PROPERTY_VALUE @"PropertyValue"
#define XS_CsdlParser_RECORD @"Record"
#define XS_CsdlParser_RELATIONSHIP @"Relationship"
#define XS_CsdlParser_REFERENCE @"Reference"
#define XS_CsdlParser_ROLE @"Role"
#define XS_CsdlParser_QUALIFIER @"Qualifier"
#define XS_CsdlParser_SCHEMA @"Schema"
#define XS_CsdlParser_TARGET @"Target"
#define XS_CsdlParser_TERM @"Term"
#define XS_CsdlParser_TO_ROLE @"ToRole"
#define XS_CsdlParser_TYPE @"Type"
#define XS_CsdlParser_TYPE_DEFINITION @"TypeDefinition"
#define XS_CsdlParser_UNDERLYING_TYPE @"UnderlyingType"
#define XS_CsdlParser_URL_REF @"UrlRef"
#define XS_CsdlParser_VALUE @"Value"
#define XS_CsdlParser_VERSION @"Version"
#define XS_CsdlParser_TEXT_TRUE @"true"
#define XS_CsdlParser_TEXT_FALSE @"false"
#define XS_CsdlParser_MINIMUM_PHASE 1
#define XS_CsdlParser_MAXIMUM_PHASE 12
#define XS_CsdlParser_DEFINE_SCHEMAS 1
#define XS_CsdlParser_DEFINE_ASSOCIATIONS 2
#define XS_CsdlParser_DEFINE_TERMS 3
#define XS_CsdlParser_DEFINE_TYPES 3
#define XS_CsdlParser_DEFINE_METHODS 3
#define XS_CsdlParser_PARSE_BASIC 4
#define XS_CsdlParser_PARSE_TERMS 5
#define XS_CsdlParser_PARSE_TYPES 6
#define XS_CsdlParser_PARSE_METHODS 6
#define XS_CsdlParser_DEFINE_CONTAINERS 7
#define XS_CsdlParser_PARSE_CONTAINERS 8
#define XS_CsdlParser_DEFINE_SETS 9
#define XS_CsdlParser_PARSE_SETS 10
#define XS_CsdlParser_PARSE_ASSOCIATIONS 11
#define XS_CsdlParser_IMPORT_METHODS 11
#define XS_CsdlParser_PARSE_ANNOTATIONS 12
#define XS_CsdlParser_URL_1 @"http://docs.oasis-open.org/odata/odata/v4.0/os/vocabularies/Org.OData.Capabilities.V1.xml"
#define XS_CsdlParser_URL_2 @"http://docs.oasis-open.org/odata/odata/v4.0/os/vocabularies/Org.OData.Core.V1.xml"
#define XS_CsdlParser_URL_3 @"http://docs.oasis-open.org/odata/odata/v4.0/os/vocabularies/Org.OData.Measures.V1.xml"
#define XS_CsdlParser_DOC_1 @"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<!--\nOData Version 4.0\nOASIS Standard\n24 February 2014\nCopyright (c) OASIS Open 2014. All Rights Reserved.\nSource: http://docs.oasis-open.org/odata/odata/v4.0/os/vocabularies/\n-->\n<edmx:Edmx xmlns:edmx=\"http://docs.oasis-open.org/odata/ns/edmx\" Version=\"4.0\">\n<edmx:Reference Uri=\"http://docs.oasis-open.org/odata/odata/v4.0/os/vocabularies/Org.OData.Core.V1.xml\">\n<edmx:Include Alias=\"Core\" Namespace=\"Org.OData.Core.V1\" />\n</edmx:Reference>\n<edmx:DataServices>\n<Schema xmlns=\"http://docs.oasis-open.org/odata/ns/edm\" Namespace=\"Org.OData.Capabilities.V1\" Alias=\"Capabilities\">\n<Annotation Term=\"Core.Description\">\n<String>\nThe Capabilities vocabulary aims to provide a way for service authors to describe\ncertain capabilities of an OData Service.\n</String>\n</Annotation>\n<Annotation Term=\"Core.LongDescription\">\n<String>\nThere are some capabilities which are strongly recommended for services to support even\nthough they are optional. Support for $top and $skip is a good example as\nsupporting these query options helps with performance of a service and are essential. Such\ncapabilities are assumed to be default capabilities of an OData service even in\nthe case that a capabilities annotation doesn’t exist. Capabilities annotations are\nmainly expected to be used to explicitly specify that a service doesn’t support such\ncapabilities. Capabilities annotations can as well be used to declaratively\nspecify the support of such capabilities.\n\nOn the other hand, there are some capabilities that a service may choose to support or\nnot support and in varying degrees. $filter and $orderby are such good examples.\nThis vocabulary aims to define terms to specify support or no support for such\ncapabilities.\n\nA service is assumed to support by default the following capabilities even though an\nannotation doesn’t exist:\n- Countability ($count, $inlinecount)\n- Client pageability ($top, $skip)\n- Expandability ($expand)\n- Indexability by key\n- Batch support ($batch)\n- Navigability of navigation properties\n\nA service is expected to support the following capabilities. If not supported, the\nservice is expected to call out the restrictions using annotations:\n- Filterability ($filter)\n- Sortability ($orderby)\n- Queryability of top level entity sets\n- Query functions\n\nA client cannot assume that a service supports certain capabilities. A client can try, but\nit needs to be prepared to handle an error in case the following capabilities are not\nsupported:\n- Insertability\n- Updatability\n- Deletability\n</String>\n</Annotation>\n\n<!-- Conformance Level -->\n\n<Term Name=\"ConformanceLevel\" Type=\"Capabilities.ConformanceLevelType\" AppliesTo=\"EntityContainer\" />\n<EnumType Name=\"ConformanceLevelType\">\n<Member Name=\"Minimal\" />\n<Member Name=\"Intermediate\" />\n<Member Name=\"Advanced\" />\n</EnumType>\n\n<!-- Request Capabilities -->\n\n<Term Name=\"SupportedFormats\" Type=\"Collection(Edm.String)\">\n<Annotation Term=\"Core.Description\" String=\"Media types of supported formats, including format parameters\" />\n<Annotation Term=\"Core.IsMediaType\" />\n</Term>\n\n<Term Name=\"AcceptableEncodings\" Type=\"Collection(Edm.String)\" AppliesTo=\"EntityContainer\">\n<Annotation Term=\"Core.Description\" String=\"List of acceptable compression methods for ($batch) requests, e.g. gzip\" />\n</Term>\n\n<!-- Supported Preferences -->\n\n<Term Name=\"AsynchronousRequestsSupported\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"EntityContainer\">\n<Annotation Term=\"Core.Description\" String=\"Service supports the asynchronous request preference\" />\n</Term>\n\n<Term Name=\"BatchContinueOnErrorSupported\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"EntityContainer\">\n<Annotation Term=\"Core.Description\" String=\"Service supports the continue on error preference\" />\n</Term>\n\n<Term Name=\"IsolationSupported\" Type=\"Capabilities.IsolationLevel\" AppliesTo=\"EntityContainer\">\n<Annotation Term=\"Core.Description\" String=\"Supported odata.isolation levels\" />\n</Term>\n<EnumType Name=\"IsolationLevel\" IsFlags=\"true\">\n<Member Name=\"Snapshot\" Value=\"1\" />\n</EnumType>\n\n<Term Name=\"CallbackSupported\" Type=\"Capabilities.CallbackType\" AppliesTo=\"EntityContainer EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Supports callbacks for the specified protocols\" />\n</Term>\n<Term Name=\"CrossJoinSupported\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"EntityContainer\">\n<Annotation Term=\"Core.Description\" String=\"Supports cross joins for the entity sets in this container\" />\n</Term>\n<ComplexType Name=\"CallbackType\">\n<Property Name=\"CallbackProtocols\" Type=\"Collection(Capabilities.CallbackProtocol)\" />\n<Annotation Term=\"Core.Description\"\nString=\"A non-empty collection lists the full set of supported protocols. A empty collection means 'only HTTP is supported'\" />\n</ComplexType>\n<ComplexType Name=\"CallbackProtocol\">\n<Property Name=\"Id\" Type=\"Edm.String\">\n<Annotation Term=\"Core.Description\" String=\"Protcol Identifier\" />\n</Property>\n<Property Name=\"UrlTemplate\" Type=\"Edm.String\">\n<Annotation Term=\"Core.Description\"\nString=\"URL Template including parameters. Parameters are enclosed in curly braces {} as defined in RFC6570\" />\n</Property>\n<Property Name=\"DocumentationUrl\" Type=\"Edm.String\" Nullable=\"true\">\n<Annotation Term=\"Core.Description\" String=\"Human readable description of the meaning of the URL Template parameters\" />\n<Annotation Term=\"Core.IsURL\" />\n</Property>\n</ComplexType>\n\n<Term Name=\"ChangeTracking\" Type=\"Capabilities.ChangeTrackingType\" AppliesTo=\"EntityContainer EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Change tracking capabilities of this service or entity set\" />\n</Term>\n<ComplexType Name=\"ChangeTrackingType\">\n<Property Name=\"Supported\" Type=\"Edm.Boolean\" DefaultValue=\"true\">\n<Annotation Term=\"Core.Description\" String=\"This entity set supports the odata.track-changes preference\" />\n</Property>\n<Property Name=\"FilterableProperties\" Type=\"Collection(Edm.PropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"Change tracking supports filters on these properties\" />\n</Property>\n<Property Name=\"ExpandableProperties\" Type=\"Collection(Edm.NavigationPropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"Change tracking supports these properties expanded\" />\n</Property>\n</ComplexType>\n\n<!--Query Capabilities -->\n\n<Term Name=\"CountRestrictions\" Type=\"Capabilities.CountRestrictionsType\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Restrictions on /$count path suffix and $count=true system query option\" />\n</Term>\n<ComplexType Name=\"CountRestrictionsType\">\n<Property Name=\"Countable\" Type=\"Edm.Boolean\" DefaultValue=\"true\">\n<Annotation Term=\"Core.Description\" String=\"Entities can be counted\" />\n</Property>\n<Property Name=\"NonCountableProperties\" Type=\"Collection(Edm.PropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"These collection properties do not allow /$count segments\" />\n</Property>\n<Property Name=\"NonCountableNavigationProperties\" Type=\"Collection(Edm.NavigationPropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"These navigation properties do not allow /$count segments\" />\n</Property>\n</ComplexType>\n\n<Term Name=\"NavigationRestrictions\" Type=\"Capabilities.NavigationRestrictionsType\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Restrictions on navigating properties according to OData URL conventions\" />\n</Term>\n<ComplexType Name=\"NavigationRestrictionsType\">\n<Property Name=\"Navigability\" Type=\"Capabilities.NavigationType\">\n<Annotation Term=\"Core.Description\" String=\"Supported Navigability\" />\n</Property>\n<Property Name=\"RestrictedProperties\" Type=\"Collection(Capabilities.NavigationPropertyRestriction)\" />\n</ComplexType>\n<ComplexType Name=\"NavigationPropertyRestriction\">\n<Property Name=\"NavigationProperty\" Type=\"Edm.NavigationPropertyPath\">\n<Annotation Term=\"Core.Description\" String=\"Navigation properties can be navigated to a single level\" />\n</Property>\n<Property Name=\"Navigability\" Type=\"Capabilities.NavigationType\">\n<Annotation Term=\"Core.Description\" String=\"Navigation properties can be navigated to a single level\" />\n</Property>\n</ComplexType>\n<EnumType Name=\"NavigationType\">\n<Member Name=\"Recursive\">\n<Annotation Term=\"Core.Description\" String=\"Navigation properties can be recursively navigated\" />\n</Member>\n<Member Name=\"Single\">\n<Annotation Term=\"Core.Description\" String=\"Navigation properties can be navigated to a single level\" />\n</Member>\n<Member Name=\"None\">\n<Annotation Term=\"Core.Description\" String=\"Navigation properties are not navigable\" />\n</Member>\n</EnumType>\n\n<Term Name=\"IndexableByKey\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Supports key values according to OData URL conventions\" />\n</Term>\n\n<Term Name=\"TopSupported\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Supports $top\" />\n</Term>\n<Term Name=\"SkipSupported\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Supports $skip\" />\n</Term>\n\n<Term Name=\"BatchSupported\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"EntityContainer\">\n<Annotation Term=\"Core.Description\" String=\"Supports $batch requests\" />\n</Term>\n\n<Term Name=\"FilterFunctions\" Type=\"Collection(Edm.String)\" AppliesTo=\"EntityContainer EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"List of functions supported in $filter\" />\n</Term>\n\n<Term Name=\"FilterRestrictions\" Type=\"Capabilities.FilterRestrictionsType\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Restrictions on $filter expressions\" />\n</Term>\n<ComplexType Name=\"FilterRestrictionsType\">\n<Property Name=\"Filterable\" Type=\"Edm.Boolean\" DefaultValue=\"true\">\n<Annotation Term=\"Core.Description\" String=\"$filter is supported\" />\n</Property>\n<Property Name=\"RequiresFilter\" Type=\"Edm.Boolean\" Nullable=\"true\">\n<Annotation Term=\"Core.Description\" String=\"$filter is required\" />\n</Property>\n<Property Name=\"RequiredProperties\" Type=\"Collection(Edm.PropertyPath)\">\n<Annotation Term=\"Core.Description\"\nString=\"These properties must be specified in the $filter clause (properties of derived types are not allowed here)\" />\n</Property>\n<Property Name=\"NonFilterableProperties\" Type=\"Collection(Edm.PropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"These properties cannot be used in $filter expressions\" />\n</Property>\n</ComplexType>\n\n<Term Name=\"SortRestrictions\" Type=\"Capabilities.SortRestrictionsType\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Restrictions on $orderby expressions\" />\n</Term>\n<ComplexType Name=\"SortRestrictionsType\">\n<Property Name=\"Sortable\" Type=\"Edm.Boolean\" DefaultValue=\"true\">\n<Annotation Term=\"Core.Description\" String=\"$orderby is supported\" />\n</Property>\n<Property Name=\"AscendingOnlyProperties\" Type=\"Collection(Edm.PropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"These properties can only be used for sorting in Ascending order\" />\n</Property>\n<Property Name=\"DescendingOnlyProperties\" Type=\"Collection(Edm.PropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"These properties can only be used for sorting in Descending order\" />\n</Property>\n<Property Name=\"NonSortableProperties\" Type=\"Collection(Edm.PropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"These properties cannot be used in $orderby expressions\" />\n</Property>\n</ComplexType>\n\n<Term Name=\"ExpandRestrictions\" Type=\"Capabilities.ExpandRestrictionsType\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Restrictions on $expand expressions\" />\n</Term>\n<ComplexType Name=\"ExpandRestrictionsType\">\n<Property Name=\"Expandable\" Type=\"Edm.Boolean\" DefaultValue=\"true\">\n<Annotation Term=\"Core.Description\" String=\"$expand is supported\" />\n</Property>\n<Property Name=\"NonExpandableProperties\" Type=\"Collection(Edm.NavigationPropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"These properties cannot be used in $expand expressions\" />\n</Property>\n</ComplexType>\n\n<Term Name=\"SearchRestrictions\" Type=\"Capabilities.SearchRestrictionsType\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Restrictions on $search expressions\" />\n</Term>\n<ComplexType Name=\"SearchRestrictionsType\">\n<Property Name=\"Searchable\" Type=\"Edm.Boolean\" DefaultValue=\"true\">\n<Annotation Term=\"Core.Description\" String=\"$search is supported\" />\n</Property>\n<Property Name=\"UnsupportedExpressions\" Type=\"Capabilities.SearchExpressions\" DefaultValue=\"none\">\n<Annotation Term=\"Core.Description\" String=\"Expressions supported in $search\" />\n</Property>\n</ComplexType>\n<EnumType Name=\"SearchExpressions\" IsFlags=\"true\">\n<Member Name=\"none\" Value=\"0\" />\n<Member Name=\"AND\" Value=\"1\" />\n<Member Name=\"OR\" Value=\"2\" />\n<Member Name=\"NOT\" Value=\"4\" />\n<Member Name=\"phrase\" Value=\"8\" />\n<Member Name=\"group\" Value=\"16\" />\n</EnumType>\n\n<!-- Data Modification Capabilities -->\n\n<Term Name=\"InsertRestrictions\" Type=\"Capabilities.InsertRestrictionsType\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Restrictions on insert operations\" />\n</Term>\n<ComplexType Name=\"InsertRestrictionsType\">\n<Property Name=\"Insertable\" Type=\"Edm.Boolean\" DefaultValue=\"true\">\n<Annotation Term=\"Core.Description\" String=\"Entities can be inserted\" />\n</Property>\n<Property Name=\"NonInsertableNavigationProperties\" Type=\"Collection(Edm.NavigationPropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"These navigation properties do not allow deep inserts\" />\n</Property>\n</ComplexType>\n\n<Term Name=\"UpdateRestrictions\" Type=\"Capabilities.UpdateRestrictionsType\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Restrictions on update operations\" />\n</Term>\n<ComplexType Name=\"UpdateRestrictionsType\">\n<Property Name=\"Updatable\" Type=\"Edm.Boolean\" DefaultValue=\"true\">\n<Annotation Term=\"Core.Description\" String=\"Entities can be updated\" />\n</Property>\n<Property Name=\"NonUpdatableNavigationProperties\" Type=\"Collection(Edm.NavigationPropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"These navigation properties do not allow rebinding\" />\n</Property>\n</ComplexType>\n\n<Term Name=\"DeleteRestrictions\" Type=\"Capabilities.DeleteRestrictionsType\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\" String=\"Restrictions on delete operations\" />\n</Term>\n<ComplexType Name=\"DeleteRestrictionsType\">\n<Property Name=\"Deletable\" Type=\"Edm.Boolean\" DefaultValue=\"true\">\n<Annotation Term=\"Core.Description\" String=\"Entities can be deleted\" />\n</Property>\n<Property Name=\"NonDeletableNavigationProperties\" Type=\"Collection(Edm.NavigationPropertyPath)\">\n<Annotation Term=\"Core.Description\" String=\"These navigation properties do not allow DeleteLink requests\" />\n</Property>\n</ComplexType>\n\n</Schema>\n</edmx:DataServices>\n</edmx:Edmx>\n"
#define XS_CsdlParser_DOC_2 @"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<!--\nOData Version 4.0\nOASIS Standard\n24 February 2014\nCopyright (c) OASIS Open 2014. All Rights Reserved.\nSource: http://docs.oasis-open.org/odata/odata/v4.0/os/vocabularies/\n\n-->\n<edmx:Edmx xmlns:edmx=\"http://docs.oasis-open.org/odata/ns/edmx\" Version=\"4.0\">\n<edmx:DataServices>\n<Schema xmlns=\"http://docs.oasis-open.org/odata/ns/edm\" Namespace=\"Org.OData.Core.V1\" Alias=\"Core\">\n<Annotation Term=\"Core.Description\">\n<String>Core terms needed to write vocabularies</String>\n</Annotation>\n\n<!--Documentation -->\n\n<Term Name=\"Description\" Type=\"Edm.String\">\n<Annotation Term=\"Core.Description\" String=\"A brief description of a model element\" />\n<Annotation Term=\"Core.IsLanguageDependent\" />\n</Term>\n\n<Term Name=\"LongDescription\" Type=\"Edm.String\">\n<Annotation Term=\"Core.Description\" String=\"A lengthy description of a model element\" />\n<Annotation Term=\"Core.IsLanguageDependent\" />\n</Term>\n\n<!-- Localization -->\n\n<Term Name=\"IsLanguageDependent\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"Property Term\">\n<Annotation Term=\"Core.Description\" String=\"Properties and terms annotated with this term are language-dependent\" />\n<Annotation Term=\"Core.RequiresType\" String=\"Edm.String\" />\n</Term>\n\n<!-- Term Restrictions -->\n\n<TypeDefinition Name=\"Tag\" UnderlyingType=\"Edm.Boolean\">\n<Annotation Term=\"Core.Description\" String=\"This is the type to use for all tagging terms\" />\n</TypeDefinition>\n\n<Term Name=\"RequiresType\" Type=\"Edm.String\" AppliesTo=\"Term\">\n<Annotation Term=\"Core.Description\"\nString=\"Properties and terms annotated with this annotation MUST have a type that is identical to or derived from the given type name\" />\n</Term>\n\n<!--Resource Paths -->\n\n<Term Name=\"ResourcePath\" Type=\"Edm.String\" AppliesTo=\"EntitySet Singleton ActionImport FunctionImport\">\n<Annotation Term=\"Core.Description\"\nString=\"Resource path for entity container child, can be relative to xml:base and the request URL\" />\n<!-- fix bug: <Annotation Term=\"Core.IsUrl\" /> -->\n<Annotation Term=\"Core.IsURL\" />\n</Term>\n\n<Term Name=\"DereferenceableIDs\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"EntityContainer\">\n<Annotation Term=\"Core.Description\" String=\"Entity-ids are URLs that locate the identified entity\" />\n</Term>\n\n<Term Name=\"ConventionalIDs\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"EntityContainer\">\n<Annotation Term=\"Core.Description\" String=\"Entity-ids follow OData URL conventions\" />\n</Term>\n\n<!-- Permissions -->\n\n<Term Name=\"Permissions\" Type=\"Core.Permission\" AppliesTo=\"Property\">\n<Annotation Term=\"Core.Description\" String=\"Permissions available for a property.The value of 2 is reserved for future use.\" />\n</Term>\n<EnumType Name=\"Permission\" IsFlags=\"true\">\n<Member Name=\"None\" Value=\"0\" />\n<Member Name=\"Read\" Value=\"1\" />\n<Member Name=\"ReadWrite\" Value=\"3\" />\n</EnumType>\n\n<!-- Metadata Extensions -->\n\n<Term Name=\"Immutable\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"Property\">\n<Annotation Term=\"Core.Description\"\nString=\"A value for this non-key property can be provided on insert and remains unchanged on update\" />\n</Term>\n\n<Term Name=\"Computed\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"Property\">\n<Annotation Term=\"Core.Description\" String=\"A value for this property is generated on both insert and update\" />\n</Term>\n\n<Term Name=\"IsURL\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"Property Term\">\n<Annotation Term=\"Core.Description\" String=\"Properties and terms annotated with this term MUST contain a valid URL\" />\n<Annotation Term=\"Core.RequiresType\" String=\"Edm.String\" />\n</Term>\n\n<Term Name=\"AcceptableMediaTypes\" Type=\"Collection(Edm.String)\" AppliesTo=\"EntityType Property\">\n<Annotation Term=\"Core.Description\"\nString=\"Lists the MIME types acceptable for the annotated entity type marked with HasStream=&quot;true&quot; or the annotated stream property\" />\n<Annotation Term=\"Core.IsMediaType\" />\n</Term>\n\n<Term Name=\"MediaType\" Type=\"Edm.String\" AppliesTo=\"Property\">\n<Annotation Term=\"Core.IsMediaType\" />\n<Annotation Term=\"Core.RequiresType\" String=\"Edm.Binary\" />\n</Term>\n\n<Term Name=\"IsMediaType\" Type=\"Core.Tag\" DefaultValue=\"true\" AppliesTo=\"Property Term\">\n<Annotation Term=\"Core.Description\" String=\"Properties and terms annotated with this term MUST contain a valid MIME type\" />\n<Annotation Term=\"Core.RequiresType\" String=\"Edm.String\" />\n</Term>\n\n<Term Name=\"OptimisticConcurrency\" Type=\"Collection(Edm.PropertyPath)\" AppliesTo=\"EntitySet\">\n<Annotation Term=\"Core.Description\"\nString=\"Data modification requires the use of Etags. A non-empty collection contains the set of properties that are used to compute the ETag\" />\n</Term>\n\n</Schema>\n</edmx:DataServices>\n</edmx:Edmx>\n"
#define XS_CsdlParser_DOC_3 @"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<!--\nOData Version 4.0\nOASIS Standard\n24 February 2014\nCopyright (c) OASIS Open 2014. All Rights Reserved.\nSource: http://docs.oasis-open.org/odata/odata/v4.0/os/vocabularies/\n-->\n<edmx:Edmx xmlns:edmx=\"http://docs.oasis-open.org/odata/ns/edmx\" Version=\"4.0\">\n<edmx:Reference Uri=\"http://docs.oasis-open.org/odata/odata/v4.0/os/vocabularies/Org.OData.Core.V1.xml\">\n<edmx:Include Alias=\"Core\" Namespace=\"Org.OData.Core.V1\" />\n</edmx:Reference>\n<edmx:DataServices>\n<Schema xmlns=\"http://docs.oasis-open.org/odata/ns/edm\" Namespace=\"Org.OData.Measures.V1\" Alias=\"Measures\">\n<Annotation Term=\"Core.Description\">\n<String>Terms describing monetary amounts and measured quantities</String>\n</Annotation>\n\n<Term Name=\"ISOCurrency\" Type=\"Edm.String\" AppliesTo=\"Property\">\n<Annotation Term=\"Core.Description\" String=\"The currency for this monetary amount as an ISO 4217 currency code\" />\n</Term>\n\n<Term Name=\"Scale\" Type=\"Edm.Byte\" AppliesTo=\"Property\">\n<Annotation Term=\"Core.Description\"\nString=\"The number of significant decimal places in the scale part (less than or equal to the number declared in the Scale facet)\" />\n<Annotation Term=\"Core.RequiresType\" String=\"Edm.Decimal\" />\n</Term>\n\n<Term Name=\"Unit\" Type=\"Edm.String\" AppliesTo=\"Property\">\n<Annotation Term=\"Core.Description\" String=\"The unit of measure for this measured quantity, e.g. cm for centimeters or % for percentages\" />\n</Term>\n\n</Schema>\n</edmx:DataServices>\n</edmx:Edmx>\n"

/* internal */ @interface XS_CsdlNavigationV3 : XS_PropertyInfo
{
    @private NSString* relName_;
    @private NSString* fromRole_;
    @private NSString* toRole_;
}
/* public */ @property (strong) NSString* relName;
/* public */ @property (strong) NSString* fromRole;
/* public */ @property (strong) NSString* toRole;
/* private */ - (id) init;
/* public */ + (XS_CsdlNavigationV3*) new;
/* public */ - (NSString*) relName;
/* public */ - (void) setRelName :(NSString*)value;
/* public */ - (NSString*) fromRole;
/* public */ - (void) setFromRole :(NSString*)value;
/* public */ - (NSString*) toRole;
/* public */ - (void) setToRole :(NSString*)value;
@end

/* internal */ @interface XS_CsdlAssociationV3 : NSObject
{
    @private NSString* localName_;
    @private NSString* qualifiedName_;
    @private NSString* endType1_;
    @private NSString* endRole1_;
    @private xs_boolean endMany1_;
    @private NSString* endType2_;
    @private NSString* endRole2_;
    @private xs_boolean endMany2_;
}
/* public */ @property (strong) NSString* localName;
/* public */ @property (strong) NSString* qualifiedName;
/* public */ @property (strong) NSString* endType1;
/* public */ @property (strong) NSString* endRole1;
/* public */ @property xs_boolean endMany1;
/* public */ @property (strong) NSString* endType2;
/* public */ @property (strong) NSString* endRole2;
/* public */ @property xs_boolean endMany2;
/* private */ - (id) init;
/* public */ + (XS_CsdlAssociationV3*) new;
/* public */ - (NSString*) localName;
/* public */ - (void) setLocalName :(NSString*)value;
/* public */ - (NSString*) qualifiedName;
/* public */ - (void) setQualifiedName :(NSString*)value;
/* public */ - (NSString*) endType1;
/* public */ - (void) setEndType1 :(NSString*)value;
/* public */ - (NSString*) endRole1;
/* public */ - (void) setEndRole1 :(NSString*)value;
/* public */ - (xs_boolean) endMany1;
/* public */ - (void) setEndMany1 :(xs_boolean)value;
/* public */ - (NSString*) endType2;
/* public */ - (void) setEndType2 :(NSString*)value;
/* public */ - (NSString*) endRole2;
/* public */ - (void) setEndRole2 :(NSString*)value;
/* public */ - (xs_boolean) endMany2;
/* public */ - (void) setEndMany2 :(xs_boolean)value;
@end

#endif
