//�ر�ͬ��
#include <iostream>
using namespace std;
ios_base::sync_with_stdio(false);
cin.tie(0);


//�ַ������ٶ���
string buff;
getline(cin, buff);
cin.get();//��һ���ַ�


//�ض���
#define LOCAL
#include <cstdio>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	return 0;
}


//�ļ���д
int main()
{
    FILE *fin, *fout;
    fin = fopen("in.txt", "rb");
    fout = fopen("out.txt", "wb");
    int n;
    fscanf(fin, "%d", &n);
    fprintf(fout, "%d\n", n);
    fclose(fin);
    fclose(fout);
    return 0;
}


//shell����
g++ ./rand.cpp -std=c++17 -o rand
g++ ./std.cpp -std=c++17 -o std
g++ ./A.cpp -std=c++17 -o A
while true
do
	./rand > in.txt
	./std < in.txt > ans.txt
	./A < in.txt > out.txt
	if diff ans.txt out.txt
	then
		echo "AC"
	else
		echo "WA"
		break
	fi
done

//�ṹ�塢���������
struct jewel {
    int id, v, w;
    double s, d;

    bool operator<(const jewel &another) const
    {
        return d > another.d;
    }
};

//��ŷ��������O(N^1/2)��
int phi(int x)
{
	int ans = x;
	for (int i = 2; (ll)i * i <= x; i++) {
		if (x % i == 0) {
			ans /= i; ans *= (i - 1);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) ans /= x, ans *= (x - 1);
	return ans;
}


//������������ɸ����O(NloglogN)��
int total;
int prime[MAXN + 10];
bool boolprime[MAXN + 10];

void eratosthenes(int n)
{
    memset(boolprime, false, sizeof(boolprime));
    total = 0;
    for (int i = 2; i * i <= n; i++)
        if (!boolprime[i])
            for (int j = i * i; j <= n; j += i) boolprime[j] = true;
    for (int i = 2; i <= n; i++)
        if (!boolprime[i]) prime[++total] = i;
}


//��������ŷ��ɸ����O(N)��
int total;
int prime[MAXN + 10];
bool boolprime[MAXN + 10];

void euler(int n)
{
    memset(boolprime, false, sizeof(boolprime));
    total = 0;
    for (int i = 2; i <= n; i++) {
        if (!boolprime[i]) prime[++total] = i;
        for (int j = 1; j <= total && i * prime[j] <= n; j++) {
            boolprime[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}


//��ŷ��������O(N)��
vector<int> prime;
int phi[MAXN];
bool done[MAXN];

void get_phi(int n)
{
	memset(done, false, sizeof(done));
	for (int i = 2; i < n; i++) {
		if (!done[i]) {
			prime.push_back(i);
			phi[i] = i - 1;
		}
		for (int j = 0; j < prime.size() && (ll)i * prime[j] < n; j++) {
			done[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = prime[j] * phi[i];
				break;
			}
			else
				phi[i * prime[j]] = phi[prime[j]] * phi[i];
		}
	}
}


//��Ī����˹������O(N)��
vector<int> prime;
int mobius[MAXN];
bool done[MAXN];

void get_mobius(int n)
{
	memset(done, false, sizeof(done));
	memset(mobius, 0, sizeof(mobius));
	mobius[1] = 1;
	for (int i = 2; i < n; i++) {
		if (!done[i]) mobius[i] = -1, prime.push_back(i);
		for (int j = 0; j < prime.size() && (ll)i * prime[j] < n; j++) {
			done[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
			else
				mobius[i * prime[j]] = -mobius[i];
		}
	}
}


//���ٳ˷�ȡģ��������ȡģ
ll qmul(ll a, ll b, ll c)
{
	ll ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % c;
		a = a + a % c;
		b >>= 1;
	}
	return ans;
}

ll qpow(ll a, ll b, ll c)
{
	ll ans = 1;
	while (b) {
		if (b & 1) ans = qmul(ans, a, c);
		a = qmul(a, a, c);
		b >>= 1;
	}
	return ans;
}


//�������ж���Miller Rabin�㷨��
const int PRIME[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 61, 67};//���Լ�

int t;

bool miller_rabin(ll n)
{
	if (n == 2) return true;
	if (n == 1 || !(n & 1)) return false;
	ll d = n - 1;
	while (!(d & 1)) d >>= 1;
	int s = 15;
	for (int i = 0; i <= s; i++) {
		if (n == PRIME[i]) return true;
		ll t = qpow(PRIME[i], d, n);//����д�ÿ���������ٳ�
		ll g = d;
		while (g != n - 1 && t != 1 && t != n - 1) {
			t = t * t % n;
			g <<= 1;
		}
		if ((t == 1 && !(g & 1)) || (t != 1 && g == n - 1)) return false;
	}
	return true;
}


//ŷ������㷨
long long gcd(long long a, long long b)
{
    return (b == 0 ? a : gcd(b, a % b));
}


//��չŷ������㷨
long long x, y;

long long extgcd(long long a, long long b)
{
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    else {
        long long d, t;
        d = extgcd(b, a % b);
        t = x; x = y;
        y = t - a / b * y;
        return d;
    }
}


//01����
    int n, volume;
    int vo[MAXN], va[MAXN], dp[MAXV];

    for (int i = 1; i <= n; i++) {
        for (int j = volume; j >= vo[i]; j--)
            dp[j] = max(dp[j], dp[j - vo[i]] + va[i]);
    printf("%d\n", dp[volume]);


//��ȫ����
    int n, volume;
    int vo[MAXN], va[MAXN], dp[MAXV];

    for (int i = 1; i <= n; i++) {
        for (int j = vo[i]; j <= volume; j++)
            dp[j] = max(dp[j], dp[j - vo[i]] + va[i]);
    }
    printf("%d\n", dp[volume]);


//���ر���
    int n, volume;
    int vo[MAXN], va[MAXN], num[MAXN], dp[MAXV];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= num[i]; j *= 2) {//�������Ż�
            int vasum = j * va[i], vosum = j * vo[i];
            for (int k = volume; k >= vosum; k--)
                dp[k] = max(dp[k], dp[k - vosum] + vasum);
            num[i] -= j;
        }
        int vasum = num[i] * va[i], vosum = num[i] * vo[i];
        for (int k = volume; k >= vosum; k--)
            dp[k] = max(dp[k], dp[k - vosum] + vasum);
    }

//��������
int n, cnt;
int ans[MAXN], in_degree[MAXN];
vector<int> connect[MAXN];
queue<int, vector<int> > q;

void toposort()
{
	cnt = 0;
	memset(in_degree, 0, sizeof(in_degree));
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < connect[i].size(); j++) in_degree[connect[i][j]]++;
	for (int i = 1; i <= n; i++) if (!in_degree[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ans[++cnt] = u;
		for (int i = 0; i < connect[u].size(); i++) {
			int v = connect[u][i];
			in_degree[v]--;
			if (!in_degree[v]) q.push(v);
		}
	}
}



//��С��������Kruskal�㷨��
struct edge {
    int from, to;
    int dist;
    bool operator<(const edge &another) const
    {
        return dist < another.dist;
    }
};

int n, m;//n�ǽڵ�����m�Ǳ���
edge e[MAXM];
int fa[MAXN];//��¼�ڵ������

int findfather(int x)//���鼯
{
    return (x == fa[x] ? x : fa[x] = findfather(fa[x]));
}

int kruskal()//��С������������
{
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int p, q;
        p = findfather(e[i].from);
        q = findfather(e[i].to);
        if (p != q) {
            fa[q] = p;
            ans += e[i].dist;
            cnt++;
        }
        if (cnt == n - 1) break;
    }
    return ans;
}


//�����·��Bellman Ford�㷨��
struct edge {
    int st, ed;
    int dist;
};

edge e[MAXM];
int dist[MAXN];
int n, m;//nΪ�ڵ�����mΪ����

bool bellman_ford(int x)//xΪԴ��
{
    memset(dist, 0x3f, sizeof(dist));
    dist[x] = 0;
    int i;
    for (i = 1; i <= n; i++) {
        bool flag = false;
        for (int j = 1; j <= m; j++)//˫����跴����㣬������򲻱�
            if (dist[e[j].ed] > dist[e[j].st] + e[j].dist) {
                dist[e[j].ed] = dist[e[j].st] + e[j].dist;
                flag = true;
            }
            else
            if (dist[e[j].st] > dist[e[j].ed] + e[j].dist) {
                dist[e[j].st] = dist[e[j].ed] + e[j].dist;
                flag = true;
            }
        if (!flag) break;
    }
    return (i == n + 1);//����true�Ǵ��ڸ���
}


//�����·��SPFA�㷨��
int n;//nΪ�ڵ���
int dist[MAXN], cnt[MAXN];//dist��¼��Դ��ľ��룬cnt��¼��Ӵ���
int path[MAXN][MAXN];//��¼��������֮���ֱ�Ӿ���
bool boolin[MAXN];//��¼�Ƿ��ڶ�����
queue<int> q;

bool spfa(int x)//xΪԴ��
{
    memset(dist, 0x3f, sizeof(dist));
    dist[x] = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(boolin, false, sizeof(boolin));
    q.push(x); boolin[x] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); boolin[u] = false;
        for (int i = 1; i <= n; i++)
            if (dist[i] > dist[u] + path[u][i]) {
                dist[i] = dist[u] + path[u][i];
                if (!boolin[i]) {
                    q.push(i);
                    boolin[i] = true;
                    cnt[i]++;
                    if (cnt[i] > n) return true;//���ڸ���
                }
            }
    }
    return false;//�����ڸ���
}


