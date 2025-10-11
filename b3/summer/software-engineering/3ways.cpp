#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    // 計算条件
    double t = 0.0;
    double dt = 0.1;
    double t_max = 50.0;

    double x_e = 1.0, v_e = 0.0;// チーム☆Euler
    double x_h = 1.0, v_h = 0.0;// チーム☆Heun
    double x_rk = 1.0, v_rk = 0.0;// チーム☆Runge-Kutta

    // ファイル名
    string filename = "result_three_methods_01.csv";
    cout << filename << " に結果を出力!!" << endl;

    // エラー処理
    ofstream ofs(filename);
    if (!ofs) {
        cout << "(^_-)-☆CSV出力失敗！" << endl;
        return -1;
    }

    // ヘッダー
    ofs << "t,x_euler,x_heun,x_runge_kutta,x_exact" << endl;

    // 計算
    for (t = 0.0; t <= t_max; t = t + dt) {
        ofs << t << "," << x_e << "," << x_h << "," << x_rk << "," << cos(t) << endl;

        // Euler
        double old_x_e = x_e;
        x_e = x_e + dt * v_e;
        v_e = v_e + dt * (-old_x_e);

        // Heun
        // 1. 予測(Predictor)
        double pred_x = x_h + dt * v_h;
        double pred_v = v_h + dt * (-x_h);
        // 2. 修正(Corrector) - スタート地点の傾きと予測地点の傾きを平均
        x_h = x_h + dt * (v_h + pred_v) / 2.0;
        v_h = v_h + dt * ((-x_h) + (-pred_x)) / 2.0;


        // Runge-Kutta
        double kx1 = dt * v_rk;
        double kv1 = dt * (-x_rk);
        double kx2 = dt * (v_rk + kv1 / 2.0);
        double kv2 = dt * -(x_rk + kx1 / 2.0);
        double kx3 = dt * (v_rk + kv2 / 2.0);
        double kv3 = dt * -(x_rk + kx2 / 2.0);
        double kx4 = dt * (v_rk + kv3);
        double kv4 = dt * -(x_rk + kx3);
        x_rk = x_rk + (kx1 + 2.0 * kx2 + 2.0 * kx3 + kx4) / 6.0;
        v_rk = v_rk + (kv1 + 2.0 * kv2 + 2.0 * kv3 + kv4) / 6.0;
    }

    ofs.close();
    cout << "計算完了! " << filename << endl;

    return 0;
}