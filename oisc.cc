#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
string input, x, a, b, v, help;
vector <string> q, results;
int res, a1, b1, aminus, bminus, c, last_res, pos;
int toInt (string x) {
  int res;
	istringstream iss(x);
  iss >> res;
  return res;
}
string toString (int x) {
  ostringstream temp;
  temp<<x;
  string res=temp.str();
	return res;
}
void newSubleq (string a, string b, string c) {
  results.push_back(a + " " + b + " " + c);
}
int main()
{
	ios_base::sync_with_stdio(0);

	while (getline(cin,input))
	{
    results.clear();
		res = 9001;
		newSubleq(toString(res), toString(res), " 12");
		q.clear();
		newSubleq("0", "0", "15");
		c=18;
		pos=0;
		while (1)
		{
      if (pos >= input.size()) break;
			x = "";
			if (input[pos]==' ') pos++;
			for (; pos<input.size(); pos++)
			{
				if (input[pos] == ' ') break;
				x += input[pos];
			}

			if (x != "+" && x != "-" && x != "*" && x != "/") q.push_back(x);
			else
			{
				b = q.back();
				q.pop_back();
				a = q.back();
				q.pop_back();
				if (a[0] == 'M')
				{
					help = "";
					for (int i = 1; i < a.size(); i++) help += a[i];
					a1 = toInt(help);
					aminus = res;
					res++;
					newSubleq(toString(res), toString(res), toString(c));
					c += 3;
					newSubleq(toString(a1), toString(aminus), toString(c));
					c += 3;
				}
				else
				{
					a1 = res;
					res++;
					newSubleq(toString(res), toString(res), toString(c));
					c += 3;
					newSubleq("-" + a, toString(a1), toString(c));
					c += 3;
					aminus = res;
					res++;
					newSubleq(toString(res), toString(res), toString(c));
					c += 3;
					newSubleq(toString(a1), toString(aminus), toString(c));
					c += 3;
				}

				if (b[0] == 'M')
				{
					help = "";
					for (int i = 1; i < b.size(); i++) help += b[i];
					b1 = toInt(help);
					bminus = res;
					res++;
					newSubleq(toString(res), toString(res), toString(c));
					c += 3;
					newSubleq(toString(b1), toString(bminus), toString(c));
					c += 3;
				}
				else
				{
					b1 = res;
					res++;
					newSubleq(toString(res), toString(res), toString(c));
					c += 3;
					newSubleq("-" + b, toString(b1), toString(c));
					c += 3;
					bminus = res;
					res++;
					newSubleq(toString(res), toString(res), toString(c));
					c += 3;
					newSubleq(toString(b1), toString(bminus), toString(c));
					c += 3;
				}

				if (x == "-")
				{
					newSubleq(toString(a1), toString(b1), toString(c));
					c += 3;
					newSubleq(toString(b1), toString(res), toString(c));
					c += 3;
					last_res = res;
					res++;
					newSubleq(toString(res), toString(res), toString(c));
					c += 3;
					v = "M" + toString(last_res);
					q.push_back(v);
				}
				else if (x == "+")
				{
					newSubleq(toString(b1), toString(aminus), toString(c));
					c += 3;
					newSubleq(toString(aminus), toString(res), toString(c));
					c += 3;
					last_res = res;
					res++;
					newSubleq(toString(res), toString(res), toString(c));
					c += 3;
					v = "M" + toString(last_res);
					q.push_back(v);
				}
				else if (x == "*")
				{
					newSubleq("-1", toString(aminus), toString(c));
					c += 6;
					newSubleq(toString(bminus), toString(res), toString(c));
					newSubleq("-1", toString(aminus), toString(c - 6));
					last_res = res;
					res++;
					c += 3;
					newSubleq(toString(res), toString(res), toString(c));
					c += 3;
					v = "M" + toString(last_res);
					q.push_back(v);
				}
				else if (x == "/")
				{
					newSubleq(toString(bminus), toString(aminus), toString(c));
					c += 6;
					newSubleq("-1", toString(res), toString(c));
					newSubleq(toString(bminus), toString(aminus), toString(c - 6));
					last_res = res;
					res++;
					c += 3;
					newSubleq(toString(res), toString(res), toString(c));
					c += 3;
					v = "M" + toString(last_res);
					q.push_back(v);
				}
			}
		}


		if (q[0][0] == 'M')
		{
			cout << results.size() + 3 << "\n";
			for (int i = 0; i < results.size(); i++) {
        cout << results[i] << "\n";
      }
			cout << last_res << " " << res << " " << c << "\n";
			c += 3;
			cout << res << " " << 0 << " " << c <<"\n";
			c += 3;
			res++;
			cout << c << " " << c << " " << 10000 <<"\n";
		}
		else
		{
			cout << results.size() + 2 << "\n";
			for (int i = 0; i < results.size(); i++) cout << results[i] << "\n";
			cout << "-" << q[0] << " " << 0 << " " << c << "\n";
			c += 3;
			res++;
			cout << c << " " << c << " " << 10000 << "\n";
		}
	}

	return 0;
}
