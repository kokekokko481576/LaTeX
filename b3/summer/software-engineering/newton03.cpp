#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Global variables for equation coefficients
double a, b, c, d, e;

// f(x) = ax^4 + bx^3 + cx^2 + dx + e
double f(double x) {
    return a * pow(x, 4) + b * pow(x, 3) + c * pow(x, 2) + d * x + e;
}

// f'(x) = 4ax^3 + 3bx^2 + 2cx + d
double df(double x) {
    return 4 * a * pow(x, 3) + 3 * b * pow(x, 2) + 2 * c * x + d;
}

// Executes Newton's method.
// Returns true if a root converges, false otherwise.
// The found root is returned via the reference parameter 'root_result'.
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
    cout<< "a b c d e" << endl;
    cout << "x_min x_max"<< endl;
    cout << "Enter coefficients and the range for initial x in this style ! " << endl;
    cin >> a >> b >> c >> d >> e;
    cout << endl;

    vector<double> found_roots;
    double root_tolerance = 1e-6;

    double initial_x;
    double final_x;

    cin >> initial_x >> final_x;
    
    // Search for roots by varying the initial value
    for (initial_x; initial_x <= final_x; initial_x += 0.5) {
        
        double a_root;
        
        if (newton(initial_x, a_root)) {
            
            bool is_new_root = true;
            for (double root : found_roots) {
                if (abs(a_root - root) < root_tolerance) {
                    is_new_root = false;
                }
            }

            if (is_new_root) {
                found_roots.push_back(a_root);
                cout << "New root found: " << a_root << " (from initial_x = " << initial_x << ")" << endl;
            }
        }

        if (found_roots.size() >= 4) {
            break;
        }
    }

    // Display the final results
    if (found_roots.size() > 0) {
        cout << "Search finished. Found " << found_roots.size() << " root(s):" << endl;
        for (int i = 0; i < found_roots.size(); ++i) {
            cout << "Root " << i + 1 << ": " << found_roots[i] << endl;
        }
    } else {
        cout << "No roots were found in the search range." << endl;
    }

    return 0;
}
