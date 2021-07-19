#include <conio.h>
#include <fstream>
#pragma warning(disable : 4996)

namespace c
{
	void printfixed( const char* s, int w) 
	{
		int n = 0;
		for (; *s != 0; s++)
		{
			n++;
			_putch(*s);
		}
		for (; n < w; n++)
		{
			_putch(' ');
		}
	}

	void print(const char* c)
	{
		for (; *c != 0; c++)
		{
			_putch(*c);
		}
	}

	void strrev(char* pl)
	{

		char* pr = pl;
		for (; *pr != 0; pr++);
		pr--;

		for (; pl < pr;pr--, pl++)
		{
			const char temp = *pl;
			*pl = *pr;
			*pr = temp;
		}
	}

	void read(char* buf, int maxsize)
	{
		const char* const pEnd = buf + maxsize;
		for (char c = _getch(); c != 13 && (buf + 1 < pEnd); c = _getch(), buf++)
		{
			_putch(c);
			*buf = c;
		}
		*buf = 0;
	}

	int str2int(const char* s)
	{
		//scans the start point
		const char* p = s;
		for (; *p >= '0' && *p <= '9'; p++);
		p--;

		int value = 0;
		int place = 1;
		// '0' - value

		for (; *p >= *s; p--)
		{
			value = (*p - '0') * place;
			place *= 10;
		}
		return value;
	}

	int fib(int n)
	{

		if (n < 2)
		{
			return n;
		}
		return fib(n - 1) + fib(n - 2);

	}



	void int2str(int val, char* buf, int maxsize)
	{
		char* const pStart = buf;
		const char* const pEnd = buf + maxsize;
		// value + buf;
		for ( ; val > 0 && (buf + 1 < pEnd); val /= 10, buf++)
		{
			*buf = '0' + val % 10;
		}
		*buf = 0;
		strrev(pStart);
	}
}

class Datatype
{
private:
	class Entry
	{
	public:
		Entry() = default;
		Entry(const char* name, int value)
			:
			value(value)
		{
			std::strcpy(this->name, name);
		}
		void print() {
			c::printfixed(name, numMaxBuffer );
			c::print(" | ");
			for (int i = 0; i < value; i++)
			{
				c::print("=");
			}
			c::print(" \n ");
		}
		void deserialize(std::ifstream &in) {
			in.read(name, sizeof(name));
			in.read(reinterpret_cast<char*>(&value), sizeof(value));
		}
		void serialize(std::ofstream &out) {
			out.write(name, sizeof(name));
			out.write(reinterpret_cast<char*>(&value), sizeof(value));
		}
	private:
		int value;
		static constexpr int numMaxBuffer = 10;
		char name[numMaxBuffer];
	};

public:
	void save(char filename) {

	}
	void load(char filename) {

	}
	void add(const char* name, int value) {
		entry[curEntry++] = { name, value };
	}
	void print() {
		for (int i = 0; i < curEntry; i++)
		{
			entry[i].print();
		}
	}

private:
	static constexpr int maxNumEntry = 16;
	int curEntry = 0;
	Entry entry[maxNumEntry];
};

int main() 
{

	c::print(" (l)oad, (s)ave , (a)dd, (p)rint, (q)uit ");

	return 0;
}

