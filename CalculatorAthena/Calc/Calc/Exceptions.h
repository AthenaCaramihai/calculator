#pragma once
class Exceptions
{public:
	virtual const char* what() const
	{
		return "Expresie incorecta / Impartire la 0";
	}
};