//�����·��Dijkstra�㷨�����Ӷ�O(N^2)�����ã�
int n;//n���ڵ�
int path[MAXN][MAXN];
int dist[MAXN];//�����֮��ľ���
bool boolset[MAXN];//��¼�������·�������еĵ�

void dijkstra(int x)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(boolset, false, sizeof(boolset));
    dist[x] = 0;
    for (int i = 1; i <= n; i++) {
        int mindist = INF, u;
        for (int j = 1; j <= n; j++)
            if (!boolset[j] && dist[j] < mindist) {//��ȡ���ܵ���ķǼ������е�������
                mindist = dist[j];
                u = j;
            }
        boolset[u]=true;//����ȷ���Ļ�����·�ĵ����뼯��
        for (int j = 1; j <= n; j++)
            if (!boolset[j] && path[u][j] != INF && dist[j] > dist[u] + path[u][j])
                dist[j] = dist[u] + path[u][j];//�ɳڲ���
    }
}


//�����·��Dijkstra�㷨�����Ӷ�O(NlogN)���Ҵ���·����¼��
const int MAXN = 505;

struct edge {
	int from, to, dist;

	edge() {}//Ĭ�Ϲ��캯����д����������
	edge (int _from, int _to, int _dist) : from(_from), to(_to), dist(_dist) {}
};

struct node {
	int u, d;

	node() {}
	node(int _u, int _d) : u(_u), d(_d) {}

	bool operator<(const node &another) const
	{
		return d > another.d;
	}
};

int n, m, origin, terminal;
vector<edge> e;//��
vector<int> g[MAXN];//�ڽӱ�
int d[MAXN], last[MAXN];//d�ǵ㵽���ľ��룬last�Ǹõ�����·����Դ�ߵı��
bool done[MAXN];//ȷ�����·�ĵ㼯
priority_queue<node> q;//���ȶ����Ż�

void add_edge(int from, int to, int dist)
{
	e.push_back(edge(from, to, dist));
	g[from].push_back(e.size() - 1);
}

void dijkstra(int x)
{
	memset(done, false, sizeof(done));
	memset(d, 0x3f, sizeof(done));
	d[x] = 0;
	q.push(node(x, 0));
	while (!q.empty()) {
		int u = q.top().u; q.pop();
		if (done[u]) continue;//����㶪��
		done[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (d[now.to] > d[u] + now.dist) {
				d[now.to] = d[u] + now.dist;
				last[now.to] = g[u][i];//��¼��Դ�߱��
				q.push(node(now.to, d[now.to]));
			}
		}
	}
}


//�������Edmond Karp�㷨�����Ӷ�O(N * M^2)��
const int MAXN = 205, INF = 0x3f3f3f3f;

struct edge {
	int from, to, cap, flow;
	
	edge() {}
	edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

int n;
vector<edge> e;
vector<int> g[MAXN];
int p[MAXN], a[MAXN];
queue<int> q;

void init()
{
	e.clear();
	for (int i = 1; i<= n; i++) g[i].clear();
}

void add_edge(int from, int to, int cap, int flow)
{
	e.push_back(edge(from, to, cap, flow));
	g[from].push_back(e.size() - 1);
}

int edmond_karp(int s, int t)
{
	int ans = 0;
	while (true) {
		memset(a, 0, sizeof(a));
		a[s] = INF;
		while (!q.empty()) q.pop();
		q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < g[u].size(); i++) {
				edge &now = e[g[u][i]];
				if (!a[now.to] && now.cap - now.flow > 0) {
					p[now.to] = g[u][i];
					a[now.to] = min(a[u], now.cap - now.flow);
					q.push(now.to);
				}
			}
			if (a[t]) break;
		}
		if (!a[t]) break;
		for (int i = t; i != s; i = e[p[i]].from) {
			e[p[i]].flow += a[t];
			e[p[i] ^ 1].flow -= a[t];
		}
		ans += a[t];
	}
	return ans;
}


//�������Dinic�㷨�����Ӷ�O(N^2 * M)��
const int MAXN = 1005, INF = 0x3f3f3f3f;

struct edge {
	int from, to, cap, flow;
	
	edge() {}
	edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

int n;
vector<edge> e;
vector<int> g[MAXN];
queue<int> q;
int d[MAXN], cur[MAXN];

void init()
{
	e.clear();
	for (int i = 0; i <= n; i++) g[i].clear();
}

void add_edge(int u, int v, int c, int f)
{
	e.push_back(edge(u, v, c, f));
	g[u].push_back(e.size() - 1);
}

bool bfs(int s, int t)
{
	memset(d, 0, sizeof(d));
	d[s] = 1; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (d[now.to] || now.cap - now.flow == 0) continue;
			d[now.to] = d[u] + 1;
			q.push(now.to);
		}
	}
	return (d[t] != 0);
}

int dfs(int u, int t, int f)
{
	if (u == t || f == 0) return f;
	int ans = 0, add;
	for (int &i = cur[u]; i < g[u].size(); i++) {
		edge &now = e[g[u][i]];
		if (d[now.to] == d[u] + 1 && (add = dfs(now.to, t, min(f, now.cap - now.flow))) > 0) {
			e[g[u][i]].flow += add;
			e[g[u][i] ^ 1].flow -= add;
			ans += add;
			f -= add;
			if (f == 0) break;
		}
	}
	return ans;
}

int dinic(int s, int t)
{
	int ans = 0;
	while (bfs(s, t)) {
		memset(cur, 0, sizeof(cur));
		ans += dfs(s, t, INF);
	}
	return ans;
}


//��С������������������Ϊ������������Ϊ������
const double INF = 1e17, EPS = 1e-8;

struct edge {
	int from, to, cap, flow;
	double cost;

	edge() {}
	edge(int u, int v, int c, int f, double w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};

int n;
vector<edge> e;
vector<int> g[MAXN];
int a[MAXN], p[MAXN];
double d[MAXN];
queue<int> q;
bool inq[MAXN];

void init()
{
	e.clear();
	for (int i = 0; i <= n + 1; i++) g[i].clear();
}

void add_edge(int u, int v, int c, double w)
{
	e.push_back(edge(u, v, c, 0, w));
	e.push_back(edge(v, u, 0, 0, -w));//����߷���Ϊ�෴��
	g[u].push_back(e.size() - 2);
	g[v].push_back(e.size() - 1);
}

bool spfa(int s, int t, int &flow, double &cost)
{
	for (int i = 0; i <= n + 1; i++) d[i] = INF;
	memset(inq, false, sizeof(inq));
	d[s] = 0; q.push(s); inq[s] = true;
	a[s] = 0x3f3f3f3f;
	while (!q.empty()) {
		int u = q.front(); q.pop(); inq[u] = false;
		for (int i = 0; i < g[u].size(); i++) {
			edge &now = e[g[u][i]];
			if (now.cap - now.flow > 0 && d[now.to] > d[u] + now.cost + EPS) {//��Ϊ����������Ե�ʣ��˴�������EPS
				a[now.to] = min(a[u], now.cap - now.flow);
				d[now.to] = d[u] + now.cost;
				p[now.to] = g[u][i];
				if (!inq[now.to]) {
					q.push(now.to);
					inq[now.to] = true;
				}
			}
		}
	}
	if (d[t] == INF) return false;
	for (int i = t; i != s; i = e[p[i]].from) {
		e[p[i]].flow += a[t];
		e[p[i] ^ 1].flow -= a[t];
	}
	flow += a[t];
	cost += d[t] * a[t];
	return true;
}

int min_cost_max_flow(int s, int t, double &cost)//��С���������
{
	int ans = 0;
	cost = 0;
	while (spfa(s, t, ans, cost));//ѭ�����Ҳ�������·Ϊֹ
	return ans;
}


//��ʽǰ����
struct edge {
    int from,to;
    int dist;
    int next;//�����fromΪ�˵����һ���ߵı��
};

int cnt;
int head[MAXN];//�����ĳ��Ϊ�˵�����һ���ߵı��
edge e[MAXM];

void addedge(int from, int to, int dist)
{
    cnt++;
    e[cnt].from = from;
    e[cnt].to = to;
    e[cnt].dist = dist;
    e[cnt].next = head[from];
    head[from] = cnt;
}

for (int i = head[u]; i != 0; i = e[i].next) {}//������uΪ�˵�ı�


//�߾��ȼӷ�
const int TEN[4] = {1, 10, 100, 1000};
const int MAXL = 1000;

struct bignumber {
    int d[MAXL];

