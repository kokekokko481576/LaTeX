#include <iostream>
#include <fstream> 
#include <vector>
#include <cmath>
#include <complex>
#include <iomanip>

using namespace std;

// z^3 - 1 の関数
complex<double> f(complex<double> z) {
    return z * z * z - 1.0;
}

// z^3 - 1 の導関数
complex<double> df(complex<double> z) {
    return 3.0 * z * z;
}

// ニュートン法を実行する関数
// 戻り値はどの解に収束したかを示す番号 (1, 2, 3)、収束しなければ0
int newton(complex<double> initial_z) {
    complex<double> z = initial_z;
    int i_max = 50;

    for (int i = 0; i < i_max; ++i) {
        if (abs(df(z)) < 1e-12) return 0; // 失敗
        
        z = z - f(z) / df(z);

        if (abs(f(z)) < 1e-9) { // 解に十分近づいたら
            // ３つの解のどれに近いか判定
            complex<double> root1(1.0, 0.0);
            complex<double> root2(-0.5, sqrt(3.0)/2.0);
            complex<double> root3(-0.5, -sqrt(3.0)/2.0);
            
            if (abs(z - root1) < 1e-6) return 1;
            if (abs(z - root2) < 1e-6) return 2;
            if (abs(z - root3) < 1e-6) return 3;
            
            return 0; // どの解にも近くなかったら失敗
        }
    }
    return 0; // 最大反復回数に達したら失敗
}

int main() {
    double real_min = -2.0, real_max = 2.0;
    double imag_min = -2.0, imag_max = 2.0;
    double step = 0.01; 

    // 結果を保存するファイルを開く
    ofstream ofs("newton_fractal_data.csv");
    if (!ofs) {
        cout << "(^_-)-☆CSV出力失敗！" << endl;
        return 1;
    }

    cout << "計算チュウ！待てと！" << endl;

    // 複素平面上を探索
    for (double y = imag_max; y >= imag_min; y -= step) {
        for (double x = real_min; x <= real_max; x += step) {
            complex<double> initial_z(x, y);
            
            int root_number = newton(initial_z);
            
            // 結果をｃｓｖに出力
            if (root_number == 1) {
                ofs << x << "," << y << endl;
            }
        }
    }

    ofs.close();
    cout << "計算完了！ newton_fractal_data.csv に結果を出力シマシタ" << endl;
    cout << "あとは"<<"Excel"<<"で描画してくれぃ" << endl;

    return 0;
}
