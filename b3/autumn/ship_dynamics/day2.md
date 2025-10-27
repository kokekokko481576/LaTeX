## 課題 2-2 解答
古賀光一朗
08C23031

---


### (1) 分散関係式

* **有限水深 (水深 $h$)**
    $$
    \omega^2 = kg \tanh(kh)
    $$
* **無限水深 ($h \to \infty$)**
    $\tanh(kh) \to 1$ となるため、
    $$
    \omega^2 = kg
    $$

---

### (2) 出会い波周期

周期 $T = 10 \, \text{s}$、船速 $V = 25 \, \text{knots}$ の向かい波における出会い波周期 $T_e$ を求める。

**1. 基本量の算出**
$$
\omega = \frac{2\pi}{T} = \frac{2\pi}{10} = 0.2\pi \, \text{rad/s} \approx 0.6283 \, \text{rad/s}
$$
$$
k = \frac{\omega^2}{g} = \frac{(0.2\pi)^2}{9.8} \approx 0.04028 \, \text{rad/m}
$$

**2. 船速の単位換算**
$$
V = 25 \, \text{knots} \times \frac{1852 \, \text{m/h}}{1 \, \text{knot}} \times \frac{1 \, \text{h}}{3600 \, \text{s}} \approx 12.86 \, \text{m/s}
$$

**3. 出会い角周波数 $\omega_e$**
向かい波 ($\theta = \pi$) のため、$\cos\theta = -1$ 。
$$
\omega_e = \omega - kV\cos\theta = \omega + kV
$$
$$
\omega_e \approx 0.6283 + (0.04028 \times 12.86) \approx 0.6283 + 0.5179 \approx 1.1462 \, \text{rad/s}
$$

**4. 出会い波周期 $T_e$**
$$
T_e = \frac{2\pi}{\omega_e} \approx \frac{2\pi}{1.1462} \approx 5.481 \, \text{s}
$$

**解答 (2): $T_e \approx 5.48 \, \text{s}$**

---

### (3) 波長、位相速度、群速度

周期 $T = 10 \, \text{s}$ の波の諸元を求める。

**1. 波長 $\lambda$**
分散関係 $\omega^2 = kg$ と $\omega=2\pi/T$, $k=2\pi/\lambda$ より、
$$
\left(\frac{2\pi}{T}\right)^2 = \frac{2\pi}{\lambda} g \implies \lambda = \frac{gT^2}{2\pi}
$$
$$
\lambda = \frac{9.8 \times 10^2}{2\pi} \approx 155.98 \, \text{m}
$$

**2. 位相速度 $C$**
$$
C = \frac{\lambda}{T} = \frac{155.98 \, \text{m}}{10 \, \text{s}} \approx 15.60 \, \text{m/s}
$$

**3. 群速度 $C_g$**
無限水深では $C_g = C/2$ である。
$$
C_g = \frac{1}{2} C \approx \frac{1}{2} \times 15.60 = 7.80 \, \text{m/s}
$$

**解答 (3):**
* **波長 $\lambda \approx 156 \, \text{m}$**
* **位相速度 $C \approx 15.6 \, \text{m/s}$**
* **群速度 $C_g \approx 7.80 \, \text{m/s}$**

---

### (4) 1波長平均エネルギー

波高 $H = 1 \, \text{m}$（振幅 $\zeta_a = 0.5 \, \text{m}$）、周期 $T = 10 \, \text{s}$ の波について、単位幅あたりの1波長平均エネルギー $E_L$ を求める。密度 $\rho = 1000 \, \text{kg/m}^3$ 。

**1. 単位面積あたり平均エネルギー $E$**
$$
E = \frac{1}{2} \rho g \zeta_a^2 = \frac{1}{2} \times 1000 \times 9.8 \times (0.5)^2 = 1225 \, \text{J/m}^2
$$

**2. 単位幅あたり1波長平均エネルギー $E_L$**
$E_L$ は $E$ に波長 $\lambda$ を乗じたものである。
$$
E_L = E \times \lambda = 1225 \, \text{J/m}^2 \times 155.98 \, \text{m} \approx 191,075.5 \, \text{J/m}
$$

**解答 (4): $E_L \approx 1.91 \times 10^5 \, \text{J/m}$**

---

### (5) 波の分散性

波の**分散性**とは、**波の伝播速度（位相速度）が、その波の周波数（または波長）によって異なる性質**である。

無限水深における位相速度 $C$ は、
$$
C = \frac{\omega}{k} = \frac{g}{\omega} \quad \text{または} \quad C = \sqrt{\frac{g\lambda}{2\pi}}
$$
と表され、速度 $C$ が角周波数 $\omega$ や波長 $\lambda$ に依存していることがわかる。

この性質により、異なる周波数成分が混在する波は、伝播するにつれて周波数（波長）ごとに分離していく。
