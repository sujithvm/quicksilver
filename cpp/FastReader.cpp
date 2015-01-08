#include <cstdio>
#include <string>
#include <memory.h>
#include <iostream>

#define BUF_SIZE 65536
char input_buf[BUF_SIZE];

struct FastReader {
	char* cur_pos;

	FastReader() {
		fread(input_buf, 1, sizeof(input_buf), stdin);
		cur_pos = input_buf;
	}

	void fill_buffer() {
		int size = input_buf + BUF_SIZE - cur_pos;
		if (size < (1 << 7)) {
			memcpy(input_buf, cur_pos, size);
			fread(input_buf + size, 1, BUF_SIZE - size, stdin);
			cur_pos = input_buf;
		}
	}

	int read_int() {
		fill_buffer();
		while (*cur_pos <= ' ')
			cur_pos++;
		bool sign = false;
		if (*cur_pos == '-') {
			sign = true;
			cur_pos++;
		}
		int res = 0;
		while (*cur_pos > ' ')
			res = (res << 3) + (res << 1) + (*(cur_pos++) & 15);
		return sign ? -res : res;
	}

	long int read_long() {
		fill_buffer();
		while (*cur_pos <= ' ')
			cur_pos++;
		bool sign = false;
		if (*cur_pos == '-') {
			sign = true;
			cur_pos++;
		}
		long long int res = 0LL;
		while (*cur_pos > ' ')
			res = (res << 3) + (res << 1) + (*(cur_pos++) & 15);
		return sign ? -res : res;
	}

	char read_char() {
		fill_buffer();
		while (*cur_pos <= ' ')
			cur_pos++;
		return *(cur_pos++);
	}

	std::string read_string() {
		fill_buffer();
		std::string str = "";
		while (*cur_pos <= ' ')
			cur_pos++;
		while (*cur_pos != ' ' && *cur_pos != '\n')
			str = str + *(cur_pos++);
		return str;
	}

	std::string read_line() {
		fill_buffer();
		std::string str = "";
		while (*cur_pos <= ' ')
			cur_pos++;
		while (*cur_pos != '\n')
			str = str + *(cur_pos++);
		return str;
	}	
};

int main() {
	FastReader fr;

	int n1 = fr.read_int();
	long long int n2 = fr.read_long();
	char ch = fr.read_char();
	std::string str1 = fr.read_string();
	std::string str2 = fr.read_line();		

	std::cout << n1 << "\n";
	std::cout << n2 << "\n";
	std::cout << ch << "\n";
	std::cout << str1 << "\n";
	std::cout << str2 << "\n";	
	
	return 0;
    
}
