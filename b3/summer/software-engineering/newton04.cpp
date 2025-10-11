#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 方程式の係数をグローバル変数として定義
double a, b, c, d, e;

// f(x) = ax^4 + bx^3 + cx^2 + dx + e を計算する関数
double f(double x) {
    return a * pow(x, 4) + b * pow(x, 3) + c * pow(x, 2) + d * x + e;
}

// f'(x) = 4ax^3 + 3bx^2 + 2cx + d を計算する関数
double df(double x) {
    return 4 * a * pow(x, 3) + 3 * b * pow(x, 2) + 2 * c * x + d;
}

// ニュートン法を実行する関数
// 戻り値：計算が成功したか (true/false)
// 引数１：initial_x （初期値）
// 引数２：root_result （見つかった解を入れる箱）
bool newton(double initial_x, double& root_result) {
    double x = initial_x;
    int i_max = 50;

    for (int i = 0; i < i_max; ++i) {
        double dfx = df(x);
        if (abs(dfx) < 1e-12) {
            return false;
        }
        
        double dx = f(x) / dfx;
        x = x - dx;

        if (abs(dx) < 1e-9) {
            root_result = x;
            return true;
        }
    }
    return false;
}

int main() {
    cout << "4次方程式 ax^4 + bx^3 + cx^2 + dx + e = 0 の解を求める。" << endl;
    cout << "係数 (a b c d e) と初期値の探索範囲 (x_min x_max) を入力セヨ" << endl;
    cin >> a >> b >> c >> d >> e;

    vector<double> found_roots;
    double root_tolerance = 1e-6;

    double x_min, x_max;
    cin >> x_min >> x_max;
    
    cout << "探索範囲 " << x_min << " から " << x_max << " で探索をカイシ" << endl;

    // 探索範囲内で初期値を変化させながら解を探す
    for (double current_initial_x = x_min; current_initial_x <= x_max; current_initial_x += 0.5) {
        
        double a_root;
        
        if (newton(current_initial_x, a_root)) {
            
            bool is_new_root = true;// 旗を立てる
            for (double root : found_roots) {
                if (abs(a_root - root) < root_tolerance) {
                    is_new_root = false;// 既存の解と近いので旗を下ろす
                }
            }
            // まだ旗が立っている⇔新しい解を見つけた場合
            if (is_new_root) {
                found_roots.push_back(a_root);
                cout << "新しい解をハッケン!: " << a_root << " (初期値 " << current_initial_x << ")" << endl;
            }
        }

        if (found_roots.size() >= 4) {
            break;
        }
    }

    // 最終結果の表示
    if (found_roots.size() > 0) {
        cout << "探索終了！ " << found_roots.size() << "個の解をハッケン！" << endl;
        for (int i = 0; i < found_roots.size(); ++i) {
            cout << "解 " << i + 1 << ": " << found_roots[i] << endl;
        }
    } else {
        cout << "範囲内に解は一つもなかったゾ" << endl;
        cout << "探索範囲を広げて出直してこい" << endl;
    }

    return 0;
}
