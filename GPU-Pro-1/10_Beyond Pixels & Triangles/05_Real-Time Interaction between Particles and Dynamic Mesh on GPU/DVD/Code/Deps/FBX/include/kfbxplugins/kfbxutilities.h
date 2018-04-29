/*!  \file kfbxutilities.h
 */

#ifndef _FBXSDK_UTILITIES_H_
#define _FBXSDK_UTILITIES_H_

/**************************************************************************************

 Copyright � 2001 - 2008 Autodesk, Inc. and/or its licensors.
 All Rights Reserved.

 The coded instructions, statements, computer programs, and/or related material 
 (collectively the "Data") in these files contain unpublished information 
 proprietary to Autodesk, Inc. and/or its licensors, which is protected by 
 Canada and United States of America federal copyright law and by international 
 treaties. 
 
 The Data may not be disclosed or distributed to third parties, in whole or in
 part, without the prior written consent of Autodesk, Inc. ("Autodesk").

 THE DATA IS PROVIDED "AS IS" AND WITHOUT WARRANTY.
 ALL WARRANTIES ARE EXPRESSLY EXCLUDED AND DISCLAIMED. AUTODESK MAKES NO
 WARRANTY OF ANY KIND WITH RESPECT TO THE DATA, EXPRESS, IMPLIED OR ARISING
 BY CUSTOM OR TRADE USAGE, AND DISCLAIMS ANY IMPLIED WARRANTIES OF TITLE, 
 NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE OR USE. 
 WITHOUT LIMITING THE FOREGOING, AUTODESK DOES NOT WARRANT THAT THE OPERATION
 OF THE DATA WILL BE UNINTERRUPTED OR ERROR FREE. 
 
 IN NO EVENT SHALL AUTODESK, ITS AFFILIATES, PARENT COMPANIES, LICENSORS
 OR SUPPLIERS ("AUTODESK GROUP") BE LIABLE FOR ANY LOSSES, DAMAGES OR EXPENSES
 OF ANY KIND (INCLUDING WITHOUT LIMITATION PUNITIVE OR MULTIPLE DAMAGES OR OTHER
 SPECIAL, DIRECT, INDIRECT, EXEMPLARY, INCIDENTAL, LOSS OF PROFITS, REVENUE
 OR DATA, COST OF COVER OR CONSEQUENTIAL LOSSES OR DAMAGES OF ANY KIND),
 HOWEVER CAUSED, AND REGARDLESS OF THE THEORY OF LIABILITY, WHETHER DERIVED
 FROM CONTRACT, TORT (INCLUDING, BUT NOT LIMITED TO, NEGLIGENCE), OR OTHERWISE,
 ARISING OUT OF OR RELATING TO THE DATA OR ITS USE OR ANY OTHER PERFORMANCE,
 WHETHER OR NOT AUTODESK HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH LOSS
 OR DAMAGE. 

**************************************************************************************/

#include <kaydaradef.h>
#ifndef KFBX_DLL 
	#define KFBX_DLL K_DLLIMPORT
#endif

#include <kaydara.h>

#include <kfbxplugins/kfbxscene.h>

#include <fbxfilesdk_nsbegin.h>

class KFbxTexture;

/** 
	* \name Scene cleaning
	*/
//@{

/** Clean bad meshes in the scene by removing bad polygons.
	* \param pScene     Pointer to the scene object.
	* \return           Array of nodes containing modified meshes.
	*/
KFBX_DLL KArrayTemplate<KFbxNode*> RemoveBadPolygonsFromMeshes(KFbxScene *pScene);
//@}


/** 
  * \name File utilities
  */
//@{

/** Get the content of a file from an hyperlink
  * \param url The hyperlink to the file. The URL must start with < http:// > ex: http://www.autodesk.com.
  * \return An allocated <char *buffer> containing the source text. You must use FBXFree_Internet_Buffer() to 
  * free the allocated memory.
  */
KFBX_DLL char* FBXGet_Internet_Source_File(const char *url);

/** Free the memory allocated by FBXGet_Internet_Source_File()
  * \param pBuf Pointer previously returned by a call to FBXGet_Internet_Source_File().
  */
KFBX_DLL void FBXFree_Internet_Buffer(char* pBuf);

KFBX_DLL KString KFbxFullPath(const char* pRelativePath);

KFBX_DLL KString KFbxExtractDirectory(const char* pFilePath);

KFBX_DLL KString KFbxExtractFileName(const char* pFilePath, bool pWithExtension=true);

KFBX_DLL KString KFbxCleanPath(const char* pPath);

KFBX_DLL KString KFbxGetRelativeFilePath(const char *pRootPath, const char *pNewFilePath);

KFBX_DLL bool KFbxEnsureDirectoryExistance(const char* pPath);

KFBX_DLL KString KFbxGetApplicationDirectory();

// Returns the amount of virtual memory available to the process; will take into account
// swap file, and the process address space if there are such limits (ie: Win32 process
// can access 2, 3 or 4gb depending on the OS they're running on, Win64 has a much
// larger limit, limited possibly by the swap file)
KFBX_DLL size_t KGetProcessVirtualMemoryAvailSize ();
//@}

#include <fbxfilesdk_nsend.h>

#endif // #ifndef _FBXSDK_UTILITIES_H_

