#include <bits/stdc++.h>
using namespace std;

unordered_map <string, string> sformat(string& fmt, vector <string>& values) 
{
	int n = fmt.size();
	string ans;
	unsigned int val_idx = 0;
	unordered_map <string, string> args;
	for(int i = 0; i < n; i++) 
	{
		if(fmt[i] == '{') 
		{
			if(fmt[i + 1] == '{')
			{
				ans += '{';
				i++;
				continue;
			}

			string key;
			while(++i < n) 
			{
				if(fmt[i] == '}')
				{
					break;
				}
				else if(fmt[i] == '{')
				{
					perror("invalid fmt");
					return args;
				}
				else
				{
					ans += fmt[i];
					key += fmt[i];
				}
			}
			if(val_idx + 1 <= values.size())
			{
				args[key] = values[val_idx];
				ans += ':';
				ans += values[val_idx++];
			}
			else
			{
				perror("invalid fmt");
				return args;
			}
		}
		else if(fmt[i] == '}')
		{
			if(fmt[++i] == '}')
			{
				ans += fmt[i];
				continue;
			}
			perror("invalid fmt");
			return args;
		}
		else ans += fmt[i];
	}
	fmt = ans;
	return args;
}

void print(string& fmt, unordered_map <string, string>& args)
{
	cout<<"--------------------"<<endl;
	cout<<"*msg*"<<endl<<fmt<<endl;
	cout<<"*args*"<<endl;
	for(auto i: args)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
}

int main()
{
	string a = "{sss}";
	string b = "{{sss}}";
	string c = "{sss} {{sss {str}";
	vector <string> vals;
	vals.push_back("test1");
	unordered_map <string, string> args = sformat(a, vals);
	print(a, args);
	args = sformat(b, vals);
	print(b, args);
	vals.push_back("test2");
	args = sformat(c, vals);
	print(c, args);
	return 0;
}