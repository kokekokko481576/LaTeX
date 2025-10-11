#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream> 

using namespace std;

const double C = 0.04455; // 造波減衰力係数
const double W = 0.905;   // 波強制力の角振動数

// 右辺を計算する関数
void equations(double t, double x, double v, double B, double& dxdt, double& dvdt) {
    dxdt = v;
    dvdt = -C * v - x + pow(x, 3) + B * cos(W * t);
}

// ４次のルンゲ・クッタ法で１ステップだけ計算を進める関数
void runge_kutta_step(double& t, double& x, double& v, double dt, double B) {
    double kx1, kv1, kx2, kv2, kx3, kv3, kx4, kv4;
    equations(t, x, v, B, kx1, kv1);
    equations(t + dt/2.0, x + dt/2.0*kx1, v + dt/2.0*kv1, B, kx2, kv2);
    equations(t + dt/2.0, x + dt/2.0*kx2, v + dt/2.0*kv2, B, kx3, kv3);
    equations(t + dt,     x + dt*kx3,     v + dt*kv3,     B, kx4, kv4);
    x = x + (dt / 6.0) * (kx1 + 2.0*kx2 + 2.0*kx3 + kx4);
    v = v + (dt / 6.0) * (kv1 + 2.0*kv2 + 2.0*kv3 + kv4);
    t = t + dt;
}


int main() {
    // 計算範囲
    double x0_min = -1.5, x0_max = 1.5;
    double v0_min = -1.5, v0_max = 1.5;
    double grid_step = 0.05;// 格子点の間隔

    double t_max = 100.0;// シミュレーションの最大時間
    double dt = 0.1;// 時間刻み
    double divergence_threshold = 100.0;// 発散判定の閾値

    // Ｂを０から０．３まで、０．００３刻みでループ (0.03 * 10 = 0.3)
    for (int i = 0; i <= 10; ++i) {
        double B = i * 0.03; // 整数ｉから、誤差なくＢの値を計算
        
        stringstream ss;
        ss << "basin_B_"  << B << ".csv";
        string filename = ss.str();// ファイル名を作成

        ofstream ofs(filename);
        if (!ofs) {
            cout << "(^_-)-☆CSV出力失敗！" << filename << endl;
            return 1;
        }

        cout << "B = "  << B << " の計算チュウ..." << endl;

        // 初期値(x0, v0)の格子点をループ
        for (double v0 = v0_min; v0 <= v0_max; v0 += grid_step) {// 初期速度のループ
            for (double x0 = x0_min; x0 <= x0_max; x0 += grid_step) {// 初期位置のループ
                // 初期値を設定
                double t = 0.0, x = x0, v = v0;
                bool diverged = false;// 発散フラグ初期化

                while (t < t_max) {
                    runge_kutta_step(t, x, v, dt, B);
                    if (abs(x) > divergence_threshold || abs(v) > divergence_threshold) {
                        diverged = true;// 発散した場合、旗を立てる
                        // cout << "発散: x = " << x << ", v = " << v << " at t = " << t << endl;
                        // 発散の宣言いれたら出力長文になったのでカット
                        break;
                    }
                }
                // 旗が立たず、発散しなかった場合
                if (!diverged) {
                    ofs << x0 << "," << v0 << endl;
                }
            }
        }
        ofs.close();
        cout << "B = " << B << " の計算おわり -> " << filename << endl;
    }

    cout << "\n全てカンリョウ！" << endl;
    cout << "11" << "個" << "csv" << "ができたはず!" << "\n" << "あとは" << "Excel" << "でがんばれ" << endl;

    return 0;
}
