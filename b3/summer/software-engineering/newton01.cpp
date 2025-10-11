#include <iostream>
#include <cmath> 
using namespace std;

// 係数をグローバル変数として定義
double a, b, c, d, e;

// f(x) = ax^4 + bx^3 + cx^2 + dx + e
double f(double x) {
    return a * pow(x, 4) + b * pow(x, 3) + c * pow(x, 2) + d * x + e;
}

// f'(x) = 4ax^3 + 3bx^2 + 2cx + d
double df(double x) {
    return 4 * a * pow(x, 3) + 3* b * pow(x, 2) + 2* c * x + d;
}

double newton(double x){
    int i_max = 50; // 最大反復回数
    for (int i = 0; i < i_max; ++i) {
        double fx = f(x);
        double dfx = df(x);

        // 傾き0のエラー処理
        if (fabs(dfx) < 1e-12) {
            cout << "計算エラー : 0除算だぜ☆" << endl;
            return -1;
        }
        // ニュートン法の計算
        double dx = fx / dfx;
        x = x - dx;

        // 途中経過
        cout << "試行"  << i + 1 << ": x = " << x << endl;

        // 収束判定
        if (fabs(dx) < 1e-12) break;// エディタが12をおすすめしてきたので、12にした
    }
    return x;
}

int main() {
    cout << "a b c d e" << endl;
    cout << "x" << endl;
    cout << "の形式で係数と初期値をオシエロ " << endl;
    cin >> a >> b >> c >> d >> e;
    double x;
    cin >> x;
    cout << "初期値: x = " << fixed << x << endl;

    x = newton(x);

    cout << "収束するといいね♡　結果は x = " << fixed << x << endl;

    return 0;
}
