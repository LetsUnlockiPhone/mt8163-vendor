/*======================================================================*
 DTS, Inc.
 5220 Las Virgenes Road
 Calabasas, CA 91302  USA

 CONFIDENTIAL: CONTAINS CONFIDENTIAL PROPRIETARY INFORMATION OWNED BY
 DTS, INC. AND/OR ITS AFFILIATES ("DTS"), INCLUDING BUT NOT LIMITED TO
 TRADE SECRETS, KNOW-HOW, TECHNICAL AND BUSINESS INFORMATION. USE,
 DISCLOSURE OR DISTRIBUTION OF THE SOFTWARE IN ANY FORM IS LIMITED TO
 SPECIFICALLY AUTHORIZED LICENSEES OF DTS.  ANY UNAUTHORIZED
 DISCLOSURE IS A VIOLATION OF STATE, FEDERAL, AND INTERNATIONAL LAWS.
 BOTH CIVIL AND CRIMINAL PENALTIES APPLY.

 DO NOT DUPLICATE. COPYRIGHT 2014, DTS, INC. ALL RIGHTS RESERVED.
 UNAUTHORIZED DUPLICATION IS A VIOLATION OF STATE, FEDERAL AND
 INTERNATIONAL LAWS.

 ALGORITHMS, DATA STRUCTURES AND METHODS CONTAINED IN THIS SOFTWARE
 MAY BE PROTECTED BY ONE OR MORE PATENTS OR PATENT APPLICATIONS.
 UNLESS OTHERWISE PROVIDED UNDER THE TERMS OF A FULLY-EXECUTED WRITTEN
 AGREEMENT BY AND BETWEEN THE RECIPIENT HEREOF AND DTS, THE FOLLOWING
 TERMS SHALL APPLY TO ANY USE OF THE SOFTWARE (THE "PRODUCT") AND, AS
 APPLICABLE, ANY RELATED DOCUMENTATION:  (i) ANY USE OF THE PRODUCT
 AND ANY RELATED DOCUMENTATION IS AT THE RECIPIENT�S SOLE RISK:
 (ii) THE PRODUCT AND ANY RELATED DOCUMENTATION ARE PROVIDED "AS IS"
 AND WITHOUT WARRANTY OF ANY KIND AND DTS EXPRESSLY DISCLAIMS ALL
 WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO ANY
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE, REGARDLESS OF WHETHER DTS KNOWS OR HAS REASON TO KNOW OF THE
 USER'S PARTICULAR NEEDS; (iii) DTS DOES NOT WARRANT THAT THE PRODUCT
 OR ANY RELATED DOCUMENTATION WILL MEET USER'S REQUIREMENTS, OR THAT
 DEFECTS IN THE PRODUCT OR ANY RELATED DOCUMENTATION WILL BE
 CORRECTED; (iv) DTS DOES NOT WARRANT THAT THE OPERATION OF ANY
 HARDWARE OR SOFTWARE ASSOCIATED WITH THIS DOCUMENT WILL BE
 UNINTERRUPTED OR ERROR-FREE; AND (v) UNDER NO CIRCUMSTANCES,
 INCLUDING NEGLIGENCE, SHALL DTS OR THE DIRECTORS, OFFICERS, EMPLOYEES,
 OR AGENTS OF DTS, BE LIABLE TO USER FOR ANY INCIDENTAL, INDIRECT,
 SPECIAL, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, AND LOSS
 OF BUSINESS INFORMATION) ARISING OUT OF THE USE, MISUSE, OR INABILITY
 TO USE THE PRODUCT OR ANY RELATED DOCUMENTATION.
*======================================================================*/

#ifndef ANDROID_SRS_TECH_USERPEQ
#define ANDROID_SRS_TECH_USERPEQ

namespace android {

struct SRS_Tech_TruEQ;

struct SRS_Tech_UserPEQ_CFG {
    float   IGain, OGain, BGain;
    int     Preset_Int;             // Internal Preset
    bool    Enabled;                // User-facing PEQ is enabled?
    bool    Skip;                   // Skip processing entirely (instead of bypass)
};

struct SRS_Tech_UserPEQ_Preset {
    char    *pName;
    float   UserParams[4][3];       // 4 bands, 3 params (center freq, gain, q)
    float   DefParams[4][3];        // 4 bands, 3 params (center freq, gain, q)
};

struct SRS_Source_UserPEQ;

// Instead of virtuals - or a 'public' class - we'll hide all of UserPEQ behind this...
extern SRS_Param*   SRS_GetBank_UserPEQ_CFG(int &paramCount);
extern void         SRS_SetParam_UserPEQ_CFG(SRS_Tech_UserPEQ_CFG *pCFG, SRS_Param *pParam, const char *pValue);
extern const char*  SRS_GetParam_UserPEQ_CFG(SRS_Tech_UserPEQ_CFG *pCFG, SRS_Param *pParam);
extern void         SRS_Default_UserPEQ_CFG(SRS_Tech_UserPEQ_CFG *pCFG);

extern SRS_Param*   SRS_GetBank_UserPEQ_Preset(int &paramCount);
extern void         SRS_SetParam_UserPEQ_Preset(SRS_Tech_UserPEQ_Preset *pCFG, SRS_Param *pParam, const char *pValue);
extern const char*  SRS_GetParam_UserPEQ_Preset(SRS_Tech_UserPEQ_Preset *pCFG, SRS_Param *pParam);
extern void         SRS_Default_UserPEQ_Preset(SRS_Tech_UserPEQ_Preset *pCFG);

extern void         SRS_Apply_UserPEQ_CFG(SRS_Tech_TruEQ *pTruEQ, SRS_Tech_UserPEQ_CFG *pCFG);
extern void         SRS_Apply_UserPEQ_Preset(SRS_Tech_TruEQ *pTruEQ, SRS_Tech_UserPEQ_Preset *pCFG);
};

#endif  // ANDROID_SRS_TECH_USERPEQ
