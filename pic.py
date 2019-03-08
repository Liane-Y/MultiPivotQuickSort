import numpy
import time
import matplotlib.pyplot as plt
import matplotlib.ticker as mtick
fmt='%.2f%%'  
yticks = mtick.FormatStrFormatter(fmt) 






ite=range(1,31)
qs=[752,615,533,463,385,377,405,451,453,449,455,439,473,469,455,477,522,492,499,549,579,546,551,561,512,520,512,519,559,575]
cmp_n=[6625100,4043170,3127562,2709098,2302168,2143136,2078694,1944672,1820384,1725238,1653052,1618158,1566658,1527462,1485006,1474990,1419386,1394382,1417384,1364686,1322514,1329282,1312290,1312862,1285804,1278032,1247398,1231448,1231336,1210782,]
twoqs=[26,53,161,385,711]
plt.plot(ite,qs,'r-<',label="running time", linewidth=1)
# plt.plot(ite,twoqs,'g--*',label="2-pivot", linewidth=1)
plt.legend()
plt.xlabel(" pivot number")  
plt.ylabel("running time/ms")
plt.title("running time v.s. pivot number when data sorted")  
plt.tight_layout()
plt.savefig("6.png")
plt.show()
