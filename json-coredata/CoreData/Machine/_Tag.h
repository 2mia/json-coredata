// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to Tag.h instead.

#import <CoreData/CoreData.h>


extern const struct TagAttributes {
} TagAttributes;

extern const struct TagRelationships {
	__unsafe_unretained NSString *issue;
} TagRelationships;

extern const struct TagFetchedProperties {
} TagFetchedProperties;

@class Issue;


@interface TagID : NSManagedObjectID {}
@end

@interface _Tag : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (TagID*)objectID;





@property (nonatomic, strong) Issue *issue;

//- (BOOL)validateIssue:(id*)value_ error:(NSError**)error_;





@end

@interface _Tag (CoreDataGeneratedAccessors)

@end

@interface _Tag (CoreDataGeneratedPrimitiveAccessors)



- (Issue*)primitiveIssue;
- (void)setPrimitiveIssue:(Issue*)value;


@end
