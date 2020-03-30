# Skyscrapers-Codeforces-2versions
Giải quyết bài toán skyscrapers trên codeforces với 2 version dễ, khó.

Bài toán: 

The outskirts of the capital are being actively built up in Berland. The company "Kernel Panic" manages the construction of a residential complex of skyscrapers in New Berlskva. All skyscrapers are built along the highway. It is known that the company has already bought n plots along the highway and is preparing to build n skyscrapers, one skyscraper per plot.

Architects must consider several requirements when planning a skyscraper. Firstly, since the land on each plot has different properties, each skyscraper has a limit on the largest number of floors it can have. Secondly, according to the design code of the city, it is unacceptable for a skyscraper to simultaneously have higher skyscrapers both to the left and to the right of it.

Formally, let's number the plots from 1 to n. Then if the skyscraper on the i-th plot has ai floors, it must hold that ai is at most mi (1≤ai≤mi). Also there mustn't be integers j and k such that j<i<k and aj>ai<ak. Plots j and k are not required to be adjacent to i.

The company wants the total number of floors in the built skyscrapers to be as large as possible. Help it to choose the number of floors for each skyscraper in an optimal way, i.e. in such a way that all requirements are fulfilled, and among all such construction plans choose any plan with the maximum possible total number of floors.

Input

The first line contains a single integer n (1≤n≤500000) — the number of plots (easy-version n <=1000).

The second line contains the integers m1,m2,…,mn (1≤mi≤109) — the limit on the number of floors for every possible number of floors for a skyscraper on each plot.

Output

Print n integers ai — the number of floors in the plan for each skyscraper, such that all requirements are met, and the total number of floors in all skyscrapers is the maximum possible.

If there are multiple answers possible, print any of them.
