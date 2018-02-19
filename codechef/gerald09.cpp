#include <set>
#include <cstring>
#include <iostream>
#include <functional>
#define ONLINE_JUDGE 1
using namespace std;
const string S = "ACGT";

static struct IO {
char tmp[1 << 10];
 
// fast input routines
char cur;
 
//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
inline char nextChar() { return cur = getc_unlocked(stdin); }
inline char peekChar() { return cur; }
 
inline operator bool() { return peekChar(); }
inline static bool isBlank(char c) { return (c < '-' && c); }
inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }
 
inline IO& operator >> (char & c) { c = nextChar(); return *this; }
 
inline IO& operator >> (char * buf) {
if (skipBlanks()) {
if (peekChar()) {
*(buf++) = peekChar();
while (!isBlank(nextChar())) *(buf++) = peekChar();
} *(buf++) = 0; } return *this; }
 
inline IO& operator >> (string & s) {
if (skipBlanks()) {	s.clear(); s += peekChar();
while (!isBlank(nextChar())) s += peekChar(); }
return *this; }
 
inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}
 
#define defineInFor(intType) \
inline IO& operator >>(intType & n) { \
if (skipBlanks()) { \
int sign = +1; \
if (peekChar() == '-') { \
sign = -1; \
n = nextChar() - '0'; \
} else \
n = peekChar() - '0'; \
while (!isBlank(nextChar())) { \
n += n + (n << 3) + peekChar() - 48; \
} \
n *= sign; \
} \
return *this; \
}
 
defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)
 
// fast output routines
 
//#define putChar(c) putc_unlocked((c), stdout)
inline void putChar(char c) { putc_unlocked(c, stdout); }
inline IO& operator << (char c) { putChar(c); return *this; }
inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }
 
inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
 
char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
inline IO& operator << (double d) { return (*this) << toString(d); }
 
 
#define defineOutFor(intType) \
inline char * toString(intType n) { \
char * p = (tmp + 30); \
if (n) { \
bool isNeg = 0; \
if (n < 0) isNeg = 1, n = -n; \
while (n) \
*--p = (n % 10) + '0', n /= 10; \
if (isNeg) *--p = '-'; \
} else *--p = '0'; \
return p; \
} \
inline IO& operator << (intType n) { return (*this) << toString(n); }
 
defineOutFor(int)
defineOutFor(long long)
 
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {   int n,m,k;
        cin>>n>>m>>k;
        char A[n][m];
        if(k<=n*m)
        {   for(int i=0; i<n; i++)
            {   for(int j=0; j<m; j++)
                {   A[i][j]='A';
                }
            }
        }
        else
        {   for(int i=0; i<n; i++)
            {   for(int j=0; j<m; j++)
                {   A[i][j]=S[rand()%4];
                }
            }
        }
        hash<string> strhash;
        int count=0;
        for(int i=1; i<=n; i++)
        {   for(int j=1; j<=m; j++)
            {   set<unsigned long long> hey;
                for(int x=0; x<=n-i; x++)
                {   for(int y=0; y<=m-j; y++)
                    {   int sz=0;
                        string s(&A[x][y], &A[x][y+j]);
                        for(int k=1; k<i; k++)
                        {   s.append(&A[x+k][y], &A[x+k][y+j]);
                        }
                        hey.insert(strhash(s));
                    }
                }
                count+=hey.size();
            }
        }
        //count=hey.size();
        //cout<<count<<'\n';
        
        for(int i=0; i<n; i++)
        {   for(int j=0; j<m; j++)
                cout<<A[i][j];
            cout<<'\n';
        }
    }
    
    return 0;
}