    bignumber()
    {
        *this = bignumber(string("0"));
    }

    bignumber(string s)
    {
        int len = s.size();
        d[0] = (len - 1) / 4 + 1;
        for (int i = 1; i < MAXL; i++) d[i] = 0;
        for (int i = len - 1; i >= 0; i--) {
            int j = (len - i - 1) / 4 + 1, k = (len - i - 1) % 4;
            d[j] += TEN[k] * (s[i] - '0');
        }
        while (d[0] > 1 && d[d[0]] == 0) d[0]--;
    }

    string tostring()
    {
        string s("");
        int i, temp;
        for (i = 3; i >= 1; i--) if(d[d[0]] >= TEN[i]) break;
        temp = d[d[0]];
        for (int j = i; j >= 0; j--) {
            s = s + (char)(temp / TEN[j] + '0');
            temp %= TEN[j];
        }
        for (i = d[0] - 1; i > 0; i--) {
            temp = d[i];
            for (int j = 3; j >= 0; j--) {
                s = s + (char)(temp / TEN[j] + '0');
                temp %= TEN[j];
            }
        }
        return s;
    }

    bignumber operator+(const bignumber &another)
    {
        bignumber c;
        c.d[0] = max(d[0], another.d[0]);
        int x = 0;
        for (int i = 1; i <= c.d[0]; i++) {
            x = x + d[i] + another.d[i];
            c.d[i] = x % 10000;
            x /= 10000;
        }
        while (x != 0) {
            c.d[++c.d[0]] = x % 10000;
            x /= 10000;
        }
        return c;
    }
};


//���������ȡģ
const int MOD = 10000;

struct matrix {
    int a[2][2];//����2*2�ľ���

    matrix()
    {
        memset(a, 0, sizeof(a));
    }

    matrix operator*(const matrix &another) const
    {
        matrix ans;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++)
                    ans.a[i][j] += a[i][k] * another.a[k][j];
                ans.a[i][j] %= MOD;//ȡģ
            }
        return ans;
    }
};

matrix qpow(matrix a, int b)
{
    matrix ans = {{{1, 0}, {0, 1}}};//2*2�ĵ�λ����
    while (b) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}


//����ͼ�����ƥ�䣨�������㷨�����Ӷ�O(N * M)��
int n;//�����㼯�ĵ���
bool visited[MAXN];//�����Ҳ���Ƿ��ڽ���·��
int xmatch[MAXN], ymatch[MAXN];//ƥ�����
vector<int> connect[MAXN];//����������Ҳ����������

