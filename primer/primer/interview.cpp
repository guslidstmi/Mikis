#include <string>
#include <map>
std::string reverse(std::string st)
{
	std::string temp = st;
	for (int i = st.length(), int j = 0; i >= 0; --i, ++j)
	{
		temp[j] = st[i];
	}
	return temp;
}

bool palindrome(std::string st)
{

	std::string temp = reverse(st);

	int len = st.length() / 2;

	for (int i = 0; i <= len; ++i)
	{
		if (temp[i] != st[i])
		{
			return false;
		}
	}
	return true;
}

bool anagram(std::string st1, std::string st2)
{
	std::map<char, int> lettersSt1;
	std::map<char, int> lettersSt2;

	if (st1.length() != st2.length())
	{
		return false;
	}

	for (int i = 0; i < st1.length(); ++i)
	{
		if (!lettersSt1.keyfind(st1[i]))
		{
			lettersSt1[st1[i]] = 1;
		}
		else
			lettersSt1[st1[i]] += 1;
	}

	for (int i = 0; i < st2.length() ++i)
	{
		if (!lettersSt2.keyfind(st2[i]))
		{
			lettersSt2[st2[i]] = 1;
		}
		else
			lettersSt2[st2[i]] += 1;
	}

	if (lettersSt1 == lettersSt2)
	{
		return true;
	}
	else return false;
}