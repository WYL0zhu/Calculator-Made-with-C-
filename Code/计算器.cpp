#include <bits/stdc++.h>
using namespace std;
struct node
{
    char ch = ' ';
    long long n = 0;
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
long long r(long long n, long long m)
{
	long long l = 1, r = m, mid, ans;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(pow(mid, n) <= m)
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return ans;
}
long long lo(long long n, long long m)
{
	long long l = 1, r = m, mid, ans;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(pow(n, mid) <= m)
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return ans;
}
int main()
{
    int i, j;
    t.n = -1;
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
                    b.n = 0;
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
            case 'm':
                if(!sta.empty() && sta.top().ch == ')')
                    sta.pop();
                else
                {
                    a[++num] = b;
                    b.n = 0;
                }
                while(!sta.empty() && (sta.top().ch == '*' || sta.top().ch == '/' || sta.top().ch == 'm' || sta.top().ch == '^' || sta.top().ch == 'r' || sta.top().ch == 'l'))
                {
                    a[++num] = sta.top();
                    sta.pop();
                }
                t.ch = ch;
                sta.push(t);
                break;
            case '^':
            case 'r':
            case 'l':
                if(!sta.empty() && sta.top().ch == ')')
                    sta.pop();
                else
                {
                    a[++num] = b;
                    b.n = 0;
                }
                while(!sta.empty() && (sta.top().ch == '^' || sta.top().ch == 'r' || sta.top().ch == 'l'))
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
                b.n = 0;
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
                b.n *= 10;
                b.n += ch;
                b.n -= '0';
                break;
        }
    if(!sta.empty() && sta.top().ch == ')')
        sta.pop();
    else
    {
        a[++num] = b;
        b.n = 0;
    }
    while(!sta.empty())
    {
        a[++num] = sta.top();
        sta.pop();
    }
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
                case 'm':
                	c = sta.top();
                    sta.pop();
                    b = sta.top();
                    sta.pop();
                    b.n %= c.n;
                    sta.push(b);
                    break;
                case '^':
                    c = sta.top();
                    sta.pop();
                    b = sta.top();
                    sta.pop();
                    b.n = pow(b.n, c.n);
                    sta.push(b);
                    break;
                case 'r':
                    c = sta.top();
                    sta.pop();
                    b = sta.top();
                    sta.pop();
                    b.n = r(b.n, c.n);
                    sta.push(b);
                    break;
                case 'l':
                    c = sta.top();
                    sta.pop();
                    b = sta.top();
                    sta.pop();
                    b.n = lo(b.n, c.n);
                    sta.push(b);
                    break;
            }
    cout << sta.top().n;
    return 0;
}
