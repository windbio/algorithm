#include <iostream>
#include <algorithm>

using namespace std;

// 实现两个整数的加
// 原理: 串行加法器
// 样例: "9999" + "100" = "10099"
string add(string a, string b) {
    string c;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int i = 0, j = 0;
    int sum = 0, carry = 0;
    while (i < a.size() && j < b.size()) {
        sum = (a[i] - '0') + (b[j] - '0') + carry;
        c.push_back('0' + sum % 10);
        carry = sum / 10;
        i ++;
        j ++;
    }
    
    while (i < a.size()) {
        sum = (a[i] - '0') + carry;
        c.push_back('0' + sum % 10);
        carry = sum / 10;
        i ++;
    }
    
    while (j < b.size()) {
        sum = (b[j] - '0') + carry;
        c.push_back('0' + sum % 10);
        carry = sum / 10;
        j ++;
    }
    
    if (carry > 0) c.push_back('0' + carry);
    
    reverse(c.begin(), c.end());
    return c;
}

// a 是一个任意整数，digit 属于 0 到 9 之间的数
// 原理: 小学时学的乘法步骤
// 样例: "1234" * 2 = "2468"
string multiply(string a, int digit) {
    if (digit == 0) return "0";
    string c = "";
    reverse(a.begin(), a.end());
    int sum = 0, carry = 0;
    for (int i = 0; i < a.size(); i ++) {
        sum = digit * (a[i] - '0') + carry;
        c.push_back('0' + sum % 10);
        carry = sum / 10;
    }
    if (carry > 0) c.push_back('0' + carry);
    reverse(c.begin(), c.end());
    return c;
}

// 实现两个整数的乘法
// 原理: 小学时学的乘法步骤
// 样例: "99" * "20" = "1980"
string multiply(string a, string b) {
    string c = "0";
    string base = "";
    reverse(b.begin(), b.end());
    for (int i = 0; i < b.size(); i ++) {
        string temp = multiply(a, b[i] - '0') + base;
        c = add(c, temp);
        base += "0";
    }
    return c;
}

// 将小数点插入合适位置，并去除前面和后面多余的零
// 样例: format(100100, 4) 的结果是 10.01
string format(string a, unsigned long pointIndex) {
    unsigned long i;
    
    reverse(a.begin(), a.end());
    for (i = a.size(); i < pointIndex; i ++) a.push_back('0');
    a.insert(pointIndex, ".");
    for (i = 0; i < a.size(); i++) if (a[i] != '0') break;
    a = a.substr(i);
    if (a.size() > 0 && a[0] == '.') a = a.substr(1);
    reverse(a.begin(), a.end());
    for (i = 0; i < a.size(); i++) if (a[i] != '0') break;
    a = a.substr(i);
    if (a.size() == 0) return "0";
    return a;
}

// 整数的幂运算实现
// 样例: exp("10", 4) 的结果是 10000
string exp(string r, int n) {
    string product = "";
    unsigned long pointIndex = 0;
    for (int i = 0; i < r.size(); i ++) {
        if (r[i] != '.') product.push_back(r[i]);
        else pointIndex = r.size() - (i+1);
    }
    
    r = product;
    for (int i = 2; i <= n; i++) {
        product = multiply(product, r);
    }
    pointIndex = pointIndex * n;
    return format(product, pointIndex);
}


int main() {
    string r;
    int n;
    while (cin >> r >> n) cout << exp(r, n) << endl;
    return 0;
}
