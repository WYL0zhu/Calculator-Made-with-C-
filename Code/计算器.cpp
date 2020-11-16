#include <bits/stdc++.h>
using namespace std;
long long gcd(long long m, long long n)
{
	if(!n)
		return m;
	if(!m)
		return n;
	return gcd(n, m % n);
}
long long lcm(long long m, long long n)
{
	return m * n / gcd(m, n);
}
struct frac
{
	int n, m = 1;
	frac &init(long long a, long long b = 1)
	{
		long long g = gcd(a, b);
		n = a / g;
		m = b / g;
		if(m < 0)
		{
			n = -n;
			m = -m;
		}
	}
	void print(string s)
	{
		cout << n << s << m;
	}
	frac &operator+=(frac &a)
	{
		long long l = lcm(m, a.m);
		n *= l / m;
		a.n *= l / a.m;
		m = a.m = l;
		n += a.n;
		long long g = gcd(n, m);
		n /= g;
		m /= g;
		if(m < 0)
		{
			n = -n;
			m = -m;
		}
		return *this;
	}
	frac &operator-=(frac &a)
	{
		long long l = lcm(m, a.m);
		n *= l / m;
		a.n *= l / a.m;
		m = a.m = l;
		n -= a.n;
		long long g = gcd(n, m);
		n /= g;
		m /= g;
		if(m < 0)
		{
			n = -n;
			m = -m;
		}
		return *this;
	}
	frac &operator*=(frac &a)
	{
		n *= a.n;
		m *= a.m;
		long long g = gcd(n, m);
		n /= g;
		m /= g;
		if(m < 0)
		{
			n = -n;
			m = -m;
		}
		return *this;
	}
	frac &operator/=(frac &a)
	{
		swap(a.n, a.m);
		*this *= a;
		return *this;
	}
};
struct node
{
    char ch = ' ';
    frac n;
} a[200003], b, c, t;
long long num, d;
char ch;
stack<node> sta;
long long pow(long long n, long long m)
{
	if(!m)
		return 1;
	if(m & 1)
		return n * pow(n * n, m >> 1);
	return pow(n * n, m >> 1);
}
frac &pow(frac n, long long m)
{
	frac t;
	long long a, b;
	a = pow(n.n, m);
	b = pow(n.m, m);
	t.init(a, b);
	return t;
}
int main()
{
	int i, j;
    t.n.n = -1;
    while(cin >> ch)
        switch(ch)
        {
            case '+':
            case '-':
                if(!sta.empty() && sta.top().ch == ')')
                    sta.pop();
                else
                {
                    a[++num] = b;
                    b.n.n = 0;
                }
                while(!sta.empty() && sta.top().ch != '(')
                {
                    a[++num] = sta.top();
                    sta.pop();
                }
                t.ch = ch;
                sta.push(t);
                break;
            case '*':
            case '/':
                if(!sta.empty() && sta.top().ch == ')')
                    sta.pop();
                else
                {
                    a[++num] = b;
                    b.n.n = 0;
                }
                while(!sta.empty() && (sta.top().ch == '*' || sta.top().ch == '/' || sta.top().ch == '^'))
                {
                    a[++num] = sta.top();
                    sta.pop();
                }
                t.ch = ch;
                sta.push(t);
                break;
            case '^':
                if(!sta.empty() && sta.top().ch == ')')
                    sta.pop();
                else
                {
                    a[++num] = b;
                    b.n.n = 0;
                }
                while(!sta.empty() && sta.top().ch == '^')
                {
                    a[++num] = sta.top();
                    sta.pop();
                }
                t.ch = ch;
                sta.push(t);
                break;
            case '(':
                t.ch = ch;
                sta.push(t);
                break;
            case ')':
                a[++num] = b;
                b.n.n = 0;
                while(!sta.empty() && sta.top().ch != '(')
                {
                    a[++num] = sta.top();
                    sta.pop();
                }
                sta.pop();
                t.ch = ch;
                sta.push(t);
                break;
            default:
                b.n.n *= 10;
                b.n.n += ch;
                b.n.n -= '0';
                break;
        }
    if(!sta.empty() && sta.top().ch == ')')
        sta.pop();
    else
    {
        a[++num] = b;
        b.n.n = 0;
    }
    while(!sta.empty())
    {
        a[++num] = sta.top();
        sta.pop();
    }
    for(i = 1; i <= num; ++i)
    	if(a[i].ch == ' ')
    		cout << a[i].n.n << " ";
    	else
    		cout << a[i].ch << " ";
    cout << endl;
    for(i = 1; i <= num; ++i)
        if(a[i].ch == ' ')
            sta.push(a[i]);
        else
            switch(a[i].ch)
            {
                case '+':
                    c = sta.top();
                    sta.pop();
                    b = sta.top();
                    sta.pop();
                    b.n += c.n;
                    sta.push(b);
                    break;
                case '-':
                    c = sta.top();
                    sta.pop();
                    b = sta.top();
                    sta.pop();
                    b.n -= c.n;
                    sta.push(b);
                    break;
                case '*':
                    c = sta.top();
                    sta.pop();
                    b = sta.top();
                    sta.pop();
                    b.n *= c.n;
                    sta.push(b);
                    break;
                case '/':
                    c = sta.top();
                    sta.pop();
                    b = sta.top();
                    sta.pop();
                    b.n /= c.n;
                    sta.push(b);
                    break;
                case '^':
                    c = sta.top();
                    sta.pop();
                    b = sta.top();
                    sta.pop();
                    b.n = pow(b.n, c.n.n);
                    sta.push(b);
                    break;
            }
    sta.top().n.print("/");
    cout << endl << static_cast<double>(sta.top().n.n) / sta.top().n.m;
    return 0;
}
