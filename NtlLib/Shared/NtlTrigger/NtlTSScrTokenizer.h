#ifndef _NTL_TSSCRTOKENIZER_H_
#define _NTL_TSSCRTOKENIZER_H_


/** 
	Script tokenizer
*/


class CNtlTSScrTokenizer
{
// Declaration
protected:
	enum { eTOKENIZER_MODE_INVALID, eTOKENIZER_MODE_OUT_BUFFER, eTOKENIZER_MODE_INNER_BUFFER };

	class CToken
	{
	public:
		CToken( const std::string& strToken, int nOffset, int nLine ) 
			: m_strToken( strToken ), m_nOffset ( nOffset ), m_nLine( nLine ) { return; }
	public:
		std::string						m_strToken;
		int								m_nOffset;
		int								m_nLine;		
	};

	typedef std::deque<CToken> deqdef_TokenList;

// Member variables
protected:
	int									m_nMode;

	deqdef_TokenList					m_defTokens;

	std::string							m_strFileName;

	char*								m_pFileBuffer;
	int									m_nFileSize;	

	int									m_nPeekPos;
	int									m_nLastLine;

	bool								m_bComment;

// Constructions and Destructions
public:
	CNtlTSScrTokenizer( const std::string& strFileName, const char* pBuff, int nSize );
	~CNtlTSScrTokenizer( void );	

// Methods
public:
	// ' ' '\t' '\r' '\n' �� �������� �����Ѵ�
	bool								IsSpace( const char c );

	// ',' '=' '(' ')' ';' '{' '}' '<' '+' '-' '*' '/' '>' �� �����ڷ� �����Ѵ�
	bool								IsOperator( const char c );

	// '//' �� �ּ����� �����Ѵ�
	bool								IsComment( const char c, int pos );
	
	// Token �� �����ϸ鼭 �����´�
	std::string							GetNextToken( int* pnOffSet = 0 );

	// Token �� �������� �ʰ� �����´�
	// ���� PopToPeek �Լ��� ȣ��Ǿ��� �� PeekNextToken �� ����ؼ� ������ ��ū���� �ϰ������� ���� �ȴ�
	std::string							PeekNextToken( int* pnOffSet = 0 );
	void								PopToPeek( void );

// Implementations
protected:
	bool								Load( const std::string& strFileName, const char* pBuff, int nSize );
	void								Unload( void );
	bool								Tokenize( void );
};

#endif