bool dfs(int u)
{
    for (int i = 0; i < connect[u].size(); i++) {
        int j = connect[u][i];
        if (!visited[j]){//���Ҳ�ĳ�㲻�ڽ���·�л�δ�����ʹ�
            visited[j] = true;//��֮���뽻��·�������Ѿ�����
            if (ymatch[j] == -1 || dfs(ymatch[j])) {//�����Ҳ���ҵ�δƥ�������ȥ���ҵ�����·
                xmatch[u] = j;
                ymatch[j] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int ans = 0;
    memset(xmatch, 0xff, sizeof(xmatch));//��ʼ��ƥ�����Ϊ-1
    memset(ymatch, 0xff, sizeof(ymatch));
    for(int i = 0; i < n; i++) {//��㼯��Ŵ�0��ʼ
        memset(visited, false, sizeof(visited));
        if (dfs(i)) ans++;
    }
    return ans;
}


//��������������
int binary_add(int a, int b)//�����Ƽӷ�
{
    int ans = a;//����a+0ʱû�г�ֵ
    while (b) {
        ans = a ^ b;
        b = (a & b) << 1;
        a = ans;
    }
    return ans;
}

int negative(int a)//ȡ�෴��
{
    return binary_add(~a, 1);
}

int binary_minus(int a, int b)//�����Ƽ���
{
    return binary_add(a, negative(b));//����ת��Ϊ�ӷ�
}

int multiply(int a, int b)//�������˷�
{
    int ans = 0;
    while (b) {
        if (b & 1) ans = binary_add(ans, a);
        a <<= 1;
        b >>= 1;
    }
    return ans;
}

int divide(int a, int b)//����������
{
    int cnt = 0;
    while (a >= b) {
        a = binary_minus(a, b);
        cnt = binary_add(cnt, 1);
    }
    return cnt;
}

bool isneg(int a)
{
    return a & 0x80000000;//�Ǹ����򷵻�true
}

bool iszero(int a)
{
    return !(a & 0xffffffff);//��0�򷵻�true
}

bool ispos(int a)
{
    return !isneg(a) && !iszero(a);//���Ǹ��ҷ�����Ϊ��
}

int binary_mul(int a, int b)//�����Ƴ˷�
{
    if (isneg(a)) {
        if (isneg(b))
            return multiply(negative(a), negative(b));
        else
            return negative(multiply(negative(a), b));
    }
    else {
        if (isneg(b))
            return negative(multiply(a, negative(b)));
        else
            return multiply(a, b);
    }
}

int binary_div(int a, int b)//�����Ƴ���
{
    if (b == 0) {
        printf("Error!\n");//������Ĵ���
        return 0;
    }
    if (isneg(a)) {
        if (isneg(b))
            return divide(negative(a), negative(b));
        else
            return negative(divide(negative(a), b));
    }
    else {
        if(isneg(b))
            return negative(divide(a, negative(b)));
        else
            return divide(a, b);
    }
}


//�鲢����������Եĸ�����������������ָ������x < y��sum[x] < sum[y],��ȵ�Ҳ�㣩
int sum[MAXN], temp[MAXN];

ll merge_sort(int l, int r)
{
	if (l == r) return 0;
	ll ans = 0;
	int mid = (l + r) >> 1;
	ans += merge_sort(l, mid);
	ans += merge_sort(mid + 1, r);
	int i = l, j = mid + 1, index = l;
	while (i <= mid && j <= r) {
		if (sum[i] < sum[j])
			temp[index++] = sum[i++];
		else
			temp[index++] = sum[j++], ans += (mid + 1 - i);
	}
	while (i <= mid) temp[index++] = sum[i++];
	while (j <= r) temp[index++] = sum[j++];
	for (int i = l; i <= r; i++) sum[i] = temp[i];
	return ans;
}


//��״����
int n;
int a[MAXN];

int lowbit(int x)
{
    return (x & -x);//������������һ��1�������
}

void modify(int x, int num)//���޸ģ���x����num
{
    while (x <= n) {
        a[x] += num;
        x += lowbit(x);//�޸ĸ��߲��
    }
}

int sum(int x)//���1��x�������
{
    int ans = 0;
    while (x > 0) {
        ans +=a[x];
        x -= lowbit(x);
    }
    return ans;
}


//ST��������Сֵ��
int n;
int a[MAXN], log[MAXN];
int st[MAXN][32];

void st_prepare()
{
	log[1] = 0;
	for (int i = 2; i <= n; i++) {
		log[i] = log[i - 1];
		if (1 << (log[i] + 1) == i) log[i]++;//���ƶ���
	}
	for (int i = n; i >= 1; i--) {
		st[i][0] = a[i];
		for (int j = 1; i + (1 << j) - 1 <= n; j++)
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);//ȡ������Сֵ
	}
}

int query(int l, int r)//����ѯ��
{
	int k = log[r - l + 1];
	return min(st[l][k], st[r - (1 << k) + 1][k]);
}


//�߶�����������¡������ѯ��
const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct segment {
    int left, right, mid;//��¼�߶���硢�ҽ硢�е�
    int val;//�߶����������ֵ���˴������ֵ
};

int n;
int a[MAXN];
segment tree[4 * MAXN];//�߶���ĿӦ��ΪҶ�ӽڵ������ı�

void build(int left, int right, int root)
{
    tree[root].left = left;
    tree[root].right = right;
    tree[root].mid = (left + right) / 2;
    if (lef t == right)
        tree[root].val = a[left];
    else {//���·ֲ潨���ڵ�
        build(left, tree[root].mid, 2 * root);
        build(tree[root].mid + 1, right, 2 * root + 1);
        tree[root].val = max(tree[2 * root].val, tree[2 * root + 1].val);//���ݵõ���ǰ�ڵ�����ֵ
    }
}

void modify(int index, int num, int root)//�������
{
    if (tree[root].left == tree[root].right && index == tree[root].left)
        tree[root].val = num;
    else {
        if(index <= tree[root].mid)
            modify(index, num, 2 * root);
        else
            modify(index, num, 2 * root + 1);
        tree[root].val = max(tree[2 * root].val, tree[2 * root + 1].val);//���ݵõ���ǰ�ڵ�����ֵ
    }
}

int query(int left, int right, int root)//�����ѯ
{
    if (right < tree[root].left || tree[root].right < left)
        return -INF;
    if (left <= tree[root].left && tree[root].right <= right)
        return tree[root].val;
    int ans = max(query(left, right, 2 * root), query(left, right, 2 * root + 1));
    return ans;
}


//�߶�����������¡������ѯ��
const int MAXN = 5e5 + 5;

struct segment {
    int left, right, mid;
    long long sum;//�����
    int mark;//������
};

int n;
int a[MAXN];
segment tree[MAXN << 2];//�߶���ĿӦ��ΪҶ�ӽڵ������ı�

void build(int left, int right, int root)
{
    tree[root].left = left;
    tree[root].right = right;
    tree[root].mid = (left + right) >> 1;
    tree[root].mark = 0;//�����ǳ�ʼ��
    if(left == right)
        tree[root].sum = a[left];
    else{
        build(left, tree[root].mid,root << 1);
        build(tree[root].mid + 1, right, root << 1 | 1);
        tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
    }
}

void push_down(int root)//�������
{
    if (tree[root].mark != 0) {
        tree[root << 1].sum += (long long)tree[root].mark * (tree[root << 1].right - tree[root << 1].left + 1);
        tree[root << 1 | 1].sum += (long long)tree[root].mark * (tree[root << 1 | 1].right - tree[root << 1 | 1].left + 1);
        tree[root << 1].mark += tree[root].mark;
        tree[root << 1 | 1].mark += tree[root].mark;
        tree[root].mark = 0;
    }
}

void modify(int left, int right, int num, int root)//��left��right�������������num
{
    if (right < tree[root].left || tree[root].right < left)
        return;
    if (left <= tree[root].left && tree[root].right <= right) {
        tree[root].sum += (long long)num * (tree[root].right - tree[root].left + 1);//����ͣ��������䶼Ҫ��
        tree[root].mark += num;//�п��ܶ�ν��������޸ģ�����������
        return;
    }
    push_down(root);//�ݹ������ӽڵ�֮ǰ�ȱ������
    modify(left, right, num, root << 1);
    modify(left, right, num, root << 1 | 1);
    tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;//�޸����Ժ����
}

long long query(int left, int right, int root)
{
    if(right < tree[root].left || tree[root].right < left)
        return 0;
    if(left <= tree[root].left && tree[root].right <= right)
        return tree[root].sum;
    push_down(root);//�ݹ������ӽڵ�֮ǰ�ȱ������
    return query(left, right, root << 1) + query(left, right, root << 1 | 1);
}


//�߶���������ϲ���
const int MAXN = 50005;

struct segment {
    int left, right, mid;
    int lx, rx, tx;//��˿�ʼ����������䳤��lx���Ҷ˿�ʼ����������䳤��rx�����������ڵ���������䳤��tx
    int mark;//�����ǣ�ȫ����1��ȫ����0��һ�������-1
};

int n;
segment tree[MAXN << 2];

void build(int left, int right, int root)
{
    tree[root].left = left;
    tree[root].right = right;
    tree[root].mid = (left + right) >> 1;
    tree[root].lx = tree[root].rx = tree[root].tx = right - left + 1;
    tree[root].mark = -1;//��ʼ��Ϊһ�����
    if (left == right) return;
    build(left, tree[root].mid,root << 1);
    build(tree[root].mid + 1, right, root << 1 | 1);
}

void push_down(int root)//�������
{
    if (tree[root].mark != -1) {
        if (tree[root].mark == 1) {//������ȫ��
            tree[root << 1].lx = tree[root << 1].rx = tree[root << 1].tx = 0;
            tree[root << 1 | 1].lx = tree[root << 1 | 1].rx = tree[root << 1 | 1].tx = 0;
        }
        else {//������ȫ��
            tree[root << 1].lx = tree[root << 1].rx = tree[root << 1].tx = tree[root << 1].right - tree[root << 1].left + 1;
            tree[root << 1 | 1].lx = tree[root << 1 | 1].rx = tree[root << 1 | 1].tx = tree[root << 1 | 1].right - tree[root << 1 | 1].left + 1;
        }
        tree[root << 1].mark = tree[root].mark;
        tree[root << 1 | 1].mark = tree[root].mark;
        tree[root].mark = -1;
    }
}

void modify(int left, int right, int val, int root)//��left��right��������Ϊval��valΪ1ȫ������valΪ0ȫ���
{
    if (left <= tree[root].left && tree[root].right <= right) {//��С����Ϊ��������ķָ�����
        if (val == 1)
            tree[root].lx = tree[root].rx = tree[root].tx = 0;
        else
            tree[root].lx = tree[root].rx = tree[root].tx = tree[root].right - tree[root].left + 1;
        tree[root].mark = val;
        return;
    }
    push_down(root);//�ݹ������ӽڵ�֮ǰ�ȱ������
    if (left <= tree[root].mid)
        modify(left, right, val, root << 1);
    if (right > tree[root].mid)
        modify(left, right, val, root << 1 | 1);
    tree[root].lx = tree[root << 1].lx;//���¶����޸ĺ�Ļ��ݣ����¸��ڵ�ĸ�����
    if (tree[root << 1].lx == tree[root << 1].right - tree[root << 1].left + 1)//��ڵ����ζ�����������������ҽڵ������
        tree[root].lx += tree[root << 1 | 1].lx;
    tree[root].rx = tree[root << 1 | 1].rx;
    if (tree[root << 1 | 1].rx == tree[root << 1 | 1].right - tree[root << 1| 1].left + 1)//�ҽڵ����ζ������������������ڵ���Ұ��
        tree[root].rx += tree[root << 1].rx;
    tree[root].tx = max(max(tree[root << 1].tx, tree[root << 1 | 1].tx), max(tree[root].lx,tree[root].rx));
    tree[root].tx = max(tree[root].tx, tree[root << 1].rx + tree[root << 1 | 1].lx);
}

int query(int num, int root)//ѯ�ʳ���Ϊnum���������������˵�
{
    push_down(root);//�ݹ������ӽڵ�֮ǰ�ȱ������
    if (tree[root].tx < num)//�������䲻���ڣ��򷵻�0
        return 0;
    if (tree[root].left == tree[root].right)//������
        return tree[root].left;
    if (tree[root << 1].tx >= num)//��ڵ���������������
        return query(num,root << 1);
    if (tree[root << 1].rx + tree[root << 1 | 1].lx >= num)//��ڵ���Ұ�μ����ҽڵ������������������
        return tree[root << 1].right - tree[root << 1].rx + 1;
    if (tree[root << 1 | 1].tx >= num)//�ҽڵ���������������
        return query(num, root << 1 | 1);
}


//�ɳ־û��߶������������������KС����
const int MAXN = 1e5 + 5;

struct segment {
    int l, r, mid;
    int data, lson, rson;
};

int n, cnt;//cntΪ�ڵ��ʶ
int a[MAXN], b[MAXN], root[MAXN];//a����ԭ���飬b������ɢ��������飬rootΪ��ͬʱ�̵��߶������ڵ�
segment seg[MAXN * 21];//�ڴ��

void build(int left, int right, int &rt)
{
    rt = ++cnt;
    seg[rt].l = left;
    seg[rt].r = right;
    seg[rt].mid = (left + right) >> 1;
    seg[rt].data = 0;
    if (left == right) return;
    build(left, seg[rt].mid, seg[rt].lson);
    build(seg[rt].mid + 1, right, seg[rt].rson);
}

void modify(int pos, int num, int pre, int &now)//��seg[pre]Ϊԭ�͹����seg[now]
{
    now = ++cnt;
    seg[now] = seg[pre];
    if (seg[now].l == seg[now].r) {
        seg[now].data += num;
        return;
    }
    if (pos <= seg[now].mid)
        modify(pos, num, seg[pre].lson, seg[now].lson);
    else
        modify(pos, num, seg[pre].rson, seg[now].rson);
    seg[now].data = seg[seg[now].lson].data + seg[seg[now].rson].data;
}

int query(int x, int y, int k)
{
    if (seg[y].l == seg[y].r) return b[seg[y].mid];
    int cnt = seg[seg[y].lson].data - seg[seg[x].lson].data;
    if (k <= cnt)//kС�ڵ���cnt����飬�����Ҳ�
        return query(seg[x].lson, seg[y].lson, k);
    else
        return query(seg[x].rson, seg[y].rson, k - cnt);
}


//�ɳ־û��߶����������������䲻ͬ�����ĸ�����
const int MAXN = 3e4 + 5;

struct segment {
    int lson, rson, sum;
};

int n, q, cnt;
int a[MAXN], root[MAXN], done[(int)1e6 + 5];
segment tree[MAXN * 21];

void push_up(int rt)
{
    tree[rt].sum = tree[tree[rt].lson].sum + tree[tree[rt].rson].sum;
}

void build(int l, int r, int &rt)
{
    rt = ++cnt;
    tree[rt].sum = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(l, mid, tree[rt].lson);
    build(mid + 1, r, tree[rt].rson);
}

void modify(int pos, int num, int l, int r, int pre, int &rt)
{
    rt = ++cnt;
    tree[rt] = tree[pre];
    if (l == r) {
        tree[rt].sum += num;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(pos, num, l, mid, tree[pre].lson, tree[rt].lson);
    if (pos >= mid + 1) modify(pos, num, mid + 1, r, tree[pre].rson, tree[rt].rson);
    push_up(rt);
}

int query(int pos, int l, int r, int rt)//����query(l, 1, n, root[r])��������[l, r]�в�ͬ�����ĸ���
{
    if (l == r) return tree[rt].sum;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return query(pos, l, mid, tree[rt].lson) + tree[tree[rt].rson].sum;
    else
        return query(pos, mid + 1, r, tree[rt].rson);
}


//Splay��
const int MAXN = 2e5 + 5, INF = 0x3fffffff;

int n, m, root, mem;
int val[MAXN], fa[MAXN], sz[MAXN], mn[MAXN], reverse_mark[MAXN], add_mark[MAXN];
int son[MAXN][2];
stack<int> st;//�ڴ��

void push_down(int x)//�����ѹ��ʵ�ʸ������Ǹ���ͬʱ����
{
    if (add_mark[x]) {
        if (son[x][0]) add_mark[son[x][0]] += add_mark[x], val[son[x][0]] += add_mark[x], mn[son[x][0]] += add_mark[x];
        if (son[x][1]) add_mark[son[x][1]] += add_mark[x], val[son[x][1]] += add_mark[x], mn[son[x][1]] += add_mark[x];
        add_mark[x] = 0;
    }
    if (reverse_mark[x]) {
        if (son[x][0]) reverse_mark[son[x][0]] ^= 1, swap(son[son[x][0]][0], son[son[x][0]][1]);
        if (son[x][1]) reverse_mark[son[x][1]] ^= 1, swap(son[son[x][1]][0], son[son[x][1]][1]);
        reverse_mark[x] = 0;
    }
}

void update(int x)
{
    sz[x] = 1;
    mn[x] = val[x];
    if (son[x][0]) sz[x] += sz[son[x][0]], mn[x] = min(mn[x], mn[son[x][0]]);
    if (son[x][1]) sz[x] += sz[son[x][1]], mn[x] = min(mn[x], mn[son[x][1]]);
}  

void rotate(int x, int dir)//dirΪ0��������1������
{
    int y = fa[x], z = fa[y];
    son[y][!dir] = son[x][dir]; if (son[x][dir]) fa[son[x][dir]] = y;
    if (z) son[z][son[z][1] == y] = x; fa[x] = z;
    son[x][dir] = y; fa[y] = x;
    update(y);//���ڵ���Ų��Ҫ����
    if (root == y) root = x;
}

void splay(int x, int f)
{
    push_down(x);
    while (fa[x] != f) {
        if (fa[fa[x]] == f)
            if (son[fa[x]][0] == x) rotate(x, 1); else rotate(x, 0);
        else {
            int y = fa[x], z = fa[y];
            if (son[z][0] == y)
                if (son[y][0] == x) rotate(y, 1), rotate(x, 1); else rotate(x, 0), rotate(x, 1);
            else
                if (son[y][1] == x) rotate(y, 0), rotate(x, 0); else rotate(x, 1), rotate(x, 0);
        }
    }
    update(x);//�Լ����Ҫ����
}

void select(int k, int f)//�����е�k����splay��f����
{
    k++;//��Ϊ������λ����һ������ռλ�����Ա������ƽ��
    int now = root, tmp;
    while (true) {
        push_down(now);
        if (son[now][0]) tmp = sz[son[now][0]]; else tmp = 0;
        if (k == tmp + 1) break;
        if (k <= tmp)
            now = son[now][0];
        else {
            now = son[now][1];
            k -= (tmp + 1);
        }
    }
    splay(now, f);
}

void select_segment(int l, int r)//������ȡ����[l, r]�ᵽ�������Ҷ��ӵ�������
{  
    select(l - 1, 0);
    select(r + 1, root);
}

void insert(int x, int num)//�������������Ϊx����СΪnum������x���������൱������֮ǰ��num
{
    select_segment(x, x - 1);
    int now;
    if (st.empty())
        now = ++mem;
    else {
        now = st.top();
        st.pop();
    }
    val[now] = num;
    sz[now] = 1;
    mn[now] = num;
    fa[now] = son[root][1];
    son[now][0] = son[now][1] = 0;
    add_mark[now] = reverse_mark[now] = 0;
    splay(now, 0);//һ��Ҫsplay����Ȼ��ϵ�ͳ����ˣ���ͬ
}

void add(int l, int r, int num)//�����һ����
{
    select_segment(l, r);
    int now = son[son[root][1]][0];
    add_mark[now] += num;
    val[now] += num;
    mn[now] += num
    splay(now, 0);
}

void reverse(int l, int r)//���䷴ת
{
    select_segment(l, r);
    int now = son[son[root][1]][0];
    reverse_mark[now] ^= 1;
    swap(son[now][0], son[now][1]);
    splay(now, 0);
}

void revolve(int l, int r, int t)//��������
{
    t = t % (r - l + 1);
    if (t < 0) t = r - l + 1 + t;
    if (!t) return;
    select_segment(l, r);
    select(r - t, son[root][1]);
    int now = son[son[root][1]][0], right = son[now][1];
    son[now][1] = 0;
    select(l, son[root][1]);
    now = son[son[root][1]][0];
    son[now][0] = right; fa[right] = now;
    splay(now, 0);
}

void del(int x)//ɾ�����Ϊx����
{
    select_segment(x, x);
    int now = son[root][1];
    st.push(son[now][0]);
    son[now][0] = 0;
    splay(now, 0);
}

long long get_min(int l, int r)//��ȡ����������Сֵ
{
    select_segment(l, r);
    int now = son[son[root][1]][0];
    return mn[now];
}

void init()//��ʼ����Ϊһͷһβ��ȷ���κ�����[a, b]����ͨ��splay(a - 1, 0)�� splay(b + 1, root)����ȡ��INF��Ϊ��ֹ����min
{
    mem = 0;
    root = ++mem; fa[root] = 0;
    son[root][1] = ++mem; fa[son[root][1]] = root;
    son[root][0] = son[son[root][1]][0] = son[son[root][1]][1] = 0;
    add_mark[root] = add_mark[son[root][1]] = 0;
    reverse_mark[root] = reverse_mark[son[root][1]] = 0;
    val[root] = val[son[root][1]] = INF;
    update(son[root][1]); update(root);
}


//KMP�㷨�����ص�һ��ƥ���λ�ã�
char s[MAXN], t[MAXN];
int nextval[MAXN];

void getnext(char *t)
{
    memset(nextval, 0, sizeof(nextval));
    nextval[0] = -1;
    int len = strlen(t), k = -1, j = 0;
    while (j < len) {
        if (k == -1 || t[k] == t[j]) {
            k++; j++;
            int w = k;
            while (w != -1 && t[w] == t[j]) w = nextval[w];//�Ż���������һ���Ƚϵ��ַ���ͬ
            nextval[j] = w;
        }
        else
            k = nextval[k];
    }
}

int kmp(char *s, char *t)
{
    int slen = strlen(s), tlen = strlen(t);
    int i = 0, j = 0;
    while (i < slen && j < tlen) {
        if (j == -1 || s[i] == t[j]) {
            i++; j++;
        }
        else
            j = nextval[j];
    }
    if (j == tlen)
        return i - j;//����t��sƥ��ĵ�һ���ַ���λ��
    else
        return -1;//�޷�ƥ��
}


//KMP�㷨����t��s�ڵ�����ƥ��λ�ã�
string s, t;
vector<int> pos;
int next_pos[MAXN];

void kmp(string s, string t)
{
	memset(next_pos, 0, sizeof(next_pos));
	int slen = s.length(), tlen = t.length();
	for (int i = 1; i < tlen; i++) {
		int j = i;
		while (j) {
			j = next_pos[j];
			if (t[j] == t[i]) {
				next_pos[i + 1] = j + 1;
				break;
			}
		}
	}
	for (int i = 0, j = 0; i < slen; i++) {
		if (j < tlen && s[i] == t[j])
			j++;
		else {
			while (j) {
				j = next_pos[j];
				if (s[i] == t[j]) {
					j++;
					break;
				}
			}
		}
		if (j == tlen) pos.push_back(i - tlen + 1);
	}
}


//Manacher�㷨
const int MAXN = 110005;

char ss[MAXN], s[MAXN << 1];//ԭ��ss������s��ע�ⳤ�ȿ�Ϊԭ������
int p[MAXN << 1];

int manacher(char *str)
{
	int len = strlen(str), j = 2;
	s[0] = '$'; s[1] = '#';
	for (int i = 0; i < len; i++) s[j++] = str[i], s[j++] = '#';
	s[j] = '\0';
	int ans = 0, id = 0;///��ǰ��Զ���Ĵ�������id
	p[0] = 0;
	for (int i = 1; i < j; i++) {
		if (i < id + p[id])
			p[i] = min(p[2 * id - i], id + p[id] - i);
		else
			p[i] = 1;
		while (s[i - p[i]] == s[i + p[i]]) p[i]++;
		if (id + p[id] < i + p[i]) id = i;
		ans = max(ans, p[i] - 1);
	}
	return ans;
}


//Trie������ѯĳ�����ʵ����Ψһǰ׺��
const int SIZE = 26;//26����/Сд��ĸ

struct trie {
    int cnt;
    trie *child[SIZE];
};

trie *root;//���ڵ㣬��Ҫ��create

trie *create()
{
    trie *tmp = (trie *)malloc(sizeof(trie));
    memset(tmp->child, NULL, sizeof(tmp->child));
    tmp->cnt = 0;
    return tmp;
}

void insert(char *s)//�����ַ���
{
    trie *p = root;
    while (p != NULL && *s != '\0') {
        int id = *s - 'a';
        if (p->child[id] == NULL)
            p->child[id] = create();
        p->child[id]->cnt++;
        p = p->child[id];
        s++;
    }
}

int findprefix(char *s)//Ѱ�ҿ���Ψһ�����ʵ����ǰ׺
{
    trie *p = root;
    int i = 0;
    while (p != NULL && p->cnt != 1 && p->child[s[i] - 'a'] != NULL && s[i] != '\0') {
        p = p->child[s[i] - 'a'];
        if (p->cnt == 1) return i;//���ҵ�ǰ׺�򷵻�ǰ׺�±�
        i++;
    }
    return -1;//���Ҳ����򷵻�-1
}

void del(trie *root)//�ͷ��ڴ�
{
    for (int i = 0; i < SIZE; i++)
        if (root->child[i] != NULL)
            del(root->child[i]);
    free(root);
}


//�ַ�����ϣ����ѡģ��19260817��122420729��163227661��217636919��386910137��515880193��
//ʮ����������3221225473��4294967291
typedef long long ll;

const int MAXN = 1e6 + 5, S = 131, MOD = 1e9 + 7;

int len;
char s[MAXN];
ll p[MAXN], inv[MAXN], sum[MAXN];

ll qpow(ll a, ll b, ll c)
{
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return ans;
}

void init_hash()
{
    p[0] = 1;
    for (int i = 1; i < MAXN; i++) p[i] = p[i - 1] * S % MOD;
    inv[MAXN - 1] = qpow(p[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 2; i >= 0; i--) inv[i] = inv[i + 1] * S % MOD;
    sum[0] = 0;
    for (int i = 1; i <= len; i++) sum[i] = (sum[i - 1] + (s[i] - 'a' + 1) * p[i - 1]) % MOD;
}

ll get_hash(int l, int r)
{
    return ((sum[r] - sum[l - 1]) * inv[l - 1] % MOD + MOD) % MOD;
}

//˫��ϣ
typedef long long ll;
typedef pair<ll, ll> pll;
#define x first
#define y second

const int MAXN = 1e5 + 5;
const ll S1 = 15485867, S2 = 32452843, MOD1 = 1e9 + 21, MOD2 = 1e9 + 9;
const pll S = pll(S1, S2), MOD = pll(MOD1, MOD2);

ostream& operator<<(ostream &os, pll h) {return os << "(" << h.x << ", " << h.y << ")";}

pll operator+(const pll a, const ll b) {return pll(a.x + b, a.y + b);}
pll operator-(const pll a, const ll b) {return pll(a.x - b, a.y - b);}
pll operator*(const pll a, const ll b) {return pll(a.x * b, a.y * b);}
pll operator+(const pll a, const pll b) {return pll(a.x + b.x, a.y + b.y);}
pll operator-(const pll a, const pll b) {return pll(a.x - b.x, a.y - b.y);}
pll operator*(const pll a, const pll b) {return pll(a.x * b.x, a.y * b.y);}
pll operator%(const pll a, const pll b) {return pll(a.x % b.x, a.y % b.y);}

int n, m;
int a[11][MAXN], pos[11][MAXN];
pll p[MAXN], inv[MAXN];
pll sum[11][MAXN];

pll qpow(pll a, pll b, pll c)
{
    ll ansx = 1, ansy = 1;
    while (b.x) {
        if (b.x & 1) ansx = ansx * a.x % c.x;
        a.x = a.x * a.x % c.x;
        b.x >>= 1;
    }
    while (b.y) {
        if (b.y & 1) ansy = ansy * a.y % c.y;
        a.y = a.y * a.y % c.y;
        b.y >>= 1;
    }
    return pll(ansx, ansy);
}

void init_hash()
{
    p[0] = pll(1, 1);
    for (int i = 1; i < MAXN; i++) p[i] = p[i - 1] * S % MOD;
    inv[MAXN - 1] = qpow(p[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 2; i >= 0; i--) inv[i] = inv[i + 1] * S % MOD;
    for (int i = 1; i <= m; i++) {
        sum[i][0] = pll(0, 0);
        for (int j = 1; j <= n; j++) sum[i][j] = (sum[i][j - 1] + p[j - 1] * a[i][j] % MOD) % MOD;
    }
}

pll get_hash(int i, int l, int r)
{
    return ((sum[i][r] - sum[i][l - 1]) * inv[l - 1] % MOD + MOD) % MOD;
}


//������׳˺���Ӧ�ĳ˷���Ԫ����1��
factorial[0] = 1;
for (int i = 1; i < MAXN; i++) factorial[i] = factorial[i - 1] * i % MOD;
inverse[MAXN - 1] = qpow(factorial[MAXN - 1], MOD - 2) % MOD;//����С����
for (int i = MAXN - 2; i >= 0; i--) inverse[i] = inverse[i + 1] * (i + 1) % MOD;



//������׳˺���Ӧ�ĳ˷���Ԫ����2��
factorial[0] = factorial[1] = 1; inverse[0] = inverse[1] = 1;
for (int i = 2; i < MAXN; i++) {//��2��ʼ
    factorial[i] = factorial[i - 1] * i % MOD;
    inverse[i] = (MOD - MOD / i) * inverse[MOD % i] % MOD;
}
for (int i = 2; i < MAXN; i++) inverse[i] = inverse[i - 1] * inverse[i] % MOD;



//���������������⣩
const int MAXN = 1005, MOD = 1e9 + 7;

int C[MAXN][MAXN];

void init()
{
    C[0][0] = 1; C[0][1] = 0;
    for (int i = 1; i <= 1000; i++){
        C[i][0] = 1; C[i][i+1] = 0;
        for (int j = 1; j<= i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
}



//���������������⣩
long long comb(long long n, long long m)
{
    if (n < m) return 0;
    if (n - m < m) m = n - m;
    long long numerator = 1, denominator = 1;
    for (long long i = 0; i < m; i++) {
        numerator = numerator * (n - i) % MOD;
        denominator = denominator * (i + 1) % MOD;
    }
    return numerator * qpow(denominator, MOD - 2) % MOD;
}



//���������Ԥ������⣩
long long comb(long long n, long long m)
{
    if (n < m) return 0;
    if (n - m < m) m = n - m;
    return factorial[n] * inverse[n - m] % MOD * inverse[m] % MOD;
}



//����������ȡģ��Lucas����
const long long MOD = 1e9 + 7;

long long qpow(long long a, long long b)
{
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % MOD;//��Ϊ�����󣬼��˿��ٳ˷�������
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}


long long lucas(long long n, long long m)
{
    if (m == 0) return 1;
    return comb(n % MOD, m % MOD) * lucas(n / MOD, m / MOD) % MOD;
}


//���㼸��ͨ��ģ��
const double EPS = 1e-8;

int sgn(double x)
{
	if (fabs(x) < EPS) return 0;
	return (x > 0 ? 1 : -1);
}


//�㡢������
struct point {
	double x, y;

	point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	
	bool operator<(const point &another) const
	{
		return (x < another.x) || (x == another.x && y < another.y);
	}

	bool operator==(const point &another) const
	{
		return sgn(x - another.x) == 0 && sgn(y - another.y) == 0;
	}
};

typedef point vec;//�����ǵ�ı���

vec operator+(vec a, vec b)
{
	return vec(a.x + b.x, a.y + b.y);
}

vec operator-(point a, point b)
{
	return vec(a.x - b.x, a.y - b.y);
}

vec operator*(vec a, double p)
{
	return vec(a.x * p, a.y * p);
}

vec operator/(vec a, double p)
{
	return vec(a.x / p, a.x / p);
}

double dot(vec a, vec b)
{
	return a.x * b.x + a.y * b.y;
}

double det(vec a, vec b)
{
	return a.x * b.y - a.y * b.x;
}

//������ģ
double length(vec a)
{
	return sqrt(dot(a, a));
}

//�����ķ�����
vec normal(vec a)
{
	double len = length(a);
	return vec(-a.y / len, a.x / len);
}

//�������ļн�
double angle(vec a, vec b)
{
	return acos(dot(a, b) / length(a) / length(b));
}

//��������ʱ����תһ������
vec rotate(vec a, double rad)
{
	return vec(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + cos(rad));
}


//ֱ�ߡ��߶���
struct line {
	point s, e;

	line() {}
	line(point _s, point _e) : s(_s), e(_e) {}
};

//�жϵ��Ƿ���ֱ����
bool ison_point_line(point p, line l)
{
	return sgn(det(p - l.s, p - l.e)) == 0;
}

//ֱ����ֱ�ߵĽ���
pair<int, point> inter_line_line(line a, line b)
{
	point res = a.s;
	vec u = a.s - b.s, v= a.e - a.s, w = b.e - b.s;
	if (sgn(det(v, w)) == 0) {
		if (sgn(det(u, v)) == 0) return make_pair(0, res);//0�����غ�
		return make_pair(1, res);//1����ƽ��
	}
	double t = det(w, u) / det(v, w);
	res = res + v * t;
	return make_pair(2, res);//2�����ཻ�����ؽ���
}

//�㵽ֱ�ߵ�ͶӰ
point proj_point_line(point p, line l)
{
	vec v = l.e - l.s;
	return l.s + v * (dot(v, p - l.s) / dot(v, v));
}

//�㵽ֱ�ߵľ���
double dist_point_line(point p, line l)
{
	vec v1 = l.e - l.s, v2 = p - l.s;
	return fabs(det(v1, v2) / length(v1));
}

//�жϵ��Ƿ����߶��ϣ��ڶ˵�Ҳ�㣩
bool ison_point_seg(point p, line l)
{
	return sgn(det(p - l.s, p - l.e)) == 0 && sgn(dot(p - l.s, p - l.e)) <= 0;
}

//�㵽�߶εľ���
double dist_point_seg(point p, line l)
{
	vec v1 = l.e - l.s, v2 = p - l.s, v3 = p - l.e;
	if (sgn(dot(v1, v2)) < 0) return length(v2);
	if (sgn(dot(v1, v3)) > 0) return length(v3);
	return fabs(det(v1, v2) / length(v1));
}

//�߶ε��߶εľ���
double dist_seg_seg(line seg1, line seg2)
{
	double d1 = min(dist_point_seg(seg1.s, seg2), dist_point_seg(seg1.e, seg2));
	double d2 = min(dist_point_seg(seg2.s, seg1), dist_point_seg(seg2.e, seg1));
	return min(d1, d2);
}

//�ж����߶��Ƿ��ཻ
bool isinter_seg_seg(line l1, line l2)
{
	return (max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) && max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x)
		&& max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) && max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y))//�ų�ʵ��
		&& (sgn(det(l1.e - l1.s, l2.s - l1.s) * det(l1.e - l1.s, l2.e - l1.s)) <= 0
		&& sgn(det(l2.e - l2.s, l1.s - l2.s) * det(l2.e - l2.s, l1.e - l2.s)) <= 0);//��������
}

//�ж��߶�l1��ֱ��l2�Ƿ��ཻ��������ȷ��ֱ�߲���һ����
bool isinter_seg_line(line l1, line l2)
{
	return sgn(det(l2.e - l2.s, l1.s - l2.s)) * sgn(det(l2.e - l2.s, l1.e - l2.s)) <= 0;
}


//��������
vector<point> p;

bool cmp(const point &a, const point &b)
{
	double crs = det(a - p[0], b - p[0]); 
	if (sgn(crs) == 0)
		return sgn(length(a - p[0]) - length(b - p[0])) < 0;
	return sgn(crs) > 0;
}

void sort_by_angle()
{
	int pos = 0;
	for (int i = 1; i < p.size(); i++)
		if (p[i].y < p[pos].y || (p[i].y == p[pos].y && p[i].x < p[pos].x)) pos = i;
	swap(p[pos], p[0]);
	sort(p.begin(), p.end(), cmp);
}


//����Σ�͹����(Ĭ��Ϊ��ʱ��˳��)
struct polygon {
	vector<point> p;
	
	polygon() {}
	polygon(vector<point> v)
	{
		p = v;
	}

	//��Ͷ���εĹ�ϵ������0�������棬1�������棬2���ڱ���
	int relation_point(point t)
	{
		int cnt = 0;
		for (int i = 0; i < p.size(); i++) {
			if (ison_point_seg(t, line(p[i], p[(i + 1) % p.size()]))) return 2;
			int k = sgn(det(p[(i + 1) % p.size()] - p[i], t - p[i]));
			int d1 = sgn(p[i].y - t.y), d2 = sgn(p[(i + 1) % p.size()].y - t.y);
			if (k > 0 && d1 <= 0 && d2 > 0) cnt++;
			if (k < 0 && d2 <= 0 && d1 > 0) cnt--;
		}
		return cnt != 0;
	}

	//���ܳ�
	double perimeter()
	{
		double ans = length(p[0] - p.back());
		for (int i = 0; i < p.size() - 1; i++)
			ans += length(p[i + 1] - p[i]);
		return ans;
	}

	//����������ǰ������ǧ��Ҫ��������
	double area()
	{
		double ans = 0;
		for (int i = 1; i < p.size() - 1; i++)
			ans += det(p[i] - p[0], p[i + 1] - p[0]);
		return fabs(ans / 2);
	}
};

//��͹����Andrew�㷨��
polygon convex_hull(vector<point> all)
{
	polygon ans;
	vector<point> &v = ans.p;
	sort(all.begin(), all.end());//ˮƽ����
	for (int i = 0; i < all.size(); i++) {
		while (v.size() > 1 && sgn(det(v.back() - v[v.size() - 2], all[i] - v[v.size() - 2])) <= 0)
			v.pop_back();
		v.push_back(all[i]);
	}
	int k = v.size();
	for (int i = all.size() - 2; i >= 0; i--) {
		while (v.size() > k && sgn(det(v.back() - v[v.size() - 2], all[i] - v[v.size() - 2])) <= 0)
			v.pop_back();
		v.push_back(all[i]);
	}
	if (all.size() > 1) v.pop_back();
	return ans;
}

//��͹����ֱ�����ȣ���ת�����㷨��
double rotating_calipers(polygon ch)
{
	double ans = 0;
	int cur = 1, sz = ch.p.size();
	for (int i = 0; i < sz; i++) {
		vec v = ch.p[i] - ch.p[(i + 1) % sz];
		while (sgn(det(v, ch.p[(cur + 1) % sz] - ch.p[cur])) < 0)
			cur = (cur + 1) % sz;
		ans = max(ans, max(length(ch.p[i] - ch.p[cur]), length(ch.p[(i + 1) % sz] - ch.p[(cur + 1) % sz])));
	}
	return ans;
}

//��͹����μ����С���루��ת�����㷨��
double rotating_calipers(polygon p, polygon q)
{
	double ans = INF;
	int sp = 0, sq = 0, psz = p.p.size(), qsz = q.p.size();
	for (int i = 1; i < psz; i++)
		if (sgn(p.p[i].y - p.p[sp].y) < 0) sp = i;
	for (int i = 1; i < qsz; i++)
		if (sgn(q.p[i].y - q.p[sq].y) > 0) sq = i;
	for (int i = 0; i < psz; i++) {
		while (sgn(det(p.p[(sp + 1) % psz] - p.p[sp], q.p[sq] - q.p[(sq + 1) % qsz])) < 0)
			sq = (sq + 1) % qsz;
		if (sgn(det(p.p[(sp + 1) % psz] - p.p[sp], q.p[sq] - q.p[(sq + 1) % qsz])) == 0)
			ans = min(ans, dist_seg_seg(line(p.p[sp], p.p[(sp + 1) % psz]), line(q.p[sq], q.p[(sq + 1) % qsz])));
		else
			ans = min(ans, dist_point_seg(q.p[sq], line(p.p[sp], p.p[(sp + 1) % psz])));
		sp = (sp + 1) % psz;
	}
	return ans;
}

//��͹����Grahamɨ�跨�������ã�
const double EPS = 1e-8;

struct point {
    double x, y;

	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

int n, m;
vector<point> all;

int sgn(double x)
{
    if (fabs(x) < EPS) return 0;
    if (x > 0)
        return 1;
    else
        return -1;
}

double det(const point &a1, const  point &a2, const point &b1, const point &b2)
{
    return ((a2.x - a1.x) * (b2.y - b1.y) - (a2.y - a1.y) * (b2.x - b1.x));
}

double dist(const point &p1, const point &p2)
{
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

bool cmp(const point &a, const point &b)
{
	if (sgn(det(all[0], a, all[0], b)) == 0)
		return sgn(dist(all[0], a) - dist(all[0], b)) < 0;
	else
		return sgn(det(all[0], a, all[0], b)) > 0;
}

vector<point> graham(vector<point> &o)
{
	double min_y = o[0].y, min_x = o[0].x;
	vector<point> ans;
	int index = 0;
	for (int i = 1; i < o.size(); i++)
		if (sgn(o[i].y - min_y) < 0 || (sgn(o[i].y - min_y) == 0 && sgn(o[i].x - min_x) < 0)) {
			min_y = o[i].y;
			min_x = o[i].x;
			index = i;
		}
	swap(o[0], o[index]);
	sort(o.begin() + 1, o.end(), cmp);//��������
	ans.push_back(o[0]); ans.push_back(o[1]);
	for (int i = 2; i < o.size(); i++) {
		while (ans.size() >= 2 && sgn(det(ans.back(), o[i], ans.back(), ans[ans.size() - 2])) <= 0)//���������ߵ�
			ans.pop_back();
		ans.push_back(o[i]);
	}
	return ans;
}


//ƽ����С����Ծ���
const double EPS = 1e17;

vector<point> all;

bool cmp_y(const point a, const point b)
{
	return a.y < b.y;
}

double nearest_dist(int left, int right)
{
	if (left == right) return INF;
	if (left + 1 == right) return length(all[right] - all[left]);
	int mid = (left + right) >> 1;
	double d1 = nearest_dist(left, mid), d2 = nearest_dist(mid + 1, right);
	double d = min(d1, d2);
	vector<point> tmp;
	for (int i = left; i <= right; i++)
		if (sgn(d - fabs(all[i].x - all[mid].x)) >= 0) tmp.push_back(all[i]);
	sort(tmp.begin(), tmp.end(), cmp_y);
	for (int i = 0; i < tmp.size(); i++)
		for (int j = i + 1; j < tmp.size()&& tmp[j].y - tmp[i].y < d; j++) {
			if (tmp[j].y - tmp[i].y > d) break;
			d = min(d, length(tmp[j] - tmp[i]));
		}
	return d;
}


//�����ʷ�
int tot;
int head[MAXN], in[MAXN], id[MAXN], fa[MAXN], top[MAXN], sz[MAXN], max_son[MAXN], deep[MAXN];
edge e[MAXN];//��ʽǰ����

void dfs_1(int u, int father, int depth)
{
	deep[u] = depth;
	fa[u] = father; max_son[u] = 0;//��ʼ���ض���
	sz[u] = 1;
	for (int i = head[u]; i != 0; i = e[i].next) {
		int v = e[i].to;
		if (v == fa[u]) continue;
		dfs_1(v, u, depth + 1);
		sz[u] += sz[v];
		if (sz[max_son[u]] < sz[v]) max_son[u] = v;
	}
}

void dfs_2(int u, int tp)
{

	in[u] = ++tot;//inΪdfs��ʱ���
	id[tot] = u;//idΪʱ�����Ӧ�ĵ���
	top[u] = tp;
	if (max_son[u] != 0) dfs_2(max_son[u], tp);//�ض�������
	for (int i = head[u]; i != 0; i = e[i].next) {
		int v = e[i].to;
		if (v == fa[u] || v == max_son[u]) continue;
		dfs_2(v, v);
	}
}


//�����㷨��LCA
int deep[MAXN];//�ڵ�����
int up[MAXN][18];//���Ƚڵ��ϡ���18��ζ����������ʱ������2��17�η���

void init()//Ӧ��dfsһ���ȡ���deep[i]�͸���up[i][0]�����
{
	for (int i = 1; i <= 17; i++)
		for (int j = 1; j <= n; j++)
			up[j][i] = up[up[j][i - 1]][i - 1];
}

int lca(int u, int v)
{
	if (deep[u] < deep[v]) swap(u, v);
	int diff = deep[u] - deep[v];
	for (int i = 17; i >= 0; i--)
		if (diff & (1 << i)) u = up[u][i];//����ʹ���㵽ͬһ�߶�
	if (u == v) return u;//���Ѿ�Ϊͬһ���㣬Ӧ��ʱ�˳�
	for (int i = 17; i >= 0; i--)
		if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];//�����ӽ�LCA
	return up[u][0];
}


//���Ի�
struct linear_basis {
    ll b[61];//����ֻ��61λ��Ҫ����͸�

    linear_basis()
    {
        memset(b, 0, sizeof(b));
    }

    void init()
    {
        memset(b, 0, sizeof(b));
    }

    bool insert(ll x)//�����Ի���ӳ�����
    {
        for (int i = 60; i >= 0; i--) {
            if (x >> i & 1) {
                if (!b[i]) {
                    b[i] = x;
                    break;
                }
                x ^= b[i];
            }
        }
        return x > 0;
    }

    ll get_max()//���Ի������ųɵ�������ֵ
    {
        ll ans = 0;
        for (int i = 60; i >= 0; i--)
            if ((ans ^ b[i]) > ans) ans ^= b[i];
        return ans;
    }

    ll get_min()//���Ի������ųɵ���С���ֵ
    {
        for (int i = 0; i <= 60; i++)
            if (b[i]) return b[i];
        return 0;
    }

    linear_basis& operator=(const linear_basis &another)
    {
        for (int i = 60; i >= 0; i--) b[i] = another.b[i];
        return *this;
    }

    linear_basis operator+(const linear_basis &another) const//�ϲ��������Ի�
    {
        linear_basis ans;
        for (int i = 60; i >= 0; i--) ans.b[i] = b[i];
        for (int i = 60; i >= 0; i--)
            if (another.b[i]) ans.insert(another.b[i]);
        return ans;
    }
};


//��׺���飨�����㷨�����Ӷ�O(NlogN)��
int n;
int s[MAXN], sa[MAXN], rk[MAXN], height[MAXN], c[MAXN], x[MAXN], y[MAXN];

void get_sa()
{
    int m = 255;
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[x[i] = s[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i >= 1; i--) sa[c[x[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int num = 0;
        for (int i = n - k + 1; i <= n; i++) y[++num] = i;
        for (int i = 1; i <= n; i++) if (sa[i] > k) y[++num] = sa[i] - k;
        for (int i = 1; i <= m; i++) c[i] = 0;
        for (int i = 1; i <= n; i++) c[x[i]]++;
        for (int i = 2; i <= m; i++) c[i] += c[i - 1];
        for (int i = n; i >= 1; i--) sa[c[x[y[i]]]--] = y[i], y[i] = 0;
        swap(x, y);
        x[sa[1]] = num = 1;
        for (int i = 2; i <= n; i++)
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++num;
        if (num == n) break;
        m = num;
    }
}

void get_height()
{
    for (int i = 1; i <= n; i++) rk[sa[i]] = i;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (rk[i] == 1) continue;
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (j + k <= n && i + k <= n && s[i + k] == s[j + k]) k++;
        height[rk[i]] = k;
    }
}
