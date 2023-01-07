### 第三题

求失效函数的公式为：
$$ f[i]=\begin{cases}
max\{k|0<k<i且"t_0t_1 \cdots t_{k-1}"="t_{j-k} \cdots t_{j-1}\} & 当此集合非空时 \\
-1 & 当i=0时 \\
0 & 其他情况时 
\end{cases}$$

对于改进后的失效函数为：
$$ newf[i]=\begin{cases}
f[i] & 当i=0或s[i] \not = s[f[i]] \\
newf[f[i]] & 当i \not = 0且s[i]=s[f[i]]
\end{cases}$$

由此，可求得该字符串的失效函数值和改进后的失效函数值如下所示：
