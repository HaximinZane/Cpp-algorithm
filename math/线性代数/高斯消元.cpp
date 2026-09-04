#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9; // 精度阈值

/*
 * 高斯-约当消元（Gauss-Jordan Elimination）
 * 参数：
 *   a : 增广矩阵，大小为 n 行 × (m+1) 列，其中 n 为方程个数，m 为未知数个数。
 *       （通常 n = m，即方阵）
 *   x : 用于存储解向量（当有唯一解时）
 * 返回值：
 *   0 : 唯一解
 *   1 : 无穷多解
 *   2 : 无解
 */
int gauss(vector<vector<double>> a, vector<double> &x)
{
    int n = (int)a.size();        // 方程数
    int m = (int)a[0].size() - 1; // 未知数个数

    vector<int> where(m, -1); // where[col] = 行号，表示变量 col 对应的主元所在行（-1表示自由变量）

    int row = 0; // 当前处理的行

    // 按列扫描
    for (int col = 0; col < m && row < n; ++col)
    {
        // 1. 选主元：在 row 到 n-1 行中，找到当前列绝对值最大的行
        int sel = row;
        for (int i = row; i < n; ++i)
        {
            if (fabs(a[i][col]) > fabs(a[sel][col]))
            {
                sel = i;
            }
        }

        // 如果该列所有元素都接近 0，则此列为自由变量，跳过
        if (fabs(a[sel][col]) < EPS)
            continue;

        // 2. 将主元行交换到当前行
        swap(a[sel], a[row]);

        // 记录该列对应的主元行
        where[col] = row;

        // 3. 归一化主元行：将主元变为 1
        double pivot = a[row][col];
        for (int j = col; j <= m; ++j)
        {
            a[row][j] /= pivot;
        }

        // 4. 消去其他所有行（包括上方和下方），使该列除主元外均为 0
        for (int i = 0; i < n; ++i)
        {
            if (i == row)
                continue;
            double factor = a[i][col];
            for (int j = col; j <= m; ++j)
            {
                a[i][j] -= factor * a[row][j];
            }
        }

        ++row; // 处理下一行
    }

    // 5. 检查无解：若存在形如 0 = b (b ≠ 0) 的行，则无解
    for (int i = row; i < n; ++i)
    {
        if (fabs(a[i][m]) > EPS)
        {
            return 2; // 无解
        }
    }

    // 6. 判断是否有自由变量（即存在某些列没有主元）
    if (row < m)
    {
        return 1; // 无穷多解
    }

    // 7. 唯一解：直接读取每个主元列对应的常数项
    x.assign(m, 0);
    for (int col = 0; col < m; ++col)
    {
        // where[col] 是主元所在行，该行的最后一列即为解
        x[col] = a[where[col]][m];
    }
    return 0;
}

// ------------------------------------------------------------
// 以下是使用示例
int main()
{
    // 示例：求解方程组
    // 2x +  y -  z = 8
    // -3x -  y + 2z = -11
    // -2x +  y + 2z = -3
    vector<vector<double>> a = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}};

    vector<double> x;
    int res = gauss(a, x);

    if (res == 0)
    {
        cout << "唯一解：\n";
        for (int i = 0; i < (int)x.size(); ++i)
        {
            cout << "x" << i << " = " << x[i] << "\n";
        }
    }
    else if (res == 1)
    {
        cout << "无穷多解\n";
    }
    else
    {
        cout << "无解\n";
    }

    return 0;
}