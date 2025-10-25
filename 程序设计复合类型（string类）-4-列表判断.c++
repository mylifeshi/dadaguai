#include <iostream>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;
string a,b;
int t, lc, s[1000], n[1000], ans, l, zt, p, dh[1000], dy,sz;
size_t len;
int kg(int x) {
    if (x >= len)return 1;
    if (a[x] == ' ')return kg(x + 1);
    else {
        if (zt == 0 && (a[x] == '[' || a[x] == ']' || a[x] == '-' || a[x] == '+'))return 0;
        if (a[x] >= '0' && a[x] <= '9')return 0;
        else return x;
    }
}
int fh(int x) {
    if(x >= len)return 1;
    if (a[x] == ' ')return fh(x + 1);
    else {
        if (a[x] >= '0' && a[x] <= '9')return x;
        if (a[x] == '[' || a[x] == ']' || a[x] == '-' || a[x] == '+'||a[x]==',')return 0;
        return 0;
    }
}
int pd(int x) {
//    ans++;
//    if (ans > 100)return 0;
   // cout << ans << " " << x << " " << zt << " " << s[zt] << " " <<p <<" "<<dh[zt] << endl;
    if (x >= len)return 1;
    if (a[x] == '[' && (x == 0 || dh[zt] != 0 || p == 1)) {
  //      cout << "一个新的【】" << endl;
        zt++;
        p = 1;
        int k = pd(x + 1);
        if (k != 0) {
            while (k < len - 1) {
             //   s[zt] = 0;
    //          cout << "*" << endl;
                k = pd(k + 1);
                if (k == 1)return 1;
                if (k == 0)return 0;
            }
        }
        return k;
    }
    if (a[x] == ' ') {
        if (sz) {
            int g = kg(x);
            if (g == 0)return 0;
            else return pd(g);
        }
        else return pd(x + 1);
    }
    if (zt == 0)return 0;
    if (a[x] == ']') {
        p = 0;
        sz = 0;
        if (zt <= 0)return 0;
        zt--;
        s[zt]++;
        if (s[zt + 1] || (!s[zt + 1]) && !(dh[zt + 1])) {
            s[zt + 1] = 0;
            dh[zt + 1] = 0;
//          cout << "回去了" << endl;
            return x;
        }
        else return 0;
    }
    if (a[x] == '-'||a[x]=='+') {
        p = 0;
        if (a[x + 1] == ' ') {
            int g = fh(x + 1);
            if (g)return pd(g);
            else return 0;
        }
        else if(a[x + 1] < '0' || a[x + 1]>'9')return 0;
        if (zt <= 0)return 0;
        if (sz == 0) {
            return pd(x + 1);
        }
        else return 0;
    }
    if (a[x] >= '0' && a[x] <= '9') {
        if (zt <= 0)return 0;
        sz = 1;
        s[zt]++;
        p = 0;
  //      cout << '&' << endl;
        return pd(x + 1);
    }
    if (a[x] == ',') {
        p = 0;
        sz = 0;
        dh[zt]++;
        if (s[zt]) {
            s[zt] = 0;
            return pd(x + 1);
        }
        else return 0;
    }
    return 0;
}

int main() {
    p = 1;
    getline(cin, a);
    len = a.length();
    //cout << "格式非法！";
   /* for (int i = 0; i < len; i++) {
        if(b[i])
    }*/
    if (pd(0) == 0) cout << "格式非法！";
    else cout << "格式合法！";
    return 0;
}