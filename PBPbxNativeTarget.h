/*
   Project: pbxbuild

   Copyright (C) 2006 Free Software Foundation

   Author: Hans Baier,,,

   Created: 2006-08-11 11:49:37 +0200 by jack

   This application is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This application is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA.
*/

#ifndef _PBPBXNATIVETARGET_H_
#define _PBPBXNATIVETARGET_H_

#include <Foundation/Foundation.h>
@class PBPbxProject;

#define PBX_VERSION_SNOWLEOPARD_XCODE_3_2 @"46"
#define PBX_VERSION_SNOWLEOPARD_XCODE_3_1 @"45"
#define PBX_VERSION_LEOPARD @"44"
#define PBX_VERSION_TIGER @"42"
#define PBX_VERSION_PANTHER @"39"
#define PBX_VERSION_JAGUAR @"38"

@interface PBPbxNativeTarget : NSObject
{
  PBPbxProject        *project;
  NSDictionary        *objects;
  
  NSString            *targetKey;
  NSString            *targetName;
  NSString            *targetType;
  NSString            *targetSubtype;

  NSString            *infoPlistFile;
  NSDictionary        *infoPlist;
  NSString            *productVersion;
  
  NSMutableSet        *includeDirs;
  NSMutableSet        *libraryDirs;
  NSMutableArray      *headers;
  NSMutableSet        *headerNonGroupDirs;
  NSMutableDictionary *sources;
  NSMutableSet        *languages;
  NSMutableArray      *resources;
  NSMutableArray      *localizedResources;
  NSMutableArray      *frameworks;
  NSMutableArray      *dependencyKeys;
  NSMutableDictionary *scripts;
  NSMutableSet        *targetDependencies;
	
  NSDictionary        *buildSettings;
}

/**
 * <em>Designated Initializer</em>: Initializes this Class with
 * the given target as a [NSMutableDictionary] and objects
 * in order to look up the references stored in target .
 */
- (id) initWithProject: (PBPbxProject *)project
             andTarget: (NSDictionary *)target
         withTargetKey: (NSString *)targetKey;

/**
 * traverses the dependency Keys for the target and
 * sets the field targetDependencies with links to the other [PBPbxNativeTarget]s
 * This assumes that the target List of project is already complete
 */
- (void) resolveDependencyKeys;

/**
 * compares the current target with anotherTarget: 
 * <ul><li>If the current target 
 * depends on anotherTarget it returns [NSOrderedDescending]</li>
 * <ul><li>If anotherTarget 
 * depends on the current target it returns [NSOrderedAscending]</li>
 * <ul><li>If both targets are not dependant on each other
 * it returns [NSOrderedSame]</li>
 * </ul>
 * The ordering is due to the order of building the targets: Lesser targets
 * have to be built before greater Targets
 */
- (NSComparisonResult) compareDepends: (PBPbxNativeTarget *)anotherTarget;

/**
 * Two PBPbxNativeTarget instances are considered equal when their targetKey 
 * property is the same
 */
- (BOOL) isEqual: (id)anObject;

/**
 * getter Method
 */
- (NSString *) targetKey;

/**
 * getter Method
 */
- (NSString *) targetName;

/**
 * getter Method
 */
- (NSString *) targetNameReplacingSpaces;

/**
 * getter Method -- returns the normalized target type 
 * (app, bundle, framework, tool, etc.)
 */
- (NSString *) targetType;

/**
 * Returns the subtype of the given target.  Null if none
 * is specified.
 */
- (NSString *) targetSubtype;

/**
 * getter Method
 */
- (NSDictionary *) infoPlist;

/**
 * getter Method
 */
- (NSString *) infoPlistFile;

/**
 * getter Method
 */
- (NSString *) productVersion;

/**
 * getter Method: returns an Array of [NSString]
 */
- (NSMutableSet *) includeDirs;

/**
 * getter Method: returns an Array of [NSString]
 */
- (NSMutableSet *) libraryDirs;

/**
 * getter Method: returns an Array of [NSString]
 */
- (NSMutableArray *) headers;

/**
 * getter Method: returns a Set of [NSString]
 */
- (NSMutableSet *) headerNonGroupDirs;

/**
 * getter Method: returns an Array of [NSString]
 */
- (NSMutableDictionary *) sources;

/**
 * getter Method: returns an Array of [NSString]
 */
- (NSMutableSet *) languages;

/**
 * getter Method: returns an Array of [NSString]
 */
- (NSMutableArray *) resources;

/**
 * getter Method
 */
- (NSMutableArray *) localizedResources;

/**
 * getter Method: returns an Array of [NSString]
 */
- (NSMutableArray *) frameworks;

/**
 * getter Method: returns an Dictionary of [NSString]
 */
- (NSMutableDictionary *) scripts;

/**
 * getter Method: returns an Array of [PBPbxNativeTarget]
 */
- (NSMutableSet *) targetDependencies;


/**
 * returns the description of the object
 */
- (NSString *) description;

/** 
 * getter Method: returns a dictionary of the build settings
 */
- (NSDictionary *) buildSettings;

/**
 * getter Method: returns the proper extension
 */
- (NSString *) extension;

- (void) dealloc;
@end

#endif // _PBPBXNATIVETARGET_H_

