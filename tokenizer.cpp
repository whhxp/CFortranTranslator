#include "tokenizer.h"
#include "grammar\for90.tab.h"
#include <string>

using namespace std;

const KeywordMeta keywords[] = {
	KeywordMeta{"if"
		, TokenMeta::If
		, YY_IF
	}
	, KeywordMeta{"then"
		, TokenMeta::META_ANY
		, YY_THEN
	}
	, KeywordMeta{"else"
		, TokenMeta::Else
		, YY_ELSE
	}
	, KeywordMeta{"end"
		, TokenMeta::META_ANY
		, YY_END
	}
	, KeywordMeta{"do"
		, TokenMeta::Do
		, YY_DO
	}
	, KeywordMeta{"continue"
		, TokenMeta::Continue
		, YY_CONTINUE
	}
	, KeywordMeta{"while"
		, TokenMeta::While
		, YY_WHILE
	}
	, KeywordMeta{"where"
		, TokenMeta::META_ANY
		, YY_WHERE
	}
	, KeywordMeta{"case"
		, TokenMeta::Case
		, YY_CASE
	}
	, KeywordMeta{"program"
		, TokenMeta::META_ANY
		, YY_PROGRAM
	}
	, KeywordMeta{"function"
		, TokenMeta::META_ANY
		, YY_FUNCTION
	}
	, KeywordMeta{"recursive"
		, TokenMeta::META_ANY
		, YY_RECURSIVE
	}
	, KeywordMeta{"result"
		, TokenMeta::META_ANY
		, YY_RESULT
	}
	, KeywordMeta{"subroutine"
		, TokenMeta::META_ANY
		, YY_SUBROUTINE
	}
	, KeywordMeta{"module"
		, TokenMeta::META_ANY
		, YY_MODULE
	}
	, KeywordMeta{"block"
		, TokenMeta::META_ANY
		, YY_BLOCK
	}
	, KeywordMeta{"implicit"
		, TokenMeta::META_ANY
		, YY_IMPLICIT
	}
	, KeywordMeta{"none"
		, TokenMeta::META_ANY
		, YY_NONE
	}
	, KeywordMeta{"use"
		, TokenMeta::META_ANY
		, YY_USE
	}
	, KeywordMeta{"parameter"
		, TokenMeta::META_ANY
		, YY_PARAMETER
	}
	, KeywordMeta{"format"
		, TokenMeta::META_ANY
		, YY_FORMAT
	}
	, KeywordMeta{"and" 
		, TokenMeta::AndAnd
		, YY_ANDAND
	}
	, KeywordMeta{".or."
		, TokenMeta::OrOr
		, YY_OROR
	}
	, KeywordMeta{".not."
		, TokenMeta::Not
		, YY_NOT
	}
	, KeywordMeta{".eqv."
		, TokenMeta::META_ANY
		, YY_EQV
	}
	, KeywordMeta{".neqv"
		, TokenMeta::META_ANY
		, YY_NEQV
	}
	, KeywordMeta{".true."
		, TokenMeta::True
		, YY_TRUE
	}
	, KeywordMeta{".false."
		, TokenMeta::False
		, YY_FALSE
	}
	, KeywordMeta{".gt."
		, TokenMeta::GT
		, YY_GT
	}
	, KeywordMeta{".ge."
		, TokenMeta::GE
		, YY_GE
	}
	, KeywordMeta{".lt."
		, TokenMeta::LT
		, YY_LT
	}
	, KeywordMeta{".le."
		, TokenMeta::LE
		, YY_LE
	}
	, KeywordMeta{".eq."
		, TokenMeta::EQ
		, YY_EQ
	}
	, KeywordMeta{".neq."
		, TokenMeta::NEQ
		, YY_NEQ
	}
};

