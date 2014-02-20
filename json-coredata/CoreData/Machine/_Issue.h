// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to Issue.h instead.

#import <CoreData/CoreData.h>


extern const struct IssueAttributes {
	__unsafe_unretained NSString *id;
	__unsafe_unretained NSString *title;
} IssueAttributes;

extern const struct IssueRelationships {
	__unsafe_unretained NSString *article;
	__unsafe_unretained NSString *tags;
} IssueRelationships;

extern const struct IssueFetchedProperties {
} IssueFetchedProperties;

@class Article;
@class Tag;




@interface IssueID : NSManagedObjectID {}
@end

@interface _Issue : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (IssueID*)objectID;





@property (nonatomic, strong) NSNumber* id;



@property int32_t idValue;
- (int32_t)idValue;
- (void)setIdValue:(int32_t)value_;

//- (BOOL)validateId:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* title;



//- (BOOL)validateTitle:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) Article *article;

//- (BOOL)validateArticle:(id*)value_ error:(NSError**)error_;




@property (nonatomic, strong) NSSet *tags;

- (NSMutableSet*)tagsSet;





@end

@interface _Issue (CoreDataGeneratedAccessors)

- (void)addTags:(NSSet*)value_;
- (void)removeTags:(NSSet*)value_;
- (void)addTagsObject:(Tag*)value_;
- (void)removeTagsObject:(Tag*)value_;

@end

@interface _Issue (CoreDataGeneratedPrimitiveAccessors)


- (NSNumber*)primitiveId;
- (void)setPrimitiveId:(NSNumber*)value;

- (int32_t)primitiveIdValue;
- (void)setPrimitiveIdValue:(int32_t)value_;




- (NSString*)primitiveTitle;
- (void)setPrimitiveTitle:(NSString*)value;





- (Article*)primitiveArticle;
- (void)setPrimitiveArticle:(Article*)value;



- (NSMutableSet*)primitiveTags;
- (void)setPrimitiveTags:(NSMutableSet*)value;


@end
