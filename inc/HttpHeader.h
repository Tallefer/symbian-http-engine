/*
* Copyright (c) 2009, Pawe� Pola�ski
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * the names of its contributors may not be used to endorse or promote products
*       derived from this software without specific prior written permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ''AS IS'' 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL PAWE� POLA�SKI BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* Initial Contributors:
* Pawe� Pola�ski - Initial contribution
* Tomasz Pola�ski
*
* Contributors:
*
* Description:
* HttpHeader.h - is handling all HTTP events
* 
* Version: 
* 1.0
*/

#ifndef HTTPHEADER_H
#define HTTPHEADER_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>

class CDesC8Array;

class CHttpHeaders: public CBase
	{
public:
	~CHttpHeaders();

	static CHttpHeaders* NewL();
	static CHttpHeaders* NewLC();

	void AddL( const TDesC8& aKey, const TDesC8& aValue );
	void AddL( const TDesC8& aKey, const TInt& aValue );
	void AddL( const TDesC8& aKey, const TInt64& aValue );

	TPtrC8 Key( TInt aIndex ) const;
	TPtrC8 Value( TInt aIndex ) const;

	TInt Count() const;
	
	TInt Find( const TDesC8& aKey ) const;

	void Reset();
	
private:
	CHttpHeaders();
	void ConstructL();

private:
	CDesC8Array* iKeyArray;
	CDesC8Array* iValueArray;
	};

#endif // HTTPHEADER_H
