<!DOCTYPE html>
<html lang='en'>
<head>
<title>vi.c « editors - busybox - BusyBox: The Swiss Army Knife of Embedded Linux</title>
<meta name='generator' content='cgit v1.2.3'/>
<meta name='robots' content='index, nofollow'/>
<link rel='stylesheet' type='text/css' href='/cgit.css'/>
<link rel='shortcut icon' href='/favicon.ico'/>
<link rel='alternate' title='Atom feed' href='https://git.busybox.net/busybox/atom/editors/vi.c?h=master' type='application/atom+xml'/>
<link rel='vcs-git' href='git://git.busybox.net/busybox' title='busybox Git repository'/>
<link rel='vcs-git' href='https://git.busybox.net/busybox' title='busybox Git repository'/>
</head>
<body>
<div id='cgit'><table id='header'>
<tr>
<td class='logo' rowspan='2'><a href='/'><img src='/busybox1.png' alt='cgit logo'/></a></td>
<td class='main'><a href='/'>index</a> : <a title='busybox' href='/busybox/'>busybox</a></td><td class='form'><form method='get'>
<select name='h' onchange='this.form.submit();'>
<option value='0_60_stable'>0_60_stable</option>
<option value='1_00_stable'>1_00_stable</option>
<option value='1_00_stable_10817'>1_00_stable_10817</option>
<option value='1_10_stable'>1_10_stable</option>
<option value='1_11_stable'>1_11_stable</option>
<option value='1_12_stable'>1_12_stable</option>
<option value='1_13_stable'>1_13_stable</option>
<option value='1_14_stable'>1_14_stable</option>
<option value='1_15_stable'>1_15_stable</option>
<option value='1_16_stable'>1_16_stable</option>
<option value='1_17_stable'>1_17_stable</option>
<option value='1_18_stable'>1_18_stable</option>
<option value='1_19_stable'>1_19_stable</option>
<option value='1_1_stable'>1_1_stable</option>
<option value='1_20_stable'>1_20_stable</option>
<option value='1_21_stable'>1_21_stable</option>
<option value='1_22_stable'>1_22_stable</option>
<option value='1_23_stable'>1_23_stable</option>
<option value='1_24_stable'>1_24_stable</option>
<option value='1_25_stable'>1_25_stable</option>
<option value='1_26_stable'>1_26_stable</option>
<option value='1_27_stable'>1_27_stable</option>
<option value='1_28_stable'>1_28_stable</option>
<option value='1_29_stable'>1_29_stable</option>
<option value='1_30_stable'>1_30_stable</option>
<option value='1_31_stable'>1_31_stable</option>
<option value='1_32_stable'>1_32_stable</option>
<option value='1_33_stable'>1_33_stable</option>
<option value='1_34_stable'>1_34_stable</option>
<option value='1_35_stable'>1_35_stable</option>
<option value='1_3_stable'>1_3_stable</option>
<option value='1_4_stable'>1_4_stable</option>
<option value='1_5_stable'>1_5_stable</option>
<option value='1_6_stable'>1_6_stable</option>
<option value='1_7_stable'>1_7_stable</option>
<option value='1_8_stable'>1_8_stable</option>
<option value='1_9_stable'>1_9_stable</option>
<option value='master' selected='selected'>master</option>
</select> <input type='submit' value='switch'/></form></td></tr>
<tr><td class='sub'>BusyBox: The Swiss Army Knife of Embedded Linux</td><td class='sub right'>vda</td></tr></table>
<table class='tabs'><tr><td>
<a href='/busybox/about/'>about</a><a href='/busybox/'>summary</a><a href='/busybox/refs/'>refs</a><a href='/busybox/log/editors/vi.c'>log</a><a class='active' href='/busybox/tree/editors/vi.c'>tree</a><a href='/busybox/commit/editors/vi.c'>commit</a><a href='/busybox/diff/editors/vi.c'>diff</a></td><td class='form'><form class='right' method='get' action='/busybox/log/editors/vi.c'>
<select name='qt'>
<option value='grep'>log msg</option>
<option value='author'>author</option>
<option value='committer'>committer</option>
<option value='range'>range</option>
</select>
<input class='txt' type='search' size='10' name='q' value=''/>
<input type='submit' value='search'/>
</form>
</td></tr></table>
<div class='path'>path: <a href='/busybox/tree/'>root</a>/<a href='/busybox/tree/editors'>editors</a>/<a href='/busybox/tree/editors/vi.c'>vi.c</a></div><div class='content'>blob: d799a8170675e3dac066c08a350a78ed9f871855 (<a href='/busybox/plain/editors/vi.c'>plain</a>)
<table summary='blob content' class='blob'>
<tr><td class='linenumbers'><pre><a id='n1' href='#n1'>1</a>
<a id='n2' href='#n2'>2</a>
<a id='n3' href='#n3'>3</a>
<a id='n4' href='#n4'>4</a>
<a id='n5' href='#n5'>5</a>
<a id='n6' href='#n6'>6</a>
<a id='n7' href='#n7'>7</a>
<a id='n8' href='#n8'>8</a>
<a id='n9' href='#n9'>9</a>
<a id='n10' href='#n10'>10</a>
<a id='n11' href='#n11'>11</a>
<a id='n12' href='#n12'>12</a>
<a id='n13' href='#n13'>13</a>
<a id='n14' href='#n14'>14</a>
<a id='n15' href='#n15'>15</a>
<a id='n16' href='#n16'>16</a>
<a id='n17' href='#n17'>17</a>
<a id='n18' href='#n18'>18</a>
<a id='n19' href='#n19'>19</a>
<a id='n20' href='#n20'>20</a>
<a id='n21' href='#n21'>21</a>
<a id='n22' href='#n22'>22</a>
<a id='n23' href='#n23'>23</a>
<a id='n24' href='#n24'>24</a>
<a id='n25' href='#n25'>25</a>
<a id='n26' href='#n26'>26</a>
<a id='n27' href='#n27'>27</a>
<a id='n28' href='#n28'>28</a>
<a id='n29' href='#n29'>29</a>
<a id='n30' href='#n30'>30</a>
<a id='n31' href='#n31'>31</a>
<a id='n32' href='#n32'>32</a>
<a id='n33' href='#n33'>33</a>
<a id='n34' href='#n34'>34</a>
<a id='n35' href='#n35'>35</a>
<a id='n36' href='#n36'>36</a>
<a id='n37' href='#n37'>37</a>
<a id='n38' href='#n38'>38</a>
<a id='n39' href='#n39'>39</a>
<a id='n40' href='#n40'>40</a>
<a id='n41' href='#n41'>41</a>
<a id='n42' href='#n42'>42</a>
<a id='n43' href='#n43'>43</a>
<a id='n44' href='#n44'>44</a>
<a id='n45' href='#n45'>45</a>
<a id='n46' href='#n46'>46</a>
<a id='n47' href='#n47'>47</a>
<a id='n48' href='#n48'>48</a>
<a id='n49' href='#n49'>49</a>
<a id='n50' href='#n50'>50</a>
<a id='n51' href='#n51'>51</a>
<a id='n52' href='#n52'>52</a>
<a id='n53' href='#n53'>53</a>
<a id='n54' href='#n54'>54</a>
<a id='n55' href='#n55'>55</a>
<a id='n56' href='#n56'>56</a>
<a id='n57' href='#n57'>57</a>
<a id='n58' href='#n58'>58</a>
<a id='n59' href='#n59'>59</a>
<a id='n60' href='#n60'>60</a>
<a id='n61' href='#n61'>61</a>
<a id='n62' href='#n62'>62</a>
<a id='n63' href='#n63'>63</a>
<a id='n64' href='#n64'>64</a>
<a id='n65' href='#n65'>65</a>
<a id='n66' href='#n66'>66</a>
<a id='n67' href='#n67'>67</a>
<a id='n68' href='#n68'>68</a>
<a id='n69' href='#n69'>69</a>
<a id='n70' href='#n70'>70</a>
<a id='n71' href='#n71'>71</a>
<a id='n72' href='#n72'>72</a>
<a id='n73' href='#n73'>73</a>
<a id='n74' href='#n74'>74</a>
<a id='n75' href='#n75'>75</a>
<a id='n76' href='#n76'>76</a>
<a id='n77' href='#n77'>77</a>
<a id='n78' href='#n78'>78</a>
<a id='n79' href='#n79'>79</a>
<a id='n80' href='#n80'>80</a>
<a id='n81' href='#n81'>81</a>
<a id='n82' href='#n82'>82</a>
<a id='n83' href='#n83'>83</a>
<a id='n84' href='#n84'>84</a>
<a id='n85' href='#n85'>85</a>
<a id='n86' href='#n86'>86</a>
<a id='n87' href='#n87'>87</a>
<a id='n88' href='#n88'>88</a>
<a id='n89' href='#n89'>89</a>
<a id='n90' href='#n90'>90</a>
<a id='n91' href='#n91'>91</a>
<a id='n92' href='#n92'>92</a>
<a id='n93' href='#n93'>93</a>
<a id='n94' href='#n94'>94</a>
<a id='n95' href='#n95'>95</a>
<a id='n96' href='#n96'>96</a>
<a id='n97' href='#n97'>97</a>
<a id='n98' href='#n98'>98</a>
<a id='n99' href='#n99'>99</a>
<a id='n100' href='#n100'>100</a>
<a id='n101' href='#n101'>101</a>
<a id='n102' href='#n102'>102</a>
<a id='n103' href='#n103'>103</a>
<a id='n104' href='#n104'>104</a>
<a id='n105' href='#n105'>105</a>
<a id='n106' href='#n106'>106</a>
<a id='n107' href='#n107'>107</a>
<a id='n108' href='#n108'>108</a>
<a id='n109' href='#n109'>109</a>
<a id='n110' href='#n110'>110</a>
<a id='n111' href='#n111'>111</a>
<a id='n112' href='#n112'>112</a>
<a id='n113' href='#n113'>113</a>
<a id='n114' href='#n114'>114</a>
<a id='n115' href='#n115'>115</a>
<a id='n116' href='#n116'>116</a>
<a id='n117' href='#n117'>117</a>
<a id='n118' href='#n118'>118</a>
<a id='n119' href='#n119'>119</a>
<a id='n120' href='#n120'>120</a>
<a id='n121' href='#n121'>121</a>
<a id='n122' href='#n122'>122</a>
<a id='n123' href='#n123'>123</a>
<a id='n124' href='#n124'>124</a>
<a id='n125' href='#n125'>125</a>
<a id='n126' href='#n126'>126</a>
<a id='n127' href='#n127'>127</a>
<a id='n128' href='#n128'>128</a>
<a id='n129' href='#n129'>129</a>
<a id='n130' href='#n130'>130</a>
<a id='n131' href='#n131'>131</a>
<a id='n132' href='#n132'>132</a>
<a id='n133' href='#n133'>133</a>
<a id='n134' href='#n134'>134</a>
<a id='n135' href='#n135'>135</a>
<a id='n136' href='#n136'>136</a>
<a id='n137' href='#n137'>137</a>
<a id='n138' href='#n138'>138</a>
<a id='n139' href='#n139'>139</a>
<a id='n140' href='#n140'>140</a>
<a id='n141' href='#n141'>141</a>
<a id='n142' href='#n142'>142</a>
<a id='n143' href='#n143'>143</a>
<a id='n144' href='#n144'>144</a>
<a id='n145' href='#n145'>145</a>
<a id='n146' href='#n146'>146</a>
<a id='n147' href='#n147'>147</a>
<a id='n148' href='#n148'>148</a>
<a id='n149' href='#n149'>149</a>
<a id='n150' href='#n150'>150</a>
<a id='n151' href='#n151'>151</a>
<a id='n152' href='#n152'>152</a>
<a id='n153' href='#n153'>153</a>
<a id='n154' href='#n154'>154</a>
<a id='n155' href='#n155'>155</a>
<a id='n156' href='#n156'>156</a>
<a id='n157' href='#n157'>157</a>
<a id='n158' href='#n158'>158</a>
<a id='n159' href='#n159'>159</a>
<a id='n160' href='#n160'>160</a>
<a id='n161' href='#n161'>161</a>
<a id='n162' href='#n162'>162</a>
<a id='n163' href='#n163'>163</a>
<a id='n164' href='#n164'>164</a>
<a id='n165' href='#n165'>165</a>
<a id='n166' href='#n166'>166</a>
<a id='n167' href='#n167'>167</a>
<a id='n168' href='#n168'>168</a>
<a id='n169' href='#n169'>169</a>
<a id='n170' href='#n170'>170</a>
<a id='n171' href='#n171'>171</a>
<a id='n172' href='#n172'>172</a>
<a id='n173' href='#n173'>173</a>
<a id='n174' href='#n174'>174</a>
<a id='n175' href='#n175'>175</a>
<a id='n176' href='#n176'>176</a>
<a id='n177' href='#n177'>177</a>
<a id='n178' href='#n178'>178</a>
<a id='n179' href='#n179'>179</a>
<a id='n180' href='#n180'>180</a>
<a id='n181' href='#n181'>181</a>
<a id='n182' href='#n182'>182</a>
<a id='n183' href='#n183'>183</a>
<a id='n184' href='#n184'>184</a>
<a id='n185' href='#n185'>185</a>
<a id='n186' href='#n186'>186</a>
<a id='n187' href='#n187'>187</a>
<a id='n188' href='#n188'>188</a>
<a id='n189' href='#n189'>189</a>
<a id='n190' href='#n190'>190</a>
<a id='n191' href='#n191'>191</a>
<a id='n192' href='#n192'>192</a>
<a id='n193' href='#n193'>193</a>
<a id='n194' href='#n194'>194</a>
<a id='n195' href='#n195'>195</a>
<a id='n196' href='#n196'>196</a>
<a id='n197' href='#n197'>197</a>
<a id='n198' href='#n198'>198</a>
<a id='n199' href='#n199'>199</a>
<a id='n200' href='#n200'>200</a>
<a id='n201' href='#n201'>201</a>
<a id='n202' href='#n202'>202</a>
<a id='n203' href='#n203'>203</a>
<a id='n204' href='#n204'>204</a>
<a id='n205' href='#n205'>205</a>
<a id='n206' href='#n206'>206</a>
<a id='n207' href='#n207'>207</a>
<a id='n208' href='#n208'>208</a>
<a id='n209' href='#n209'>209</a>
<a id='n210' href='#n210'>210</a>
<a id='n211' href='#n211'>211</a>
<a id='n212' href='#n212'>212</a>
<a id='n213' href='#n213'>213</a>
<a id='n214' href='#n214'>214</a>
<a id='n215' href='#n215'>215</a>
<a id='n216' href='#n216'>216</a>
<a id='n217' href='#n217'>217</a>
<a id='n218' href='#n218'>218</a>
<a id='n219' href='#n219'>219</a>
<a id='n220' href='#n220'>220</a>
<a id='n221' href='#n221'>221</a>
<a id='n222' href='#n222'>222</a>
<a id='n223' href='#n223'>223</a>
<a id='n224' href='#n224'>224</a>
<a id='n225' href='#n225'>225</a>
<a id='n226' href='#n226'>226</a>
<a id='n227' href='#n227'>227</a>
<a id='n228' href='#n228'>228</a>
<a id='n229' href='#n229'>229</a>
<a id='n230' href='#n230'>230</a>
<a id='n231' href='#n231'>231</a>
<a id='n232' href='#n232'>232</a>
<a id='n233' href='#n233'>233</a>
<a id='n234' href='#n234'>234</a>
<a id='n235' href='#n235'>235</a>
<a id='n236' href='#n236'>236</a>
<a id='n237' href='#n237'>237</a>
<a id='n238' href='#n238'>238</a>
<a id='n239' href='#n239'>239</a>
<a id='n240' href='#n240'>240</a>
<a id='n241' href='#n241'>241</a>
<a id='n242' href='#n242'>242</a>
<a id='n243' href='#n243'>243</a>
<a id='n244' href='#n244'>244</a>
<a id='n245' href='#n245'>245</a>
<a id='n246' href='#n246'>246</a>
<a id='n247' href='#n247'>247</a>
<a id='n248' href='#n248'>248</a>
<a id='n249' href='#n249'>249</a>
<a id='n250' href='#n250'>250</a>
<a id='n251' href='#n251'>251</a>
<a id='n252' href='#n252'>252</a>
<a id='n253' href='#n253'>253</a>
<a id='n254' href='#n254'>254</a>
<a id='n255' href='#n255'>255</a>
<a id='n256' href='#n256'>256</a>
<a id='n257' href='#n257'>257</a>
<a id='n258' href='#n258'>258</a>
<a id='n259' href='#n259'>259</a>
<a id='n260' href='#n260'>260</a>
<a id='n261' href='#n261'>261</a>
<a id='n262' href='#n262'>262</a>
<a id='n263' href='#n263'>263</a>
<a id='n264' href='#n264'>264</a>
<a id='n265' href='#n265'>265</a>
<a id='n266' href='#n266'>266</a>
<a id='n267' href='#n267'>267</a>
<a id='n268' href='#n268'>268</a>
<a id='n269' href='#n269'>269</a>
<a id='n270' href='#n270'>270</a>
<a id='n271' href='#n271'>271</a>
<a id='n272' href='#n272'>272</a>
<a id='n273' href='#n273'>273</a>
<a id='n274' href='#n274'>274</a>
<a id='n275' href='#n275'>275</a>
<a id='n276' href='#n276'>276</a>
<a id='n277' href='#n277'>277</a>
<a id='n278' href='#n278'>278</a>
<a id='n279' href='#n279'>279</a>
<a id='n280' href='#n280'>280</a>
<a id='n281' href='#n281'>281</a>
<a id='n282' href='#n282'>282</a>
<a id='n283' href='#n283'>283</a>
<a id='n284' href='#n284'>284</a>
<a id='n285' href='#n285'>285</a>
<a id='n286' href='#n286'>286</a>
<a id='n287' href='#n287'>287</a>
<a id='n288' href='#n288'>288</a>
<a id='n289' href='#n289'>289</a>
<a id='n290' href='#n290'>290</a>
<a id='n291' href='#n291'>291</a>
<a id='n292' href='#n292'>292</a>
<a id='n293' href='#n293'>293</a>
<a id='n294' href='#n294'>294</a>
<a id='n295' href='#n295'>295</a>
<a id='n296' href='#n296'>296</a>
<a id='n297' href='#n297'>297</a>
<a id='n298' href='#n298'>298</a>
<a id='n299' href='#n299'>299</a>
<a id='n300' href='#n300'>300</a>
<a id='n301' href='#n301'>301</a>
<a id='n302' href='#n302'>302</a>
<a id='n303' href='#n303'>303</a>
<a id='n304' href='#n304'>304</a>
<a id='n305' href='#n305'>305</a>
<a id='n306' href='#n306'>306</a>
<a id='n307' href='#n307'>307</a>
<a id='n308' href='#n308'>308</a>
<a id='n309' href='#n309'>309</a>
<a id='n310' href='#n310'>310</a>
<a id='n311' href='#n311'>311</a>
<a id='n312' href='#n312'>312</a>
<a id='n313' href='#n313'>313</a>
<a id='n314' href='#n314'>314</a>
<a id='n315' href='#n315'>315</a>
<a id='n316' href='#n316'>316</a>
<a id='n317' href='#n317'>317</a>
<a id='n318' href='#n318'>318</a>
<a id='n319' href='#n319'>319</a>
<a id='n320' href='#n320'>320</a>
<a id='n321' href='#n321'>321</a>
<a id='n322' href='#n322'>322</a>
<a id='n323' href='#n323'>323</a>
<a id='n324' href='#n324'>324</a>
<a id='n325' href='#n325'>325</a>
<a id='n326' href='#n326'>326</a>
<a id='n327' href='#n327'>327</a>
<a id='n328' href='#n328'>328</a>
<a id='n329' href='#n329'>329</a>
<a id='n330' href='#n330'>330</a>
<a id='n331' href='#n331'>331</a>
<a id='n332' href='#n332'>332</a>
<a id='n333' href='#n333'>333</a>
<a id='n334' href='#n334'>334</a>
<a id='n335' href='#n335'>335</a>
<a id='n336' href='#n336'>336</a>
<a id='n337' href='#n337'>337</a>
<a id='n338' href='#n338'>338</a>
<a id='n339' href='#n339'>339</a>
<a id='n340' href='#n340'>340</a>
<a id='n341' href='#n341'>341</a>
<a id='n342' href='#n342'>342</a>
<a id='n343' href='#n343'>343</a>
<a id='n344' href='#n344'>344</a>
<a id='n345' href='#n345'>345</a>
<a id='n346' href='#n346'>346</a>
<a id='n347' href='#n347'>347</a>
<a id='n348' href='#n348'>348</a>
<a id='n349' href='#n349'>349</a>
<a id='n350' href='#n350'>350</a>
<a id='n351' href='#n351'>351</a>
<a id='n352' href='#n352'>352</a>
<a id='n353' href='#n353'>353</a>
<a id='n354' href='#n354'>354</a>
<a id='n355' href='#n355'>355</a>
<a id='n356' href='#n356'>356</a>
<a id='n357' href='#n357'>357</a>
<a id='n358' href='#n358'>358</a>
<a id='n359' href='#n359'>359</a>
<a id='n360' href='#n360'>360</a>
<a id='n361' href='#n361'>361</a>
<a id='n362' href='#n362'>362</a>
<a id='n363' href='#n363'>363</a>
<a id='n364' href='#n364'>364</a>
<a id='n365' href='#n365'>365</a>
<a id='n366' href='#n366'>366</a>
<a id='n367' href='#n367'>367</a>
<a id='n368' href='#n368'>368</a>
<a id='n369' href='#n369'>369</a>
<a id='n370' href='#n370'>370</a>
<a id='n371' href='#n371'>371</a>
<a id='n372' href='#n372'>372</a>
<a id='n373' href='#n373'>373</a>
<a id='n374' href='#n374'>374</a>
<a id='n375' href='#n375'>375</a>
<a id='n376' href='#n376'>376</a>
<a id='n377' href='#n377'>377</a>
<a id='n378' href='#n378'>378</a>
<a id='n379' href='#n379'>379</a>
<a id='n380' href='#n380'>380</a>
<a id='n381' href='#n381'>381</a>
<a id='n382' href='#n382'>382</a>
<a id='n383' href='#n383'>383</a>
<a id='n384' href='#n384'>384</a>
<a id='n385' href='#n385'>385</a>
<a id='n386' href='#n386'>386</a>
<a id='n387' href='#n387'>387</a>
<a id='n388' href='#n388'>388</a>
<a id='n389' href='#n389'>389</a>
<a id='n390' href='#n390'>390</a>
<a id='n391' href='#n391'>391</a>
<a id='n392' href='#n392'>392</a>
<a id='n393' href='#n393'>393</a>
<a id='n394' href='#n394'>394</a>
<a id='n395' href='#n395'>395</a>
<a id='n396' href='#n396'>396</a>
<a id='n397' href='#n397'>397</a>
<a id='n398' href='#n398'>398</a>
<a id='n399' href='#n399'>399</a>
<a id='n400' href='#n400'>400</a>
<a id='n401' href='#n401'>401</a>
<a id='n402' href='#n402'>402</a>
<a id='n403' href='#n403'>403</a>
<a id='n404' href='#n404'>404</a>
<a id='n405' href='#n405'>405</a>
<a id='n406' href='#n406'>406</a>
<a id='n407' href='#n407'>407</a>
<a id='n408' href='#n408'>408</a>
<a id='n409' href='#n409'>409</a>
<a id='n410' href='#n410'>410</a>
<a id='n411' href='#n411'>411</a>
<a id='n412' href='#n412'>412</a>
<a id='n413' href='#n413'>413</a>
<a id='n414' href='#n414'>414</a>
<a id='n415' href='#n415'>415</a>
<a id='n416' href='#n416'>416</a>
<a id='n417' href='#n417'>417</a>
<a id='n418' href='#n418'>418</a>
<a id='n419' href='#n419'>419</a>
<a id='n420' href='#n420'>420</a>
<a id='n421' href='#n421'>421</a>
<a id='n422' href='#n422'>422</a>
<a id='n423' href='#n423'>423</a>
<a id='n424' href='#n424'>424</a>
<a id='n425' href='#n425'>425</a>
<a id='n426' href='#n426'>426</a>
<a id='n427' href='#n427'>427</a>
<a id='n428' href='#n428'>428</a>
<a id='n429' href='#n429'>429</a>
<a id='n430' href='#n430'>430</a>
<a id='n431' href='#n431'>431</a>
<a id='n432' href='#n432'>432</a>
<a id='n433' href='#n433'>433</a>
<a id='n434' href='#n434'>434</a>
<a id='n435' href='#n435'>435</a>
<a id='n436' href='#n436'>436</a>
<a id='n437' href='#n437'>437</a>
<a id='n438' href='#n438'>438</a>
<a id='n439' href='#n439'>439</a>
<a id='n440' href='#n440'>440</a>
<a id='n441' href='#n441'>441</a>
<a id='n442' href='#n442'>442</a>
<a id='n443' href='#n443'>443</a>
<a id='n444' href='#n444'>444</a>
<a id='n445' href='#n445'>445</a>
<a id='n446' href='#n446'>446</a>
<a id='n447' href='#n447'>447</a>
<a id='n448' href='#n448'>448</a>
<a id='n449' href='#n449'>449</a>
<a id='n450' href='#n450'>450</a>
<a id='n451' href='#n451'>451</a>
<a id='n452' href='#n452'>452</a>
<a id='n453' href='#n453'>453</a>
<a id='n454' href='#n454'>454</a>
<a id='n455' href='#n455'>455</a>
<a id='n456' href='#n456'>456</a>
<a id='n457' href='#n457'>457</a>
<a id='n458' href='#n458'>458</a>
<a id='n459' href='#n459'>459</a>
<a id='n460' href='#n460'>460</a>
<a id='n461' href='#n461'>461</a>
<a id='n462' href='#n462'>462</a>
<a id='n463' href='#n463'>463</a>
<a id='n464' href='#n464'>464</a>
<a id='n465' href='#n465'>465</a>
<a id='n466' href='#n466'>466</a>
<a id='n467' href='#n467'>467</a>
<a id='n468' href='#n468'>468</a>
<a id='n469' href='#n469'>469</a>
<a id='n470' href='#n470'>470</a>
<a id='n471' href='#n471'>471</a>
<a id='n472' href='#n472'>472</a>
<a id='n473' href='#n473'>473</a>
<a id='n474' href='#n474'>474</a>
<a id='n475' href='#n475'>475</a>
<a id='n476' href='#n476'>476</a>
<a id='n477' href='#n477'>477</a>
<a id='n478' href='#n478'>478</a>
<a id='n479' href='#n479'>479</a>
<a id='n480' href='#n480'>480</a>
<a id='n481' href='#n481'>481</a>
<a id='n482' href='#n482'>482</a>
<a id='n483' href='#n483'>483</a>
<a id='n484' href='#n484'>484</a>
<a id='n485' href='#n485'>485</a>
<a id='n486' href='#n486'>486</a>
<a id='n487' href='#n487'>487</a>
<a id='n488' href='#n488'>488</a>
<a id='n489' href='#n489'>489</a>
<a id='n490' href='#n490'>490</a>
<a id='n491' href='#n491'>491</a>
<a id='n492' href='#n492'>492</a>
<a id='n493' href='#n493'>493</a>
<a id='n494' href='#n494'>494</a>
<a id='n495' href='#n495'>495</a>
<a id='n496' href='#n496'>496</a>
<a id='n497' href='#n497'>497</a>
<a id='n498' href='#n498'>498</a>
<a id='n499' href='#n499'>499</a>
<a id='n500' href='#n500'>500</a>
<a id='n501' href='#n501'>501</a>
<a id='n502' href='#n502'>502</a>
<a id='n503' href='#n503'>503</a>
<a id='n504' href='#n504'>504</a>
<a id='n505' href='#n505'>505</a>
<a id='n506' href='#n506'>506</a>
<a id='n507' href='#n507'>507</a>
<a id='n508' href='#n508'>508</a>
<a id='n509' href='#n509'>509</a>
<a id='n510' href='#n510'>510</a>
<a id='n511' href='#n511'>511</a>
<a id='n512' href='#n512'>512</a>
<a id='n513' href='#n513'>513</a>
<a id='n514' href='#n514'>514</a>
<a id='n515' href='#n515'>515</a>
<a id='n516' href='#n516'>516</a>
<a id='n517' href='#n517'>517</a>
<a id='n518' href='#n518'>518</a>
<a id='n519' href='#n519'>519</a>
<a id='n520' href='#n520'>520</a>
<a id='n521' href='#n521'>521</a>
<a id='n522' href='#n522'>522</a>
<a id='n523' href='#n523'>523</a>
<a id='n524' href='#n524'>524</a>
<a id='n525' href='#n525'>525</a>
<a id='n526' href='#n526'>526</a>
<a id='n527' href='#n527'>527</a>
<a id='n528' href='#n528'>528</a>
<a id='n529' href='#n529'>529</a>
<a id='n530' href='#n530'>530</a>
<a id='n531' href='#n531'>531</a>
<a id='n532' href='#n532'>532</a>
<a id='n533' href='#n533'>533</a>
<a id='n534' href='#n534'>534</a>
<a id='n535' href='#n535'>535</a>
<a id='n536' href='#n536'>536</a>
<a id='n537' href='#n537'>537</a>
<a id='n538' href='#n538'>538</a>
<a id='n539' href='#n539'>539</a>
<a id='n540' href='#n540'>540</a>
<a id='n541' href='#n541'>541</a>
<a id='n542' href='#n542'>542</a>
<a id='n543' href='#n543'>543</a>
<a id='n544' href='#n544'>544</a>
<a id='n545' href='#n545'>545</a>
<a id='n546' href='#n546'>546</a>
<a id='n547' href='#n547'>547</a>
<a id='n548' href='#n548'>548</a>
<a id='n549' href='#n549'>549</a>
<a id='n550' href='#n550'>550</a>
<a id='n551' href='#n551'>551</a>
<a id='n552' href='#n552'>552</a>
<a id='n553' href='#n553'>553</a>
<a id='n554' href='#n554'>554</a>
<a id='n555' href='#n555'>555</a>
<a id='n556' href='#n556'>556</a>
<a id='n557' href='#n557'>557</a>
<a id='n558' href='#n558'>558</a>
<a id='n559' href='#n559'>559</a>
<a id='n560' href='#n560'>560</a>
<a id='n561' href='#n561'>561</a>
<a id='n562' href='#n562'>562</a>
<a id='n563' href='#n563'>563</a>
<a id='n564' href='#n564'>564</a>
<a id='n565' href='#n565'>565</a>
<a id='n566' href='#n566'>566</a>
<a id='n567' href='#n567'>567</a>
<a id='n568' href='#n568'>568</a>
<a id='n569' href='#n569'>569</a>
<a id='n570' href='#n570'>570</a>
<a id='n571' href='#n571'>571</a>
<a id='n572' href='#n572'>572</a>
<a id='n573' href='#n573'>573</a>
<a id='n574' href='#n574'>574</a>
<a id='n575' href='#n575'>575</a>
<a id='n576' href='#n576'>576</a>
<a id='n577' href='#n577'>577</a>
<a id='n578' href='#n578'>578</a>
<a id='n579' href='#n579'>579</a>
<a id='n580' href='#n580'>580</a>
<a id='n581' href='#n581'>581</a>
<a id='n582' href='#n582'>582</a>
<a id='n583' href='#n583'>583</a>
<a id='n584' href='#n584'>584</a>
<a id='n585' href='#n585'>585</a>
<a id='n586' href='#n586'>586</a>
<a id='n587' href='#n587'>587</a>
<a id='n588' href='#n588'>588</a>
<a id='n589' href='#n589'>589</a>
<a id='n590' href='#n590'>590</a>
<a id='n591' href='#n591'>591</a>
<a id='n592' href='#n592'>592</a>
<a id='n593' href='#n593'>593</a>
<a id='n594' href='#n594'>594</a>
<a id='n595' href='#n595'>595</a>
<a id='n596' href='#n596'>596</a>
<a id='n597' href='#n597'>597</a>
<a id='n598' href='#n598'>598</a>
<a id='n599' href='#n599'>599</a>
<a id='n600' href='#n600'>600</a>
<a id='n601' href='#n601'>601</a>
<a id='n602' href='#n602'>602</a>
<a id='n603' href='#n603'>603</a>
<a id='n604' href='#n604'>604</a>
<a id='n605' href='#n605'>605</a>
<a id='n606' href='#n606'>606</a>
<a id='n607' href='#n607'>607</a>
<a id='n608' href='#n608'>608</a>
<a id='n609' href='#n609'>609</a>
<a id='n610' href='#n610'>610</a>
<a id='n611' href='#n611'>611</a>
<a id='n612' href='#n612'>612</a>
<a id='n613' href='#n613'>613</a>
<a id='n614' href='#n614'>614</a>
<a id='n615' href='#n615'>615</a>
<a id='n616' href='#n616'>616</a>
<a id='n617' href='#n617'>617</a>
<a id='n618' href='#n618'>618</a>
<a id='n619' href='#n619'>619</a>
<a id='n620' href='#n620'>620</a>
<a id='n621' href='#n621'>621</a>
<a id='n622' href='#n622'>622</a>
<a id='n623' href='#n623'>623</a>
<a id='n624' href='#n624'>624</a>
<a id='n625' href='#n625'>625</a>
<a id='n626' href='#n626'>626</a>
<a id='n627' href='#n627'>627</a>
<a id='n628' href='#n628'>628</a>
<a id='n629' href='#n629'>629</a>
<a id='n630' href='#n630'>630</a>
<a id='n631' href='#n631'>631</a>
<a id='n632' href='#n632'>632</a>
<a id='n633' href='#n633'>633</a>
<a id='n634' href='#n634'>634</a>
<a id='n635' href='#n635'>635</a>
<a id='n636' href='#n636'>636</a>
<a id='n637' href='#n637'>637</a>
<a id='n638' href='#n638'>638</a>
<a id='n639' href='#n639'>639</a>
<a id='n640' href='#n640'>640</a>
<a id='n641' href='#n641'>641</a>
<a id='n642' href='#n642'>642</a>
<a id='n643' href='#n643'>643</a>
<a id='n644' href='#n644'>644</a>
<a id='n645' href='#n645'>645</a>
<a id='n646' href='#n646'>646</a>
<a id='n647' href='#n647'>647</a>
<a id='n648' href='#n648'>648</a>
<a id='n649' href='#n649'>649</a>
<a id='n650' href='#n650'>650</a>
<a id='n651' href='#n651'>651</a>
<a id='n652' href='#n652'>652</a>
<a id='n653' href='#n653'>653</a>
<a id='n654' href='#n654'>654</a>
<a id='n655' href='#n655'>655</a>
<a id='n656' href='#n656'>656</a>
<a id='n657' href='#n657'>657</a>
<a id='n658' href='#n658'>658</a>
<a id='n659' href='#n659'>659</a>
<a id='n660' href='#n660'>660</a>
<a id='n661' href='#n661'>661</a>
<a id='n662' href='#n662'>662</a>
<a id='n663' href='#n663'>663</a>
<a id='n664' href='#n664'>664</a>
<a id='n665' href='#n665'>665</a>
<a id='n666' href='#n666'>666</a>
<a id='n667' href='#n667'>667</a>
<a id='n668' href='#n668'>668</a>
<a id='n669' href='#n669'>669</a>
<a id='n670' href='#n670'>670</a>
<a id='n671' href='#n671'>671</a>
<a id='n672' href='#n672'>672</a>
<a id='n673' href='#n673'>673</a>
<a id='n674' href='#n674'>674</a>
<a id='n675' href='#n675'>675</a>
<a id='n676' href='#n676'>676</a>
<a id='n677' href='#n677'>677</a>
<a id='n678' href='#n678'>678</a>
<a id='n679' href='#n679'>679</a>
<a id='n680' href='#n680'>680</a>
<a id='n681' href='#n681'>681</a>
<a id='n682' href='#n682'>682</a>
<a id='n683' href='#n683'>683</a>
<a id='n684' href='#n684'>684</a>
<a id='n685' href='#n685'>685</a>
<a id='n686' href='#n686'>686</a>
<a id='n687' href='#n687'>687</a>
<a id='n688' href='#n688'>688</a>
<a id='n689' href='#n689'>689</a>
<a id='n690' href='#n690'>690</a>
<a id='n691' href='#n691'>691</a>
<a id='n692' href='#n692'>692</a>
<a id='n693' href='#n693'>693</a>
<a id='n694' href='#n694'>694</a>
<a id='n695' href='#n695'>695</a>
<a id='n696' href='#n696'>696</a>
<a id='n697' href='#n697'>697</a>
<a id='n698' href='#n698'>698</a>
<a id='n699' href='#n699'>699</a>
<a id='n700' href='#n700'>700</a>
<a id='n701' href='#n701'>701</a>
<a id='n702' href='#n702'>702</a>
<a id='n703' href='#n703'>703</a>
<a id='n704' href='#n704'>704</a>
<a id='n705' href='#n705'>705</a>
<a id='n706' href='#n706'>706</a>
<a id='n707' href='#n707'>707</a>
<a id='n708' href='#n708'>708</a>
<a id='n709' href='#n709'>709</a>
<a id='n710' href='#n710'>710</a>
<a id='n711' href='#n711'>711</a>
<a id='n712' href='#n712'>712</a>
<a id='n713' href='#n713'>713</a>
<a id='n714' href='#n714'>714</a>
<a id='n715' href='#n715'>715</a>
<a id='n716' href='#n716'>716</a>
<a id='n717' href='#n717'>717</a>
<a id='n718' href='#n718'>718</a>
<a id='n719' href='#n719'>719</a>
<a id='n720' href='#n720'>720</a>
<a id='n721' href='#n721'>721</a>
<a id='n722' href='#n722'>722</a>
<a id='n723' href='#n723'>723</a>
<a id='n724' href='#n724'>724</a>
<a id='n725' href='#n725'>725</a>
<a id='n726' href='#n726'>726</a>
<a id='n727' href='#n727'>727</a>
<a id='n728' href='#n728'>728</a>
<a id='n729' href='#n729'>729</a>
<a id='n730' href='#n730'>730</a>
<a id='n731' href='#n731'>731</a>
<a id='n732' href='#n732'>732</a>
<a id='n733' href='#n733'>733</a>
<a id='n734' href='#n734'>734</a>
<a id='n735' href='#n735'>735</a>
<a id='n736' href='#n736'>736</a>
<a id='n737' href='#n737'>737</a>
<a id='n738' href='#n738'>738</a>
<a id='n739' href='#n739'>739</a>
<a id='n740' href='#n740'>740</a>
<a id='n741' href='#n741'>741</a>
<a id='n742' href='#n742'>742</a>
<a id='n743' href='#n743'>743</a>
<a id='n744' href='#n744'>744</a>
<a id='n745' href='#n745'>745</a>
<a id='n746' href='#n746'>746</a>
<a id='n747' href='#n747'>747</a>
<a id='n748' href='#n748'>748</a>
<a id='n749' href='#n749'>749</a>
<a id='n750' href='#n750'>750</a>
<a id='n751' href='#n751'>751</a>
<a id='n752' href='#n752'>752</a>
<a id='n753' href='#n753'>753</a>
<a id='n754' href='#n754'>754</a>
<a id='n755' href='#n755'>755</a>
<a id='n756' href='#n756'>756</a>
<a id='n757' href='#n757'>757</a>
<a id='n758' href='#n758'>758</a>
<a id='n759' href='#n759'>759</a>
<a id='n760' href='#n760'>760</a>
<a id='n761' href='#n761'>761</a>
<a id='n762' href='#n762'>762</a>
<a id='n763' href='#n763'>763</a>
<a id='n764' href='#n764'>764</a>
<a id='n765' href='#n765'>765</a>
<a id='n766' href='#n766'>766</a>
<a id='n767' href='#n767'>767</a>
<a id='n768' href='#n768'>768</a>
<a id='n769' href='#n769'>769</a>
<a id='n770' href='#n770'>770</a>
<a id='n771' href='#n771'>771</a>
<a id='n772' href='#n772'>772</a>
<a id='n773' href='#n773'>773</a>
<a id='n774' href='#n774'>774</a>
<a id='n775' href='#n775'>775</a>
<a id='n776' href='#n776'>776</a>
<a id='n777' href='#n777'>777</a>
<a id='n778' href='#n778'>778</a>
<a id='n779' href='#n779'>779</a>
<a id='n780' href='#n780'>780</a>
<a id='n781' href='#n781'>781</a>
<a id='n782' href='#n782'>782</a>
<a id='n783' href='#n783'>783</a>
<a id='n784' href='#n784'>784</a>
<a id='n785' href='#n785'>785</a>
<a id='n786' href='#n786'>786</a>
<a id='n787' href='#n787'>787</a>
<a id='n788' href='#n788'>788</a>
<a id='n789' href='#n789'>789</a>
<a id='n790' href='#n790'>790</a>
<a id='n791' href='#n791'>791</a>
<a id='n792' href='#n792'>792</a>
<a id='n793' href='#n793'>793</a>
<a id='n794' href='#n794'>794</a>
<a id='n795' href='#n795'>795</a>
<a id='n796' href='#n796'>796</a>
<a id='n797' href='#n797'>797</a>
<a id='n798' href='#n798'>798</a>
<a id='n799' href='#n799'>799</a>
<a id='n800' href='#n800'>800</a>
<a id='n801' href='#n801'>801</a>
<a id='n802' href='#n802'>802</a>
<a id='n803' href='#n803'>803</a>
<a id='n804' href='#n804'>804</a>
<a id='n805' href='#n805'>805</a>
<a id='n806' href='#n806'>806</a>
<a id='n807' href='#n807'>807</a>
<a id='n808' href='#n808'>808</a>
<a id='n809' href='#n809'>809</a>
<a id='n810' href='#n810'>810</a>
<a id='n811' href='#n811'>811</a>
<a id='n812' href='#n812'>812</a>
<a id='n813' href='#n813'>813</a>
<a id='n814' href='#n814'>814</a>
<a id='n815' href='#n815'>815</a>
<a id='n816' href='#n816'>816</a>
<a id='n817' href='#n817'>817</a>
<a id='n818' href='#n818'>818</a>
<a id='n819' href='#n819'>819</a>
<a id='n820' href='#n820'>820</a>
<a id='n821' href='#n821'>821</a>
<a id='n822' href='#n822'>822</a>
<a id='n823' href='#n823'>823</a>
<a id='n824' href='#n824'>824</a>
<a id='n825' href='#n825'>825</a>
<a id='n826' href='#n826'>826</a>
<a id='n827' href='#n827'>827</a>
<a id='n828' href='#n828'>828</a>
<a id='n829' href='#n829'>829</a>
<a id='n830' href='#n830'>830</a>
<a id='n831' href='#n831'>831</a>
<a id='n832' href='#n832'>832</a>
<a id='n833' href='#n833'>833</a>
<a id='n834' href='#n834'>834</a>
<a id='n835' href='#n835'>835</a>
<a id='n836' href='#n836'>836</a>
<a id='n837' href='#n837'>837</a>
<a id='n838' href='#n838'>838</a>
<a id='n839' href='#n839'>839</a>
<a id='n840' href='#n840'>840</a>
<a id='n841' href='#n841'>841</a>
<a id='n842' href='#n842'>842</a>
<a id='n843' href='#n843'>843</a>
<a id='n844' href='#n844'>844</a>
<a id='n845' href='#n845'>845</a>
<a id='n846' href='#n846'>846</a>
<a id='n847' href='#n847'>847</a>
<a id='n848' href='#n848'>848</a>
<a id='n849' href='#n849'>849</a>
<a id='n850' href='#n850'>850</a>
<a id='n851' href='#n851'>851</a>
<a id='n852' href='#n852'>852</a>
<a id='n853' href='#n853'>853</a>
<a id='n854' href='#n854'>854</a>
<a id='n855' href='#n855'>855</a>
<a id='n856' href='#n856'>856</a>
<a id='n857' href='#n857'>857</a>
<a id='n858' href='#n858'>858</a>
<a id='n859' href='#n859'>859</a>
<a id='n860' href='#n860'>860</a>
<a id='n861' href='#n861'>861</a>
<a id='n862' href='#n862'>862</a>
<a id='n863' href='#n863'>863</a>
<a id='n864' href='#n864'>864</a>
<a id='n865' href='#n865'>865</a>
<a id='n866' href='#n866'>866</a>
<a id='n867' href='#n867'>867</a>
<a id='n868' href='#n868'>868</a>
<a id='n869' href='#n869'>869</a>
<a id='n870' href='#n870'>870</a>
<a id='n871' href='#n871'>871</a>
<a id='n872' href='#n872'>872</a>
<a id='n873' href='#n873'>873</a>
<a id='n874' href='#n874'>874</a>
<a id='n875' href='#n875'>875</a>
<a id='n876' href='#n876'>876</a>
<a id='n877' href='#n877'>877</a>
<a id='n878' href='#n878'>878</a>
<a id='n879' href='#n879'>879</a>
<a id='n880' href='#n880'>880</a>
<a id='n881' href='#n881'>881</a>
<a id='n882' href='#n882'>882</a>
<a id='n883' href='#n883'>883</a>
<a id='n884' href='#n884'>884</a>
<a id='n885' href='#n885'>885</a>
<a id='n886' href='#n886'>886</a>
<a id='n887' href='#n887'>887</a>
<a id='n888' href='#n888'>888</a>
<a id='n889' href='#n889'>889</a>
<a id='n890' href='#n890'>890</a>
<a id='n891' href='#n891'>891</a>
<a id='n892' href='#n892'>892</a>
<a id='n893' href='#n893'>893</a>
<a id='n894' href='#n894'>894</a>
<a id='n895' href='#n895'>895</a>
<a id='n896' href='#n896'>896</a>
<a id='n897' href='#n897'>897</a>
<a id='n898' href='#n898'>898</a>
<a id='n899' href='#n899'>899</a>
<a id='n900' href='#n900'>900</a>
<a id='n901' href='#n901'>901</a>
<a id='n902' href='#n902'>902</a>
<a id='n903' href='#n903'>903</a>
<a id='n904' href='#n904'>904</a>
<a id='n905' href='#n905'>905</a>
<a id='n906' href='#n906'>906</a>
<a id='n907' href='#n907'>907</a>
<a id='n908' href='#n908'>908</a>
<a id='n909' href='#n909'>909</a>
<a id='n910' href='#n910'>910</a>
<a id='n911' href='#n911'>911</a>
<a id='n912' href='#n912'>912</a>
<a id='n913' href='#n913'>913</a>
<a id='n914' href='#n914'>914</a>
<a id='n915' href='#n915'>915</a>
<a id='n916' href='#n916'>916</a>
<a id='n917' href='#n917'>917</a>
<a id='n918' href='#n918'>918</a>
<a id='n919' href='#n919'>919</a>
<a id='n920' href='#n920'>920</a>
<a id='n921' href='#n921'>921</a>
<a id='n922' href='#n922'>922</a>
<a id='n923' href='#n923'>923</a>
<a id='n924' href='#n924'>924</a>
<a id='n925' href='#n925'>925</a>
<a id='n926' href='#n926'>926</a>
<a id='n927' href='#n927'>927</a>
<a id='n928' href='#n928'>928</a>
<a id='n929' href='#n929'>929</a>
<a id='n930' href='#n930'>930</a>
<a id='n931' href='#n931'>931</a>
<a id='n932' href='#n932'>932</a>
<a id='n933' href='#n933'>933</a>
<a id='n934' href='#n934'>934</a>
<a id='n935' href='#n935'>935</a>
<a id='n936' href='#n936'>936</a>
<a id='n937' href='#n937'>937</a>
<a id='n938' href='#n938'>938</a>
<a id='n939' href='#n939'>939</a>
<a id='n940' href='#n940'>940</a>
<a id='n941' href='#n941'>941</a>
<a id='n942' href='#n942'>942</a>
<a id='n943' href='#n943'>943</a>
<a id='n944' href='#n944'>944</a>
<a id='n945' href='#n945'>945</a>
<a id='n946' href='#n946'>946</a>
<a id='n947' href='#n947'>947</a>
<a id='n948' href='#n948'>948</a>
<a id='n949' href='#n949'>949</a>
<a id='n950' href='#n950'>950</a>
<a id='n951' href='#n951'>951</a>
<a id='n952' href='#n952'>952</a>
<a id='n953' href='#n953'>953</a>
<a id='n954' href='#n954'>954</a>
<a id='n955' href='#n955'>955</a>
<a id='n956' href='#n956'>956</a>
<a id='n957' href='#n957'>957</a>
<a id='n958' href='#n958'>958</a>
<a id='n959' href='#n959'>959</a>
<a id='n960' href='#n960'>960</a>
<a id='n961' href='#n961'>961</a>
<a id='n962' href='#n962'>962</a>
<a id='n963' href='#n963'>963</a>
<a id='n964' href='#n964'>964</a>
<a id='n965' href='#n965'>965</a>
<a id='n966' href='#n966'>966</a>
<a id='n967' href='#n967'>967</a>
<a id='n968' href='#n968'>968</a>
<a id='n969' href='#n969'>969</a>
<a id='n970' href='#n970'>970</a>
<a id='n971' href='#n971'>971</a>
<a id='n972' href='#n972'>972</a>
<a id='n973' href='#n973'>973</a>
<a id='n974' href='#n974'>974</a>
<a id='n975' href='#n975'>975</a>
<a id='n976' href='#n976'>976</a>
<a id='n977' href='#n977'>977</a>
<a id='n978' href='#n978'>978</a>
<a id='n979' href='#n979'>979</a>
<a id='n980' href='#n980'>980</a>
<a id='n981' href='#n981'>981</a>
<a id='n982' href='#n982'>982</a>
<a id='n983' href='#n983'>983</a>
<a id='n984' href='#n984'>984</a>
<a id='n985' href='#n985'>985</a>
<a id='n986' href='#n986'>986</a>
<a id='n987' href='#n987'>987</a>
<a id='n988' href='#n988'>988</a>
<a id='n989' href='#n989'>989</a>
<a id='n990' href='#n990'>990</a>
<a id='n991' href='#n991'>991</a>
<a id='n992' href='#n992'>992</a>
<a id='n993' href='#n993'>993</a>
<a id='n994' href='#n994'>994</a>
<a id='n995' href='#n995'>995</a>
<a id='n996' href='#n996'>996</a>
<a id='n997' href='#n997'>997</a>
<a id='n998' href='#n998'>998</a>
<a id='n999' href='#n999'>999</a>
<a id='n1000' href='#n1000'>1000</a>
<a id='n1001' href='#n1001'>1001</a>
<a id='n1002' href='#n1002'>1002</a>
<a id='n1003' href='#n1003'>1003</a>
<a id='n1004' href='#n1004'>1004</a>
<a id='n1005' href='#n1005'>1005</a>
<a id='n1006' href='#n1006'>1006</a>
<a id='n1007' href='#n1007'>1007</a>
<a id='n1008' href='#n1008'>1008</a>
<a id='n1009' href='#n1009'>1009</a>
<a id='n1010' href='#n1010'>1010</a>
<a id='n1011' href='#n1011'>1011</a>
<a id='n1012' href='#n1012'>1012</a>
<a id='n1013' href='#n1013'>1013</a>
<a id='n1014' href='#n1014'>1014</a>
<a id='n1015' href='#n1015'>1015</a>
<a id='n1016' href='#n1016'>1016</a>
<a id='n1017' href='#n1017'>1017</a>
<a id='n1018' href='#n1018'>1018</a>
<a id='n1019' href='#n1019'>1019</a>
<a id='n1020' href='#n1020'>1020</a>
<a id='n1021' href='#n1021'>1021</a>
<a id='n1022' href='#n1022'>1022</a>
<a id='n1023' href='#n1023'>1023</a>
<a id='n1024' href='#n1024'>1024</a>
<a id='n1025' href='#n1025'>1025</a>
<a id='n1026' href='#n1026'>1026</a>
<a id='n1027' href='#n1027'>1027</a>
<a id='n1028' href='#n1028'>1028</a>
<a id='n1029' href='#n1029'>1029</a>
<a id='n1030' href='#n1030'>1030</a>
<a id='n1031' href='#n1031'>1031</a>
<a id='n1032' href='#n1032'>1032</a>
<a id='n1033' href='#n1033'>1033</a>
<a id='n1034' href='#n1034'>1034</a>
<a id='n1035' href='#n1035'>1035</a>
<a id='n1036' href='#n1036'>1036</a>
<a id='n1037' href='#n1037'>1037</a>
<a id='n1038' href='#n1038'>1038</a>
<a id='n1039' href='#n1039'>1039</a>
<a id='n1040' href='#n1040'>1040</a>
<a id='n1041' href='#n1041'>1041</a>
<a id='n1042' href='#n1042'>1042</a>
<a id='n1043' href='#n1043'>1043</a>
<a id='n1044' href='#n1044'>1044</a>
<a id='n1045' href='#n1045'>1045</a>
<a id='n1046' href='#n1046'>1046</a>
<a id='n1047' href='#n1047'>1047</a>
<a id='n1048' href='#n1048'>1048</a>
<a id='n1049' href='#n1049'>1049</a>
<a id='n1050' href='#n1050'>1050</a>
<a id='n1051' href='#n1051'>1051</a>
<a id='n1052' href='#n1052'>1052</a>
<a id='n1053' href='#n1053'>1053</a>
<a id='n1054' href='#n1054'>1054</a>
<a id='n1055' href='#n1055'>1055</a>
<a id='n1056' href='#n1056'>1056</a>
<a id='n1057' href='#n1057'>1057</a>
<a id='n1058' href='#n1058'>1058</a>
<a id='n1059' href='#n1059'>1059</a>
<a id='n1060' href='#n1060'>1060</a>
<a id='n1061' href='#n1061'>1061</a>
<a id='n1062' href='#n1062'>1062</a>
<a id='n1063' href='#n1063'>1063</a>
<a id='n1064' href='#n1064'>1064</a>
<a id='n1065' href='#n1065'>1065</a>
<a id='n1066' href='#n1066'>1066</a>
<a id='n1067' href='#n1067'>1067</a>
<a id='n1068' href='#n1068'>1068</a>
<a id='n1069' href='#n1069'>1069</a>
<a id='n1070' href='#n1070'>1070</a>
<a id='n1071' href='#n1071'>1071</a>
<a id='n1072' href='#n1072'>1072</a>
<a id='n1073' href='#n1073'>1073</a>
<a id='n1074' href='#n1074'>1074</a>
<a id='n1075' href='#n1075'>1075</a>
<a id='n1076' href='#n1076'>1076</a>
<a id='n1077' href='#n1077'>1077</a>
<a id='n1078' href='#n1078'>1078</a>
<a id='n1079' href='#n1079'>1079</a>
<a id='n1080' href='#n1080'>1080</a>
<a id='n1081' href='#n1081'>1081</a>
<a id='n1082' href='#n1082'>1082</a>
<a id='n1083' href='#n1083'>1083</a>
<a id='n1084' href='#n1084'>1084</a>
<a id='n1085' href='#n1085'>1085</a>
<a id='n1086' href='#n1086'>1086</a>
<a id='n1087' href='#n1087'>1087</a>
<a id='n1088' href='#n1088'>1088</a>
<a id='n1089' href='#n1089'>1089</a>
<a id='n1090' href='#n1090'>1090</a>
<a id='n1091' href='#n1091'>1091</a>
<a id='n1092' href='#n1092'>1092</a>
<a id='n1093' href='#n1093'>1093</a>
<a id='n1094' href='#n1094'>1094</a>
<a id='n1095' href='#n1095'>1095</a>
<a id='n1096' href='#n1096'>1096</a>
<a id='n1097' href='#n1097'>1097</a>
<a id='n1098' href='#n1098'>1098</a>
<a id='n1099' href='#n1099'>1099</a>
<a id='n1100' href='#n1100'>1100</a>
<a id='n1101' href='#n1101'>1101</a>
<a id='n1102' href='#n1102'>1102</a>
<a id='n1103' href='#n1103'>1103</a>
<a id='n1104' href='#n1104'>1104</a>
<a id='n1105' href='#n1105'>1105</a>
<a id='n1106' href='#n1106'>1106</a>
<a id='n1107' href='#n1107'>1107</a>
<a id='n1108' href='#n1108'>1108</a>
<a id='n1109' href='#n1109'>1109</a>
<a id='n1110' href='#n1110'>1110</a>
<a id='n1111' href='#n1111'>1111</a>
<a id='n1112' href='#n1112'>1112</a>
<a id='n1113' href='#n1113'>1113</a>
<a id='n1114' href='#n1114'>1114</a>
<a id='n1115' href='#n1115'>1115</a>
<a id='n1116' href='#n1116'>1116</a>
<a id='n1117' href='#n1117'>1117</a>
<a id='n1118' href='#n1118'>1118</a>
<a id='n1119' href='#n1119'>1119</a>
<a id='n1120' href='#n1120'>1120</a>
<a id='n1121' href='#n1121'>1121</a>
<a id='n1122' href='#n1122'>1122</a>
<a id='n1123' href='#n1123'>1123</a>
<a id='n1124' href='#n1124'>1124</a>
<a id='n1125' href='#n1125'>1125</a>
<a id='n1126' href='#n1126'>1126</a>
<a id='n1127' href='#n1127'>1127</a>
<a id='n1128' href='#n1128'>1128</a>
<a id='n1129' href='#n1129'>1129</a>
<a id='n1130' href='#n1130'>1130</a>
<a id='n1131' href='#n1131'>1131</a>
<a id='n1132' href='#n1132'>1132</a>
<a id='n1133' href='#n1133'>1133</a>
<a id='n1134' href='#n1134'>1134</a>
<a id='n1135' href='#n1135'>1135</a>
<a id='n1136' href='#n1136'>1136</a>
<a id='n1137' href='#n1137'>1137</a>
<a id='n1138' href='#n1138'>1138</a>
<a id='n1139' href='#n1139'>1139</a>
<a id='n1140' href='#n1140'>1140</a>
<a id='n1141' href='#n1141'>1141</a>
<a id='n1142' href='#n1142'>1142</a>
<a id='n1143' href='#n1143'>1143</a>
<a id='n1144' href='#n1144'>1144</a>
<a id='n1145' href='#n1145'>1145</a>
<a id='n1146' href='#n1146'>1146</a>
<a id='n1147' href='#n1147'>1147</a>
<a id='n1148' href='#n1148'>1148</a>
<a id='n1149' href='#n1149'>1149</a>
<a id='n1150' href='#n1150'>1150</a>
<a id='n1151' href='#n1151'>1151</a>
<a id='n1152' href='#n1152'>1152</a>
<a id='n1153' href='#n1153'>1153</a>
<a id='n1154' href='#n1154'>1154</a>
<a id='n1155' href='#n1155'>1155</a>
<a id='n1156' href='#n1156'>1156</a>
<a id='n1157' href='#n1157'>1157</a>
<a id='n1158' href='#n1158'>1158</a>
<a id='n1159' href='#n1159'>1159</a>
<a id='n1160' href='#n1160'>1160</a>
<a id='n1161' href='#n1161'>1161</a>
<a id='n1162' href='#n1162'>1162</a>
<a id='n1163' href='#n1163'>1163</a>
<a id='n1164' href='#n1164'>1164</a>
<a id='n1165' href='#n1165'>1165</a>
<a id='n1166' href='#n1166'>1166</a>
<a id='n1167' href='#n1167'>1167</a>
<a id='n1168' href='#n1168'>1168</a>
<a id='n1169' href='#n1169'>1169</a>
<a id='n1170' href='#n1170'>1170</a>
<a id='n1171' href='#n1171'>1171</a>
<a id='n1172' href='#n1172'>1172</a>
<a id='n1173' href='#n1173'>1173</a>
<a id='n1174' href='#n1174'>1174</a>
<a id='n1175' href='#n1175'>1175</a>
<a id='n1176' href='#n1176'>1176</a>
<a id='n1177' href='#n1177'>1177</a>
<a id='n1178' href='#n1178'>1178</a>
<a id='n1179' href='#n1179'>1179</a>
<a id='n1180' href='#n1180'>1180</a>
<a id='n1181' href='#n1181'>1181</a>
<a id='n1182' href='#n1182'>1182</a>
<a id='n1183' href='#n1183'>1183</a>
<a id='n1184' href='#n1184'>1184</a>
<a id='n1185' href='#n1185'>1185</a>
<a id='n1186' href='#n1186'>1186</a>
<a id='n1187' href='#n1187'>1187</a>
<a id='n1188' href='#n1188'>1188</a>
<a id='n1189' href='#n1189'>1189</a>
<a id='n1190' href='#n1190'>1190</a>
<a id='n1191' href='#n1191'>1191</a>
<a id='n1192' href='#n1192'>1192</a>
<a id='n1193' href='#n1193'>1193</a>
<a id='n1194' href='#n1194'>1194</a>
<a id='n1195' href='#n1195'>1195</a>
<a id='n1196' href='#n1196'>1196</a>
<a id='n1197' href='#n1197'>1197</a>
<a id='n1198' href='#n1198'>1198</a>
<a id='n1199' href='#n1199'>1199</a>
<a id='n1200' href='#n1200'>1200</a>
<a id='n1201' href='#n1201'>1201</a>
<a id='n1202' href='#n1202'>1202</a>
<a id='n1203' href='#n1203'>1203</a>
<a id='n1204' href='#n1204'>1204</a>
<a id='n1205' href='#n1205'>1205</a>
<a id='n1206' href='#n1206'>1206</a>
<a id='n1207' href='#n1207'>1207</a>
<a id='n1208' href='#n1208'>1208</a>
<a id='n1209' href='#n1209'>1209</a>
<a id='n1210' href='#n1210'>1210</a>
<a id='n1211' href='#n1211'>1211</a>
<a id='n1212' href='#n1212'>1212</a>
<a id='n1213' href='#n1213'>1213</a>
<a id='n1214' href='#n1214'>1214</a>
<a id='n1215' href='#n1215'>1215</a>
<a id='n1216' href='#n1216'>1216</a>
<a id='n1217' href='#n1217'>1217</a>
<a id='n1218' href='#n1218'>1218</a>
<a id='n1219' href='#n1219'>1219</a>
<a id='n1220' href='#n1220'>1220</a>
<a id='n1221' href='#n1221'>1221</a>
<a id='n1222' href='#n1222'>1222</a>
<a id='n1223' href='#n1223'>1223</a>
<a id='n1224' href='#n1224'>1224</a>
<a id='n1225' href='#n1225'>1225</a>
<a id='n1226' href='#n1226'>1226</a>
<a id='n1227' href='#n1227'>1227</a>
<a id='n1228' href='#n1228'>1228</a>
<a id='n1229' href='#n1229'>1229</a>
<a id='n1230' href='#n1230'>1230</a>
<a id='n1231' href='#n1231'>1231</a>
<a id='n1232' href='#n1232'>1232</a>
<a id='n1233' href='#n1233'>1233</a>
<a id='n1234' href='#n1234'>1234</a>
<a id='n1235' href='#n1235'>1235</a>
<a id='n1236' href='#n1236'>1236</a>
<a id='n1237' href='#n1237'>1237</a>
<a id='n1238' href='#n1238'>1238</a>
<a id='n1239' href='#n1239'>1239</a>
<a id='n1240' href='#n1240'>1240</a>
<a id='n1241' href='#n1241'>1241</a>
<a id='n1242' href='#n1242'>1242</a>
<a id='n1243' href='#n1243'>1243</a>
<a id='n1244' href='#n1244'>1244</a>
<a id='n1245' href='#n1245'>1245</a>
<a id='n1246' href='#n1246'>1246</a>
<a id='n1247' href='#n1247'>1247</a>
<a id='n1248' href='#n1248'>1248</a>
<a id='n1249' href='#n1249'>1249</a>
<a id='n1250' href='#n1250'>1250</a>
<a id='n1251' href='#n1251'>1251</a>
<a id='n1252' href='#n1252'>1252</a>
<a id='n1253' href='#n1253'>1253</a>
<a id='n1254' href='#n1254'>1254</a>
<a id='n1255' href='#n1255'>1255</a>
<a id='n1256' href='#n1256'>1256</a>
<a id='n1257' href='#n1257'>1257</a>
<a id='n1258' href='#n1258'>1258</a>
<a id='n1259' href='#n1259'>1259</a>
<a id='n1260' href='#n1260'>1260</a>
<a id='n1261' href='#n1261'>1261</a>
<a id='n1262' href='#n1262'>1262</a>
<a id='n1263' href='#n1263'>1263</a>
<a id='n1264' href='#n1264'>1264</a>
<a id='n1265' href='#n1265'>1265</a>
<a id='n1266' href='#n1266'>1266</a>
<a id='n1267' href='#n1267'>1267</a>
<a id='n1268' href='#n1268'>1268</a>
<a id='n1269' href='#n1269'>1269</a>
<a id='n1270' href='#n1270'>1270</a>
<a id='n1271' href='#n1271'>1271</a>
<a id='n1272' href='#n1272'>1272</a>
<a id='n1273' href='#n1273'>1273</a>
<a id='n1274' href='#n1274'>1274</a>
<a id='n1275' href='#n1275'>1275</a>
<a id='n1276' href='#n1276'>1276</a>
<a id='n1277' href='#n1277'>1277</a>
<a id='n1278' href='#n1278'>1278</a>
<a id='n1279' href='#n1279'>1279</a>
<a id='n1280' href='#n1280'>1280</a>
<a id='n1281' href='#n1281'>1281</a>
<a id='n1282' href='#n1282'>1282</a>
<a id='n1283' href='#n1283'>1283</a>
<a id='n1284' href='#n1284'>1284</a>
<a id='n1285' href='#n1285'>1285</a>
<a id='n1286' href='#n1286'>1286</a>
<a id='n1287' href='#n1287'>1287</a>
<a id='n1288' href='#n1288'>1288</a>
<a id='n1289' href='#n1289'>1289</a>
<a id='n1290' href='#n1290'>1290</a>
<a id='n1291' href='#n1291'>1291</a>
<a id='n1292' href='#n1292'>1292</a>
<a id='n1293' href='#n1293'>1293</a>
<a id='n1294' href='#n1294'>1294</a>
<a id='n1295' href='#n1295'>1295</a>
<a id='n1296' href='#n1296'>1296</a>
<a id='n1297' href='#n1297'>1297</a>
<a id='n1298' href='#n1298'>1298</a>
<a id='n1299' href='#n1299'>1299</a>
<a id='n1300' href='#n1300'>1300</a>
<a id='n1301' href='#n1301'>1301</a>
<a id='n1302' href='#n1302'>1302</a>
<a id='n1303' href='#n1303'>1303</a>
<a id='n1304' href='#n1304'>1304</a>
<a id='n1305' href='#n1305'>1305</a>
<a id='n1306' href='#n1306'>1306</a>
<a id='n1307' href='#n1307'>1307</a>
<a id='n1308' href='#n1308'>1308</a>
<a id='n1309' href='#n1309'>1309</a>
<a id='n1310' href='#n1310'>1310</a>
<a id='n1311' href='#n1311'>1311</a>
<a id='n1312' href='#n1312'>1312</a>
<a id='n1313' href='#n1313'>1313</a>
<a id='n1314' href='#n1314'>1314</a>
<a id='n1315' href='#n1315'>1315</a>
<a id='n1316' href='#n1316'>1316</a>
<a id='n1317' href='#n1317'>1317</a>
<a id='n1318' href='#n1318'>1318</a>
<a id='n1319' href='#n1319'>1319</a>
<a id='n1320' href='#n1320'>1320</a>
<a id='n1321' href='#n1321'>1321</a>
<a id='n1322' href='#n1322'>1322</a>
<a id='n1323' href='#n1323'>1323</a>
<a id='n1324' href='#n1324'>1324</a>
<a id='n1325' href='#n1325'>1325</a>
<a id='n1326' href='#n1326'>1326</a>
<a id='n1327' href='#n1327'>1327</a>
<a id='n1328' href='#n1328'>1328</a>
<a id='n1329' href='#n1329'>1329</a>
<a id='n1330' href='#n1330'>1330</a>
<a id='n1331' href='#n1331'>1331</a>
<a id='n1332' href='#n1332'>1332</a>
<a id='n1333' href='#n1333'>1333</a>
<a id='n1334' href='#n1334'>1334</a>
<a id='n1335' href='#n1335'>1335</a>
<a id='n1336' href='#n1336'>1336</a>
<a id='n1337' href='#n1337'>1337</a>
<a id='n1338' href='#n1338'>1338</a>
<a id='n1339' href='#n1339'>1339</a>
<a id='n1340' href='#n1340'>1340</a>
<a id='n1341' href='#n1341'>1341</a>
<a id='n1342' href='#n1342'>1342</a>
<a id='n1343' href='#n1343'>1343</a>
<a id='n1344' href='#n1344'>1344</a>
<a id='n1345' href='#n1345'>1345</a>
<a id='n1346' href='#n1346'>1346</a>
<a id='n1347' href='#n1347'>1347</a>
<a id='n1348' href='#n1348'>1348</a>
<a id='n1349' href='#n1349'>1349</a>
<a id='n1350' href='#n1350'>1350</a>
<a id='n1351' href='#n1351'>1351</a>
<a id='n1352' href='#n1352'>1352</a>
<a id='n1353' href='#n1353'>1353</a>
<a id='n1354' href='#n1354'>1354</a>
<a id='n1355' href='#n1355'>1355</a>
<a id='n1356' href='#n1356'>1356</a>
<a id='n1357' href='#n1357'>1357</a>
<a id='n1358' href='#n1358'>1358</a>
<a id='n1359' href='#n1359'>1359</a>
<a id='n1360' href='#n1360'>1360</a>
<a id='n1361' href='#n1361'>1361</a>
<a id='n1362' href='#n1362'>1362</a>
<a id='n1363' href='#n1363'>1363</a>
<a id='n1364' href='#n1364'>1364</a>
<a id='n1365' href='#n1365'>1365</a>
<a id='n1366' href='#n1366'>1366</a>
<a id='n1367' href='#n1367'>1367</a>
<a id='n1368' href='#n1368'>1368</a>
<a id='n1369' href='#n1369'>1369</a>
<a id='n1370' href='#n1370'>1370</a>
<a id='n1371' href='#n1371'>1371</a>
<a id='n1372' href='#n1372'>1372</a>
<a id='n1373' href='#n1373'>1373</a>
<a id='n1374' href='#n1374'>1374</a>
<a id='n1375' href='#n1375'>1375</a>
<a id='n1376' href='#n1376'>1376</a>
<a id='n1377' href='#n1377'>1377</a>
<a id='n1378' href='#n1378'>1378</a>
<a id='n1379' href='#n1379'>1379</a>
<a id='n1380' href='#n1380'>1380</a>
<a id='n1381' href='#n1381'>1381</a>
<a id='n1382' href='#n1382'>1382</a>
<a id='n1383' href='#n1383'>1383</a>
<a id='n1384' href='#n1384'>1384</a>
<a id='n1385' href='#n1385'>1385</a>
<a id='n1386' href='#n1386'>1386</a>
<a id='n1387' href='#n1387'>1387</a>
<a id='n1388' href='#n1388'>1388</a>
<a id='n1389' href='#n1389'>1389</a>
<a id='n1390' href='#n1390'>1390</a>
<a id='n1391' href='#n1391'>1391</a>
<a id='n1392' href='#n1392'>1392</a>
<a id='n1393' href='#n1393'>1393</a>
<a id='n1394' href='#n1394'>1394</a>
<a id='n1395' href='#n1395'>1395</a>
<a id='n1396' href='#n1396'>1396</a>
<a id='n1397' href='#n1397'>1397</a>
<a id='n1398' href='#n1398'>1398</a>
<a id='n1399' href='#n1399'>1399</a>
<a id='n1400' href='#n1400'>1400</a>
<a id='n1401' href='#n1401'>1401</a>
<a id='n1402' href='#n1402'>1402</a>
<a id='n1403' href='#n1403'>1403</a>
<a id='n1404' href='#n1404'>1404</a>
<a id='n1405' href='#n1405'>1405</a>
<a id='n1406' href='#n1406'>1406</a>
<a id='n1407' href='#n1407'>1407</a>
<a id='n1408' href='#n1408'>1408</a>
<a id='n1409' href='#n1409'>1409</a>
<a id='n1410' href='#n1410'>1410</a>
<a id='n1411' href='#n1411'>1411</a>
<a id='n1412' href='#n1412'>1412</a>
<a id='n1413' href='#n1413'>1413</a>
<a id='n1414' href='#n1414'>1414</a>
<a id='n1415' href='#n1415'>1415</a>
<a id='n1416' href='#n1416'>1416</a>
<a id='n1417' href='#n1417'>1417</a>
<a id='n1418' href='#n1418'>1418</a>
<a id='n1419' href='#n1419'>1419</a>
<a id='n1420' href='#n1420'>1420</a>
<a id='n1421' href='#n1421'>1421</a>
<a id='n1422' href='#n1422'>1422</a>
<a id='n1423' href='#n1423'>1423</a>
<a id='n1424' href='#n1424'>1424</a>
<a id='n1425' href='#n1425'>1425</a>
<a id='n1426' href='#n1426'>1426</a>
<a id='n1427' href='#n1427'>1427</a>
<a id='n1428' href='#n1428'>1428</a>
<a id='n1429' href='#n1429'>1429</a>
<a id='n1430' href='#n1430'>1430</a>
<a id='n1431' href='#n1431'>1431</a>
<a id='n1432' href='#n1432'>1432</a>
<a id='n1433' href='#n1433'>1433</a>
<a id='n1434' href='#n1434'>1434</a>
<a id='n1435' href='#n1435'>1435</a>
<a id='n1436' href='#n1436'>1436</a>
<a id='n1437' href='#n1437'>1437</a>
<a id='n1438' href='#n1438'>1438</a>
<a id='n1439' href='#n1439'>1439</a>
<a id='n1440' href='#n1440'>1440</a>
<a id='n1441' href='#n1441'>1441</a>
<a id='n1442' href='#n1442'>1442</a>
<a id='n1443' href='#n1443'>1443</a>
<a id='n1444' href='#n1444'>1444</a>
<a id='n1445' href='#n1445'>1445</a>
<a id='n1446' href='#n1446'>1446</a>
<a id='n1447' href='#n1447'>1447</a>
<a id='n1448' href='#n1448'>1448</a>
<a id='n1449' href='#n1449'>1449</a>
<a id='n1450' href='#n1450'>1450</a>
<a id='n1451' href='#n1451'>1451</a>
<a id='n1452' href='#n1452'>1452</a>
<a id='n1453' href='#n1453'>1453</a>
<a id='n1454' href='#n1454'>1454</a>
<a id='n1455' href='#n1455'>1455</a>
<a id='n1456' href='#n1456'>1456</a>
<a id='n1457' href='#n1457'>1457</a>
<a id='n1458' href='#n1458'>1458</a>
<a id='n1459' href='#n1459'>1459</a>
<a id='n1460' href='#n1460'>1460</a>
<a id='n1461' href='#n1461'>1461</a>
<a id='n1462' href='#n1462'>1462</a>
<a id='n1463' href='#n1463'>1463</a>
<a id='n1464' href='#n1464'>1464</a>
<a id='n1465' href='#n1465'>1465</a>
<a id='n1466' href='#n1466'>1466</a>
<a id='n1467' href='#n1467'>1467</a>
<a id='n1468' href='#n1468'>1468</a>
<a id='n1469' href='#n1469'>1469</a>
<a id='n1470' href='#n1470'>1470</a>
<a id='n1471' href='#n1471'>1471</a>
<a id='n1472' href='#n1472'>1472</a>
<a id='n1473' href='#n1473'>1473</a>
<a id='n1474' href='#n1474'>1474</a>
<a id='n1475' href='#n1475'>1475</a>
<a id='n1476' href='#n1476'>1476</a>
<a id='n1477' href='#n1477'>1477</a>
<a id='n1478' href='#n1478'>1478</a>
<a id='n1479' href='#n1479'>1479</a>
<a id='n1480' href='#n1480'>1480</a>
<a id='n1481' href='#n1481'>1481</a>
<a id='n1482' href='#n1482'>1482</a>
<a id='n1483' href='#n1483'>1483</a>
<a id='n1484' href='#n1484'>1484</a>
<a id='n1485' href='#n1485'>1485</a>
<a id='n1486' href='#n1486'>1486</a>
<a id='n1487' href='#n1487'>1487</a>
<a id='n1488' href='#n1488'>1488</a>
<a id='n1489' href='#n1489'>1489</a>
<a id='n1490' href='#n1490'>1490</a>
<a id='n1491' href='#n1491'>1491</a>
<a id='n1492' href='#n1492'>1492</a>
<a id='n1493' href='#n1493'>1493</a>
<a id='n1494' href='#n1494'>1494</a>
<a id='n1495' href='#n1495'>1495</a>
<a id='n1496' href='#n1496'>1496</a>
<a id='n1497' href='#n1497'>1497</a>
<a id='n1498' href='#n1498'>1498</a>
<a id='n1499' href='#n1499'>1499</a>
<a id='n1500' href='#n1500'>1500</a>
<a id='n1501' href='#n1501'>1501</a>
<a id='n1502' href='#n1502'>1502</a>
<a id='n1503' href='#n1503'>1503</a>
<a id='n1504' href='#n1504'>1504</a>
<a id='n1505' href='#n1505'>1505</a>
<a id='n1506' href='#n1506'>1506</a>
<a id='n1507' href='#n1507'>1507</a>
<a id='n1508' href='#n1508'>1508</a>
<a id='n1509' href='#n1509'>1509</a>
<a id='n1510' href='#n1510'>1510</a>
<a id='n1511' href='#n1511'>1511</a>
<a id='n1512' href='#n1512'>1512</a>
<a id='n1513' href='#n1513'>1513</a>
<a id='n1514' href='#n1514'>1514</a>
<a id='n1515' href='#n1515'>1515</a>
<a id='n1516' href='#n1516'>1516</a>
<a id='n1517' href='#n1517'>1517</a>
<a id='n1518' href='#n1518'>1518</a>
<a id='n1519' href='#n1519'>1519</a>
<a id='n1520' href='#n1520'>1520</a>
<a id='n1521' href='#n1521'>1521</a>
<a id='n1522' href='#n1522'>1522</a>
<a id='n1523' href='#n1523'>1523</a>
<a id='n1524' href='#n1524'>1524</a>
<a id='n1525' href='#n1525'>1525</a>
<a id='n1526' href='#n1526'>1526</a>
<a id='n1527' href='#n1527'>1527</a>
<a id='n1528' href='#n1528'>1528</a>
<a id='n1529' href='#n1529'>1529</a>
<a id='n1530' href='#n1530'>1530</a>
<a id='n1531' href='#n1531'>1531</a>
<a id='n1532' href='#n1532'>1532</a>
<a id='n1533' href='#n1533'>1533</a>
<a id='n1534' href='#n1534'>1534</a>
<a id='n1535' href='#n1535'>1535</a>
<a id='n1536' href='#n1536'>1536</a>
<a id='n1537' href='#n1537'>1537</a>
<a id='n1538' href='#n1538'>1538</a>
<a id='n1539' href='#n1539'>1539</a>
<a id='n1540' href='#n1540'>1540</a>
<a id='n1541' href='#n1541'>1541</a>
<a id='n1542' href='#n1542'>1542</a>
<a id='n1543' href='#n1543'>1543</a>
<a id='n1544' href='#n1544'>1544</a>
<a id='n1545' href='#n1545'>1545</a>
<a id='n1546' href='#n1546'>1546</a>
<a id='n1547' href='#n1547'>1547</a>
<a id='n1548' href='#n1548'>1548</a>
<a id='n1549' href='#n1549'>1549</a>
<a id='n1550' href='#n1550'>1550</a>
<a id='n1551' href='#n1551'>1551</a>
<a id='n1552' href='#n1552'>1552</a>
<a id='n1553' href='#n1553'>1553</a>
<a id='n1554' href='#n1554'>1554</a>
<a id='n1555' href='#n1555'>1555</a>
<a id='n1556' href='#n1556'>1556</a>
<a id='n1557' href='#n1557'>1557</a>
<a id='n1558' href='#n1558'>1558</a>
<a id='n1559' href='#n1559'>1559</a>
<a id='n1560' href='#n1560'>1560</a>
<a id='n1561' href='#n1561'>1561</a>
<a id='n1562' href='#n1562'>1562</a>
<a id='n1563' href='#n1563'>1563</a>
<a id='n1564' href='#n1564'>1564</a>
<a id='n1565' href='#n1565'>1565</a>
<a id='n1566' href='#n1566'>1566</a>
<a id='n1567' href='#n1567'>1567</a>
<a id='n1568' href='#n1568'>1568</a>
<a id='n1569' href='#n1569'>1569</a>
<a id='n1570' href='#n1570'>1570</a>
<a id='n1571' href='#n1571'>1571</a>
<a id='n1572' href='#n1572'>1572</a>
<a id='n1573' href='#n1573'>1573</a>
<a id='n1574' href='#n1574'>1574</a>
<a id='n1575' href='#n1575'>1575</a>
<a id='n1576' href='#n1576'>1576</a>
<a id='n1577' href='#n1577'>1577</a>
<a id='n1578' href='#n1578'>1578</a>
<a id='n1579' href='#n1579'>1579</a>
<a id='n1580' href='#n1580'>1580</a>
<a id='n1581' href='#n1581'>1581</a>
<a id='n1582' href='#n1582'>1582</a>
<a id='n1583' href='#n1583'>1583</a>
<a id='n1584' href='#n1584'>1584</a>
<a id='n1585' href='#n1585'>1585</a>
<a id='n1586' href='#n1586'>1586</a>
<a id='n1587' href='#n1587'>1587</a>
<a id='n1588' href='#n1588'>1588</a>
<a id='n1589' href='#n1589'>1589</a>
<a id='n1590' href='#n1590'>1590</a>
<a id='n1591' href='#n1591'>1591</a>
<a id='n1592' href='#n1592'>1592</a>
<a id='n1593' href='#n1593'>1593</a>
<a id='n1594' href='#n1594'>1594</a>
<a id='n1595' href='#n1595'>1595</a>
<a id='n1596' href='#n1596'>1596</a>
<a id='n1597' href='#n1597'>1597</a>
<a id='n1598' href='#n1598'>1598</a>
<a id='n1599' href='#n1599'>1599</a>
<a id='n1600' href='#n1600'>1600</a>
<a id='n1601' href='#n1601'>1601</a>
<a id='n1602' href='#n1602'>1602</a>
<a id='n1603' href='#n1603'>1603</a>
<a id='n1604' href='#n1604'>1604</a>
<a id='n1605' href='#n1605'>1605</a>
<a id='n1606' href='#n1606'>1606</a>
<a id='n1607' href='#n1607'>1607</a>
<a id='n1608' href='#n1608'>1608</a>
<a id='n1609' href='#n1609'>1609</a>
<a id='n1610' href='#n1610'>1610</a>
<a id='n1611' href='#n1611'>1611</a>
<a id='n1612' href='#n1612'>1612</a>
<a id='n1613' href='#n1613'>1613</a>
<a id='n1614' href='#n1614'>1614</a>
<a id='n1615' href='#n1615'>1615</a>
<a id='n1616' href='#n1616'>1616</a>
<a id='n1617' href='#n1617'>1617</a>
<a id='n1618' href='#n1618'>1618</a>
<a id='n1619' href='#n1619'>1619</a>
<a id='n1620' href='#n1620'>1620</a>
<a id='n1621' href='#n1621'>1621</a>
<a id='n1622' href='#n1622'>1622</a>
<a id='n1623' href='#n1623'>1623</a>
<a id='n1624' href='#n1624'>1624</a>
<a id='n1625' href='#n1625'>1625</a>
<a id='n1626' href='#n1626'>1626</a>
<a id='n1627' href='#n1627'>1627</a>
<a id='n1628' href='#n1628'>1628</a>
<a id='n1629' href='#n1629'>1629</a>
<a id='n1630' href='#n1630'>1630</a>
<a id='n1631' href='#n1631'>1631</a>
<a id='n1632' href='#n1632'>1632</a>
<a id='n1633' href='#n1633'>1633</a>
<a id='n1634' href='#n1634'>1634</a>
<a id='n1635' href='#n1635'>1635</a>
<a id='n1636' href='#n1636'>1636</a>
<a id='n1637' href='#n1637'>1637</a>
<a id='n1638' href='#n1638'>1638</a>
<a id='n1639' href='#n1639'>1639</a>
<a id='n1640' href='#n1640'>1640</a>
<a id='n1641' href='#n1641'>1641</a>
<a id='n1642' href='#n1642'>1642</a>
<a id='n1643' href='#n1643'>1643</a>
<a id='n1644' href='#n1644'>1644</a>
<a id='n1645' href='#n1645'>1645</a>
<a id='n1646' href='#n1646'>1646</a>
<a id='n1647' href='#n1647'>1647</a>
<a id='n1648' href='#n1648'>1648</a>
<a id='n1649' href='#n1649'>1649</a>
<a id='n1650' href='#n1650'>1650</a>
<a id='n1651' href='#n1651'>1651</a>
<a id='n1652' href='#n1652'>1652</a>
<a id='n1653' href='#n1653'>1653</a>
<a id='n1654' href='#n1654'>1654</a>
<a id='n1655' href='#n1655'>1655</a>
<a id='n1656' href='#n1656'>1656</a>
<a id='n1657' href='#n1657'>1657</a>
<a id='n1658' href='#n1658'>1658</a>
<a id='n1659' href='#n1659'>1659</a>
<a id='n1660' href='#n1660'>1660</a>
<a id='n1661' href='#n1661'>1661</a>
<a id='n1662' href='#n1662'>1662</a>
<a id='n1663' href='#n1663'>1663</a>
<a id='n1664' href='#n1664'>1664</a>
<a id='n1665' href='#n1665'>1665</a>
<a id='n1666' href='#n1666'>1666</a>
<a id='n1667' href='#n1667'>1667</a>
<a id='n1668' href='#n1668'>1668</a>
<a id='n1669' href='#n1669'>1669</a>
<a id='n1670' href='#n1670'>1670</a>
<a id='n1671' href='#n1671'>1671</a>
<a id='n1672' href='#n1672'>1672</a>
<a id='n1673' href='#n1673'>1673</a>
<a id='n1674' href='#n1674'>1674</a>
<a id='n1675' href='#n1675'>1675</a>
<a id='n1676' href='#n1676'>1676</a>
<a id='n1677' href='#n1677'>1677</a>
<a id='n1678' href='#n1678'>1678</a>
<a id='n1679' href='#n1679'>1679</a>
<a id='n1680' href='#n1680'>1680</a>
<a id='n1681' href='#n1681'>1681</a>
<a id='n1682' href='#n1682'>1682</a>
<a id='n1683' href='#n1683'>1683</a>
<a id='n1684' href='#n1684'>1684</a>
<a id='n1685' href='#n1685'>1685</a>
<a id='n1686' href='#n1686'>1686</a>
<a id='n1687' href='#n1687'>1687</a>
<a id='n1688' href='#n1688'>1688</a>
<a id='n1689' href='#n1689'>1689</a>
<a id='n1690' href='#n1690'>1690</a>
<a id='n1691' href='#n1691'>1691</a>
<a id='n1692' href='#n1692'>1692</a>
<a id='n1693' href='#n1693'>1693</a>
<a id='n1694' href='#n1694'>1694</a>
<a id='n1695' href='#n1695'>1695</a>
<a id='n1696' href='#n1696'>1696</a>
<a id='n1697' href='#n1697'>1697</a>
<a id='n1698' href='#n1698'>1698</a>
<a id='n1699' href='#n1699'>1699</a>
<a id='n1700' href='#n1700'>1700</a>
<a id='n1701' href='#n1701'>1701</a>
<a id='n1702' href='#n1702'>1702</a>
<a id='n1703' href='#n1703'>1703</a>
<a id='n1704' href='#n1704'>1704</a>
<a id='n1705' href='#n1705'>1705</a>
<a id='n1706' href='#n1706'>1706</a>
<a id='n1707' href='#n1707'>1707</a>
<a id='n1708' href='#n1708'>1708</a>
<a id='n1709' href='#n1709'>1709</a>
<a id='n1710' href='#n1710'>1710</a>
<a id='n1711' href='#n1711'>1711</a>
<a id='n1712' href='#n1712'>1712</a>
<a id='n1713' href='#n1713'>1713</a>
<a id='n1714' href='#n1714'>1714</a>
<a id='n1715' href='#n1715'>1715</a>
<a id='n1716' href='#n1716'>1716</a>
<a id='n1717' href='#n1717'>1717</a>
<a id='n1718' href='#n1718'>1718</a>
<a id='n1719' href='#n1719'>1719</a>
<a id='n1720' href='#n1720'>1720</a>
<a id='n1721' href='#n1721'>1721</a>
<a id='n1722' href='#n1722'>1722</a>
<a id='n1723' href='#n1723'>1723</a>
<a id='n1724' href='#n1724'>1724</a>
<a id='n1725' href='#n1725'>1725</a>
<a id='n1726' href='#n1726'>1726</a>
<a id='n1727' href='#n1727'>1727</a>
<a id='n1728' href='#n1728'>1728</a>
<a id='n1729' href='#n1729'>1729</a>
<a id='n1730' href='#n1730'>1730</a>
<a id='n1731' href='#n1731'>1731</a>
<a id='n1732' href='#n1732'>1732</a>
<a id='n1733' href='#n1733'>1733</a>
<a id='n1734' href='#n1734'>1734</a>
<a id='n1735' href='#n1735'>1735</a>
<a id='n1736' href='#n1736'>1736</a>
<a id='n1737' href='#n1737'>1737</a>
<a id='n1738' href='#n1738'>1738</a>
<a id='n1739' href='#n1739'>1739</a>
<a id='n1740' href='#n1740'>1740</a>
<a id='n1741' href='#n1741'>1741</a>
<a id='n1742' href='#n1742'>1742</a>
<a id='n1743' href='#n1743'>1743</a>
<a id='n1744' href='#n1744'>1744</a>
<a id='n1745' href='#n1745'>1745</a>
<a id='n1746' href='#n1746'>1746</a>
<a id='n1747' href='#n1747'>1747</a>
<a id='n1748' href='#n1748'>1748</a>
<a id='n1749' href='#n1749'>1749</a>
<a id='n1750' href='#n1750'>1750</a>
<a id='n1751' href='#n1751'>1751</a>
<a id='n1752' href='#n1752'>1752</a>
<a id='n1753' href='#n1753'>1753</a>
<a id='n1754' href='#n1754'>1754</a>
<a id='n1755' href='#n1755'>1755</a>
<a id='n1756' href='#n1756'>1756</a>
<a id='n1757' href='#n1757'>1757</a>
<a id='n1758' href='#n1758'>1758</a>
<a id='n1759' href='#n1759'>1759</a>
<a id='n1760' href='#n1760'>1760</a>
<a id='n1761' href='#n1761'>1761</a>
<a id='n1762' href='#n1762'>1762</a>
<a id='n1763' href='#n1763'>1763</a>
<a id='n1764' href='#n1764'>1764</a>
<a id='n1765' href='#n1765'>1765</a>
<a id='n1766' href='#n1766'>1766</a>
<a id='n1767' href='#n1767'>1767</a>
<a id='n1768' href='#n1768'>1768</a>
<a id='n1769' href='#n1769'>1769</a>
<a id='n1770' href='#n1770'>1770</a>
<a id='n1771' href='#n1771'>1771</a>
<a id='n1772' href='#n1772'>1772</a>
<a id='n1773' href='#n1773'>1773</a>
<a id='n1774' href='#n1774'>1774</a>
<a id='n1775' href='#n1775'>1775</a>
<a id='n1776' href='#n1776'>1776</a>
<a id='n1777' href='#n1777'>1777</a>
<a id='n1778' href='#n1778'>1778</a>
<a id='n1779' href='#n1779'>1779</a>
<a id='n1780' href='#n1780'>1780</a>
<a id='n1781' href='#n1781'>1781</a>
<a id='n1782' href='#n1782'>1782</a>
<a id='n1783' href='#n1783'>1783</a>
<a id='n1784' href='#n1784'>1784</a>
<a id='n1785' href='#n1785'>1785</a>
<a id='n1786' href='#n1786'>1786</a>
<a id='n1787' href='#n1787'>1787</a>
<a id='n1788' href='#n1788'>1788</a>
<a id='n1789' href='#n1789'>1789</a>
<a id='n1790' href='#n1790'>1790</a>
<a id='n1791' href='#n1791'>1791</a>
<a id='n1792' href='#n1792'>1792</a>
<a id='n1793' href='#n1793'>1793</a>
<a id='n1794' href='#n1794'>1794</a>
<a id='n1795' href='#n1795'>1795</a>
<a id='n1796' href='#n1796'>1796</a>
<a id='n1797' href='#n1797'>1797</a>
<a id='n1798' href='#n1798'>1798</a>
<a id='n1799' href='#n1799'>1799</a>
<a id='n1800' href='#n1800'>1800</a>
<a id='n1801' href='#n1801'>1801</a>
<a id='n1802' href='#n1802'>1802</a>
<a id='n1803' href='#n1803'>1803</a>
<a id='n1804' href='#n1804'>1804</a>
<a id='n1805' href='#n1805'>1805</a>
<a id='n1806' href='#n1806'>1806</a>
<a id='n1807' href='#n1807'>1807</a>
<a id='n1808' href='#n1808'>1808</a>
<a id='n1809' href='#n1809'>1809</a>
<a id='n1810' href='#n1810'>1810</a>
<a id='n1811' href='#n1811'>1811</a>
<a id='n1812' href='#n1812'>1812</a>
<a id='n1813' href='#n1813'>1813</a>
<a id='n1814' href='#n1814'>1814</a>
<a id='n1815' href='#n1815'>1815</a>
<a id='n1816' href='#n1816'>1816</a>
<a id='n1817' href='#n1817'>1817</a>
<a id='n1818' href='#n1818'>1818</a>
<a id='n1819' href='#n1819'>1819</a>
<a id='n1820' href='#n1820'>1820</a>
<a id='n1821' href='#n1821'>1821</a>
<a id='n1822' href='#n1822'>1822</a>
<a id='n1823' href='#n1823'>1823</a>
<a id='n1824' href='#n1824'>1824</a>
<a id='n1825' href='#n1825'>1825</a>
<a id='n1826' href='#n1826'>1826</a>
<a id='n1827' href='#n1827'>1827</a>
<a id='n1828' href='#n1828'>1828</a>
<a id='n1829' href='#n1829'>1829</a>
<a id='n1830' href='#n1830'>1830</a>
<a id='n1831' href='#n1831'>1831</a>
<a id='n1832' href='#n1832'>1832</a>
<a id='n1833' href='#n1833'>1833</a>
<a id='n1834' href='#n1834'>1834</a>
<a id='n1835' href='#n1835'>1835</a>
<a id='n1836' href='#n1836'>1836</a>
<a id='n1837' href='#n1837'>1837</a>
<a id='n1838' href='#n1838'>1838</a>
<a id='n1839' href='#n1839'>1839</a>
<a id='n1840' href='#n1840'>1840</a>
<a id='n1841' href='#n1841'>1841</a>
<a id='n1842' href='#n1842'>1842</a>
<a id='n1843' href='#n1843'>1843</a>
<a id='n1844' href='#n1844'>1844</a>
<a id='n1845' href='#n1845'>1845</a>
<a id='n1846' href='#n1846'>1846</a>
<a id='n1847' href='#n1847'>1847</a>
<a id='n1848' href='#n1848'>1848</a>
<a id='n1849' href='#n1849'>1849</a>
<a id='n1850' href='#n1850'>1850</a>
<a id='n1851' href='#n1851'>1851</a>
<a id='n1852' href='#n1852'>1852</a>
<a id='n1853' href='#n1853'>1853</a>
<a id='n1854' href='#n1854'>1854</a>
<a id='n1855' href='#n1855'>1855</a>
<a id='n1856' href='#n1856'>1856</a>
<a id='n1857' href='#n1857'>1857</a>
<a id='n1858' href='#n1858'>1858</a>
<a id='n1859' href='#n1859'>1859</a>
<a id='n1860' href='#n1860'>1860</a>
<a id='n1861' href='#n1861'>1861</a>
<a id='n1862' href='#n1862'>1862</a>
<a id='n1863' href='#n1863'>1863</a>
<a id='n1864' href='#n1864'>1864</a>
<a id='n1865' href='#n1865'>1865</a>
<a id='n1866' href='#n1866'>1866</a>
<a id='n1867' href='#n1867'>1867</a>
<a id='n1868' href='#n1868'>1868</a>
<a id='n1869' href='#n1869'>1869</a>
<a id='n1870' href='#n1870'>1870</a>
<a id='n1871' href='#n1871'>1871</a>
<a id='n1872' href='#n1872'>1872</a>
<a id='n1873' href='#n1873'>1873</a>
<a id='n1874' href='#n1874'>1874</a>
<a id='n1875' href='#n1875'>1875</a>
<a id='n1876' href='#n1876'>1876</a>
<a id='n1877' href='#n1877'>1877</a>
<a id='n1878' href='#n1878'>1878</a>
<a id='n1879' href='#n1879'>1879</a>
<a id='n1880' href='#n1880'>1880</a>
<a id='n1881' href='#n1881'>1881</a>
<a id='n1882' href='#n1882'>1882</a>
<a id='n1883' href='#n1883'>1883</a>
<a id='n1884' href='#n1884'>1884</a>
<a id='n1885' href='#n1885'>1885</a>
<a id='n1886' href='#n1886'>1886</a>
<a id='n1887' href='#n1887'>1887</a>
<a id='n1888' href='#n1888'>1888</a>
<a id='n1889' href='#n1889'>1889</a>
<a id='n1890' href='#n1890'>1890</a>
<a id='n1891' href='#n1891'>1891</a>
<a id='n1892' href='#n1892'>1892</a>
<a id='n1893' href='#n1893'>1893</a>
<a id='n1894' href='#n1894'>1894</a>
<a id='n1895' href='#n1895'>1895</a>
<a id='n1896' href='#n1896'>1896</a>
<a id='n1897' href='#n1897'>1897</a>
<a id='n1898' href='#n1898'>1898</a>
<a id='n1899' href='#n1899'>1899</a>
<a id='n1900' href='#n1900'>1900</a>
<a id='n1901' href='#n1901'>1901</a>
<a id='n1902' href='#n1902'>1902</a>
<a id='n1903' href='#n1903'>1903</a>
<a id='n1904' href='#n1904'>1904</a>
<a id='n1905' href='#n1905'>1905</a>
<a id='n1906' href='#n1906'>1906</a>
<a id='n1907' href='#n1907'>1907</a>
<a id='n1908' href='#n1908'>1908</a>
<a id='n1909' href='#n1909'>1909</a>
<a id='n1910' href='#n1910'>1910</a>
<a id='n1911' href='#n1911'>1911</a>
<a id='n1912' href='#n1912'>1912</a>
<a id='n1913' href='#n1913'>1913</a>
<a id='n1914' href='#n1914'>1914</a>
<a id='n1915' href='#n1915'>1915</a>
<a id='n1916' href='#n1916'>1916</a>
<a id='n1917' href='#n1917'>1917</a>
<a id='n1918' href='#n1918'>1918</a>
<a id='n1919' href='#n1919'>1919</a>
<a id='n1920' href='#n1920'>1920</a>
<a id='n1921' href='#n1921'>1921</a>
<a id='n1922' href='#n1922'>1922</a>
<a id='n1923' href='#n1923'>1923</a>
<a id='n1924' href='#n1924'>1924</a>
<a id='n1925' href='#n1925'>1925</a>
<a id='n1926' href='#n1926'>1926</a>
<a id='n1927' href='#n1927'>1927</a>
<a id='n1928' href='#n1928'>1928</a>
<a id='n1929' href='#n1929'>1929</a>
<a id='n1930' href='#n1930'>1930</a>
<a id='n1931' href='#n1931'>1931</a>
<a id='n1932' href='#n1932'>1932</a>
<a id='n1933' href='#n1933'>1933</a>
<a id='n1934' href='#n1934'>1934</a>
<a id='n1935' href='#n1935'>1935</a>
<a id='n1936' href='#n1936'>1936</a>
<a id='n1937' href='#n1937'>1937</a>
<a id='n1938' href='#n1938'>1938</a>
<a id='n1939' href='#n1939'>1939</a>
<a id='n1940' href='#n1940'>1940</a>
<a id='n1941' href='#n1941'>1941</a>
<a id='n1942' href='#n1942'>1942</a>
<a id='n1943' href='#n1943'>1943</a>
<a id='n1944' href='#n1944'>1944</a>
<a id='n1945' href='#n1945'>1945</a>
<a id='n1946' href='#n1946'>1946</a>
<a id='n1947' href='#n1947'>1947</a>
<a id='n1948' href='#n1948'>1948</a>
<a id='n1949' href='#n1949'>1949</a>
<a id='n1950' href='#n1950'>1950</a>
<a id='n1951' href='#n1951'>1951</a>
<a id='n1952' href='#n1952'>1952</a>
<a id='n1953' href='#n1953'>1953</a>
<a id='n1954' href='#n1954'>1954</a>
<a id='n1955' href='#n1955'>1955</a>
<a id='n1956' href='#n1956'>1956</a>
<a id='n1957' href='#n1957'>1957</a>
<a id='n1958' href='#n1958'>1958</a>
<a id='n1959' href='#n1959'>1959</a>
<a id='n1960' href='#n1960'>1960</a>
<a id='n1961' href='#n1961'>1961</a>
<a id='n1962' href='#n1962'>1962</a>
<a id='n1963' href='#n1963'>1963</a>
<a id='n1964' href='#n1964'>1964</a>
<a id='n1965' href='#n1965'>1965</a>
<a id='n1966' href='#n1966'>1966</a>
<a id='n1967' href='#n1967'>1967</a>
<a id='n1968' href='#n1968'>1968</a>
<a id='n1969' href='#n1969'>1969</a>
<a id='n1970' href='#n1970'>1970</a>
<a id='n1971' href='#n1971'>1971</a>
<a id='n1972' href='#n1972'>1972</a>
<a id='n1973' href='#n1973'>1973</a>
<a id='n1974' href='#n1974'>1974</a>
<a id='n1975' href='#n1975'>1975</a>
<a id='n1976' href='#n1976'>1976</a>
<a id='n1977' href='#n1977'>1977</a>
<a id='n1978' href='#n1978'>1978</a>
<a id='n1979' href='#n1979'>1979</a>
<a id='n1980' href='#n1980'>1980</a>
<a id='n1981' href='#n1981'>1981</a>
<a id='n1982' href='#n1982'>1982</a>
<a id='n1983' href='#n1983'>1983</a>
<a id='n1984' href='#n1984'>1984</a>
<a id='n1985' href='#n1985'>1985</a>
<a id='n1986' href='#n1986'>1986</a>
<a id='n1987' href='#n1987'>1987</a>
<a id='n1988' href='#n1988'>1988</a>
<a id='n1989' href='#n1989'>1989</a>
<a id='n1990' href='#n1990'>1990</a>
<a id='n1991' href='#n1991'>1991</a>
<a id='n1992' href='#n1992'>1992</a>
<a id='n1993' href='#n1993'>1993</a>
<a id='n1994' href='#n1994'>1994</a>
<a id='n1995' href='#n1995'>1995</a>
<a id='n1996' href='#n1996'>1996</a>
<a id='n1997' href='#n1997'>1997</a>
<a id='n1998' href='#n1998'>1998</a>
<a id='n1999' href='#n1999'>1999</a>
<a id='n2000' href='#n2000'>2000</a>
<a id='n2001' href='#n2001'>2001</a>
<a id='n2002' href='#n2002'>2002</a>
<a id='n2003' href='#n2003'>2003</a>
<a id='n2004' href='#n2004'>2004</a>
<a id='n2005' href='#n2005'>2005</a>
<a id='n2006' href='#n2006'>2006</a>
<a id='n2007' href='#n2007'>2007</a>
<a id='n2008' href='#n2008'>2008</a>
<a id='n2009' href='#n2009'>2009</a>
<a id='n2010' href='#n2010'>2010</a>
<a id='n2011' href='#n2011'>2011</a>
<a id='n2012' href='#n2012'>2012</a>
<a id='n2013' href='#n2013'>2013</a>
<a id='n2014' href='#n2014'>2014</a>
<a id='n2015' href='#n2015'>2015</a>
<a id='n2016' href='#n2016'>2016</a>
<a id='n2017' href='#n2017'>2017</a>
<a id='n2018' href='#n2018'>2018</a>
<a id='n2019' href='#n2019'>2019</a>
<a id='n2020' href='#n2020'>2020</a>
<a id='n2021' href='#n2021'>2021</a>
<a id='n2022' href='#n2022'>2022</a>
<a id='n2023' href='#n2023'>2023</a>
<a id='n2024' href='#n2024'>2024</a>
<a id='n2025' href='#n2025'>2025</a>
<a id='n2026' href='#n2026'>2026</a>
<a id='n2027' href='#n2027'>2027</a>
<a id='n2028' href='#n2028'>2028</a>
<a id='n2029' href='#n2029'>2029</a>
<a id='n2030' href='#n2030'>2030</a>
<a id='n2031' href='#n2031'>2031</a>
<a id='n2032' href='#n2032'>2032</a>
<a id='n2033' href='#n2033'>2033</a>
<a id='n2034' href='#n2034'>2034</a>
<a id='n2035' href='#n2035'>2035</a>
<a id='n2036' href='#n2036'>2036</a>
<a id='n2037' href='#n2037'>2037</a>
<a id='n2038' href='#n2038'>2038</a>
<a id='n2039' href='#n2039'>2039</a>
<a id='n2040' href='#n2040'>2040</a>
<a id='n2041' href='#n2041'>2041</a>
<a id='n2042' href='#n2042'>2042</a>
<a id='n2043' href='#n2043'>2043</a>
<a id='n2044' href='#n2044'>2044</a>
<a id='n2045' href='#n2045'>2045</a>
<a id='n2046' href='#n2046'>2046</a>
<a id='n2047' href='#n2047'>2047</a>
<a id='n2048' href='#n2048'>2048</a>
<a id='n2049' href='#n2049'>2049</a>
<a id='n2050' href='#n2050'>2050</a>
<a id='n2051' href='#n2051'>2051</a>
<a id='n2052' href='#n2052'>2052</a>
<a id='n2053' href='#n2053'>2053</a>
<a id='n2054' href='#n2054'>2054</a>
<a id='n2055' href='#n2055'>2055</a>
<a id='n2056' href='#n2056'>2056</a>
<a id='n2057' href='#n2057'>2057</a>
<a id='n2058' href='#n2058'>2058</a>
<a id='n2059' href='#n2059'>2059</a>
<a id='n2060' href='#n2060'>2060</a>
<a id='n2061' href='#n2061'>2061</a>
<a id='n2062' href='#n2062'>2062</a>
<a id='n2063' href='#n2063'>2063</a>
<a id='n2064' href='#n2064'>2064</a>
<a id='n2065' href='#n2065'>2065</a>
<a id='n2066' href='#n2066'>2066</a>
<a id='n2067' href='#n2067'>2067</a>
<a id='n2068' href='#n2068'>2068</a>
<a id='n2069' href='#n2069'>2069</a>
<a id='n2070' href='#n2070'>2070</a>
<a id='n2071' href='#n2071'>2071</a>
<a id='n2072' href='#n2072'>2072</a>
<a id='n2073' href='#n2073'>2073</a>
<a id='n2074' href='#n2074'>2074</a>
<a id='n2075' href='#n2075'>2075</a>
<a id='n2076' href='#n2076'>2076</a>
<a id='n2077' href='#n2077'>2077</a>
<a id='n2078' href='#n2078'>2078</a>
<a id='n2079' href='#n2079'>2079</a>
<a id='n2080' href='#n2080'>2080</a>
<a id='n2081' href='#n2081'>2081</a>
<a id='n2082' href='#n2082'>2082</a>
<a id='n2083' href='#n2083'>2083</a>
<a id='n2084' href='#n2084'>2084</a>
<a id='n2085' href='#n2085'>2085</a>
<a id='n2086' href='#n2086'>2086</a>
<a id='n2087' href='#n2087'>2087</a>
<a id='n2088' href='#n2088'>2088</a>
<a id='n2089' href='#n2089'>2089</a>
<a id='n2090' href='#n2090'>2090</a>
<a id='n2091' href='#n2091'>2091</a>
<a id='n2092' href='#n2092'>2092</a>
<a id='n2093' href='#n2093'>2093</a>
<a id='n2094' href='#n2094'>2094</a>
<a id='n2095' href='#n2095'>2095</a>
<a id='n2096' href='#n2096'>2096</a>
<a id='n2097' href='#n2097'>2097</a>
<a id='n2098' href='#n2098'>2098</a>
<a id='n2099' href='#n2099'>2099</a>
<a id='n2100' href='#n2100'>2100</a>
<a id='n2101' href='#n2101'>2101</a>
<a id='n2102' href='#n2102'>2102</a>
<a id='n2103' href='#n2103'>2103</a>
<a id='n2104' href='#n2104'>2104</a>
<a id='n2105' href='#n2105'>2105</a>
<a id='n2106' href='#n2106'>2106</a>
<a id='n2107' href='#n2107'>2107</a>
<a id='n2108' href='#n2108'>2108</a>
<a id='n2109' href='#n2109'>2109</a>
<a id='n2110' href='#n2110'>2110</a>
<a id='n2111' href='#n2111'>2111</a>
<a id='n2112' href='#n2112'>2112</a>
<a id='n2113' href='#n2113'>2113</a>
<a id='n2114' href='#n2114'>2114</a>
<a id='n2115' href='#n2115'>2115</a>
<a id='n2116' href='#n2116'>2116</a>
<a id='n2117' href='#n2117'>2117</a>
<a id='n2118' href='#n2118'>2118</a>
<a id='n2119' href='#n2119'>2119</a>
<a id='n2120' href='#n2120'>2120</a>
<a id='n2121' href='#n2121'>2121</a>
<a id='n2122' href='#n2122'>2122</a>
<a id='n2123' href='#n2123'>2123</a>
<a id='n2124' href='#n2124'>2124</a>
<a id='n2125' href='#n2125'>2125</a>
<a id='n2126' href='#n2126'>2126</a>
<a id='n2127' href='#n2127'>2127</a>
<a id='n2128' href='#n2128'>2128</a>
<a id='n2129' href='#n2129'>2129</a>
<a id='n2130' href='#n2130'>2130</a>
<a id='n2131' href='#n2131'>2131</a>
<a id='n2132' href='#n2132'>2132</a>
<a id='n2133' href='#n2133'>2133</a>
<a id='n2134' href='#n2134'>2134</a>
<a id='n2135' href='#n2135'>2135</a>
<a id='n2136' href='#n2136'>2136</a>
<a id='n2137' href='#n2137'>2137</a>
<a id='n2138' href='#n2138'>2138</a>
<a id='n2139' href='#n2139'>2139</a>
<a id='n2140' href='#n2140'>2140</a>
<a id='n2141' href='#n2141'>2141</a>
<a id='n2142' href='#n2142'>2142</a>
<a id='n2143' href='#n2143'>2143</a>
<a id='n2144' href='#n2144'>2144</a>
<a id='n2145' href='#n2145'>2145</a>
<a id='n2146' href='#n2146'>2146</a>
<a id='n2147' href='#n2147'>2147</a>
<a id='n2148' href='#n2148'>2148</a>
<a id='n2149' href='#n2149'>2149</a>
<a id='n2150' href='#n2150'>2150</a>
<a id='n2151' href='#n2151'>2151</a>
<a id='n2152' href='#n2152'>2152</a>
<a id='n2153' href='#n2153'>2153</a>
<a id='n2154' href='#n2154'>2154</a>
<a id='n2155' href='#n2155'>2155</a>
<a id='n2156' href='#n2156'>2156</a>
<a id='n2157' href='#n2157'>2157</a>
<a id='n2158' href='#n2158'>2158</a>
<a id='n2159' href='#n2159'>2159</a>
<a id='n2160' href='#n2160'>2160</a>
<a id='n2161' href='#n2161'>2161</a>
<a id='n2162' href='#n2162'>2162</a>
<a id='n2163' href='#n2163'>2163</a>
<a id='n2164' href='#n2164'>2164</a>
<a id='n2165' href='#n2165'>2165</a>
<a id='n2166' href='#n2166'>2166</a>
<a id='n2167' href='#n2167'>2167</a>
<a id='n2168' href='#n2168'>2168</a>
<a id='n2169' href='#n2169'>2169</a>
<a id='n2170' href='#n2170'>2170</a>
<a id='n2171' href='#n2171'>2171</a>
<a id='n2172' href='#n2172'>2172</a>
<a id='n2173' href='#n2173'>2173</a>
<a id='n2174' href='#n2174'>2174</a>
<a id='n2175' href='#n2175'>2175</a>
<a id='n2176' href='#n2176'>2176</a>
<a id='n2177' href='#n2177'>2177</a>
<a id='n2178' href='#n2178'>2178</a>
<a id='n2179' href='#n2179'>2179</a>
<a id='n2180' href='#n2180'>2180</a>
<a id='n2181' href='#n2181'>2181</a>
<a id='n2182' href='#n2182'>2182</a>
<a id='n2183' href='#n2183'>2183</a>
<a id='n2184' href='#n2184'>2184</a>
<a id='n2185' href='#n2185'>2185</a>
<a id='n2186' href='#n2186'>2186</a>
<a id='n2187' href='#n2187'>2187</a>
<a id='n2188' href='#n2188'>2188</a>
<a id='n2189' href='#n2189'>2189</a>
<a id='n2190' href='#n2190'>2190</a>
<a id='n2191' href='#n2191'>2191</a>
<a id='n2192' href='#n2192'>2192</a>
<a id='n2193' href='#n2193'>2193</a>
<a id='n2194' href='#n2194'>2194</a>
<a id='n2195' href='#n2195'>2195</a>
<a id='n2196' href='#n2196'>2196</a>
<a id='n2197' href='#n2197'>2197</a>
<a id='n2198' href='#n2198'>2198</a>
<a id='n2199' href='#n2199'>2199</a>
<a id='n2200' href='#n2200'>2200</a>
<a id='n2201' href='#n2201'>2201</a>
<a id='n2202' href='#n2202'>2202</a>
<a id='n2203' href='#n2203'>2203</a>
<a id='n2204' href='#n2204'>2204</a>
<a id='n2205' href='#n2205'>2205</a>
<a id='n2206' href='#n2206'>2206</a>
<a id='n2207' href='#n2207'>2207</a>
<a id='n2208' href='#n2208'>2208</a>
<a id='n2209' href='#n2209'>2209</a>
<a id='n2210' href='#n2210'>2210</a>
<a id='n2211' href='#n2211'>2211</a>
<a id='n2212' href='#n2212'>2212</a>
<a id='n2213' href='#n2213'>2213</a>
<a id='n2214' href='#n2214'>2214</a>
<a id='n2215' href='#n2215'>2215</a>
<a id='n2216' href='#n2216'>2216</a>
<a id='n2217' href='#n2217'>2217</a>
<a id='n2218' href='#n2218'>2218</a>
<a id='n2219' href='#n2219'>2219</a>
<a id='n2220' href='#n2220'>2220</a>
<a id='n2221' href='#n2221'>2221</a>
<a id='n2222' href='#n2222'>2222</a>
<a id='n2223' href='#n2223'>2223</a>
<a id='n2224' href='#n2224'>2224</a>
<a id='n2225' href='#n2225'>2225</a>
<a id='n2226' href='#n2226'>2226</a>
<a id='n2227' href='#n2227'>2227</a>
<a id='n2228' href='#n2228'>2228</a>
<a id='n2229' href='#n2229'>2229</a>
<a id='n2230' href='#n2230'>2230</a>
<a id='n2231' href='#n2231'>2231</a>
<a id='n2232' href='#n2232'>2232</a>
<a id='n2233' href='#n2233'>2233</a>
<a id='n2234' href='#n2234'>2234</a>
<a id='n2235' href='#n2235'>2235</a>
<a id='n2236' href='#n2236'>2236</a>
<a id='n2237' href='#n2237'>2237</a>
<a id='n2238' href='#n2238'>2238</a>
<a id='n2239' href='#n2239'>2239</a>
<a id='n2240' href='#n2240'>2240</a>
<a id='n2241' href='#n2241'>2241</a>
<a id='n2242' href='#n2242'>2242</a>
<a id='n2243' href='#n2243'>2243</a>
<a id='n2244' href='#n2244'>2244</a>
<a id='n2245' href='#n2245'>2245</a>
<a id='n2246' href='#n2246'>2246</a>
<a id='n2247' href='#n2247'>2247</a>
<a id='n2248' href='#n2248'>2248</a>
<a id='n2249' href='#n2249'>2249</a>
<a id='n2250' href='#n2250'>2250</a>
<a id='n2251' href='#n2251'>2251</a>
<a id='n2252' href='#n2252'>2252</a>
<a id='n2253' href='#n2253'>2253</a>
<a id='n2254' href='#n2254'>2254</a>
<a id='n2255' href='#n2255'>2255</a>
<a id='n2256' href='#n2256'>2256</a>
<a id='n2257' href='#n2257'>2257</a>
<a id='n2258' href='#n2258'>2258</a>
<a id='n2259' href='#n2259'>2259</a>
<a id='n2260' href='#n2260'>2260</a>
<a id='n2261' href='#n2261'>2261</a>
<a id='n2262' href='#n2262'>2262</a>
<a id='n2263' href='#n2263'>2263</a>
<a id='n2264' href='#n2264'>2264</a>
<a id='n2265' href='#n2265'>2265</a>
<a id='n2266' href='#n2266'>2266</a>
<a id='n2267' href='#n2267'>2267</a>
<a id='n2268' href='#n2268'>2268</a>
<a id='n2269' href='#n2269'>2269</a>
<a id='n2270' href='#n2270'>2270</a>
<a id='n2271' href='#n2271'>2271</a>
<a id='n2272' href='#n2272'>2272</a>
<a id='n2273' href='#n2273'>2273</a>
<a id='n2274' href='#n2274'>2274</a>
<a id='n2275' href='#n2275'>2275</a>
<a id='n2276' href='#n2276'>2276</a>
<a id='n2277' href='#n2277'>2277</a>
<a id='n2278' href='#n2278'>2278</a>
<a id='n2279' href='#n2279'>2279</a>
<a id='n2280' href='#n2280'>2280</a>
<a id='n2281' href='#n2281'>2281</a>
<a id='n2282' href='#n2282'>2282</a>
<a id='n2283' href='#n2283'>2283</a>
<a id='n2284' href='#n2284'>2284</a>
<a id='n2285' href='#n2285'>2285</a>
<a id='n2286' href='#n2286'>2286</a>
<a id='n2287' href='#n2287'>2287</a>
<a id='n2288' href='#n2288'>2288</a>
<a id='n2289' href='#n2289'>2289</a>
<a id='n2290' href='#n2290'>2290</a>
<a id='n2291' href='#n2291'>2291</a>
<a id='n2292' href='#n2292'>2292</a>
<a id='n2293' href='#n2293'>2293</a>
<a id='n2294' href='#n2294'>2294</a>
<a id='n2295' href='#n2295'>2295</a>
<a id='n2296' href='#n2296'>2296</a>
<a id='n2297' href='#n2297'>2297</a>
<a id='n2298' href='#n2298'>2298</a>
<a id='n2299' href='#n2299'>2299</a>
<a id='n2300' href='#n2300'>2300</a>
<a id='n2301' href='#n2301'>2301</a>
<a id='n2302' href='#n2302'>2302</a>
<a id='n2303' href='#n2303'>2303</a>
<a id='n2304' href='#n2304'>2304</a>
<a id='n2305' href='#n2305'>2305</a>
<a id='n2306' href='#n2306'>2306</a>
<a id='n2307' href='#n2307'>2307</a>
<a id='n2308' href='#n2308'>2308</a>
<a id='n2309' href='#n2309'>2309</a>
<a id='n2310' href='#n2310'>2310</a>
<a id='n2311' href='#n2311'>2311</a>
<a id='n2312' href='#n2312'>2312</a>
<a id='n2313' href='#n2313'>2313</a>
<a id='n2314' href='#n2314'>2314</a>
<a id='n2315' href='#n2315'>2315</a>
<a id='n2316' href='#n2316'>2316</a>
<a id='n2317' href='#n2317'>2317</a>
<a id='n2318' href='#n2318'>2318</a>
<a id='n2319' href='#n2319'>2319</a>
<a id='n2320' href='#n2320'>2320</a>
<a id='n2321' href='#n2321'>2321</a>
<a id='n2322' href='#n2322'>2322</a>
<a id='n2323' href='#n2323'>2323</a>
<a id='n2324' href='#n2324'>2324</a>
<a id='n2325' href='#n2325'>2325</a>
<a id='n2326' href='#n2326'>2326</a>
<a id='n2327' href='#n2327'>2327</a>
<a id='n2328' href='#n2328'>2328</a>
<a id='n2329' href='#n2329'>2329</a>
<a id='n2330' href='#n2330'>2330</a>
<a id='n2331' href='#n2331'>2331</a>
<a id='n2332' href='#n2332'>2332</a>
<a id='n2333' href='#n2333'>2333</a>
<a id='n2334' href='#n2334'>2334</a>
<a id='n2335' href='#n2335'>2335</a>
<a id='n2336' href='#n2336'>2336</a>
<a id='n2337' href='#n2337'>2337</a>
<a id='n2338' href='#n2338'>2338</a>
<a id='n2339' href='#n2339'>2339</a>
<a id='n2340' href='#n2340'>2340</a>
<a id='n2341' href='#n2341'>2341</a>
<a id='n2342' href='#n2342'>2342</a>
<a id='n2343' href='#n2343'>2343</a>
<a id='n2344' href='#n2344'>2344</a>
<a id='n2345' href='#n2345'>2345</a>
<a id='n2346' href='#n2346'>2346</a>
<a id='n2347' href='#n2347'>2347</a>
<a id='n2348' href='#n2348'>2348</a>
<a id='n2349' href='#n2349'>2349</a>
<a id='n2350' href='#n2350'>2350</a>
<a id='n2351' href='#n2351'>2351</a>
<a id='n2352' href='#n2352'>2352</a>
<a id='n2353' href='#n2353'>2353</a>
<a id='n2354' href='#n2354'>2354</a>
<a id='n2355' href='#n2355'>2355</a>
<a id='n2356' href='#n2356'>2356</a>
<a id='n2357' href='#n2357'>2357</a>
<a id='n2358' href='#n2358'>2358</a>
<a id='n2359' href='#n2359'>2359</a>
<a id='n2360' href='#n2360'>2360</a>
<a id='n2361' href='#n2361'>2361</a>
<a id='n2362' href='#n2362'>2362</a>
<a id='n2363' href='#n2363'>2363</a>
<a id='n2364' href='#n2364'>2364</a>
<a id='n2365' href='#n2365'>2365</a>
<a id='n2366' href='#n2366'>2366</a>
<a id='n2367' href='#n2367'>2367</a>
<a id='n2368' href='#n2368'>2368</a>
<a id='n2369' href='#n2369'>2369</a>
<a id='n2370' href='#n2370'>2370</a>
<a id='n2371' href='#n2371'>2371</a>
<a id='n2372' href='#n2372'>2372</a>
<a id='n2373' href='#n2373'>2373</a>
<a id='n2374' href='#n2374'>2374</a>
<a id='n2375' href='#n2375'>2375</a>
<a id='n2376' href='#n2376'>2376</a>
<a id='n2377' href='#n2377'>2377</a>
<a id='n2378' href='#n2378'>2378</a>
<a id='n2379' href='#n2379'>2379</a>
<a id='n2380' href='#n2380'>2380</a>
<a id='n2381' href='#n2381'>2381</a>
<a id='n2382' href='#n2382'>2382</a>
<a id='n2383' href='#n2383'>2383</a>
<a id='n2384' href='#n2384'>2384</a>
<a id='n2385' href='#n2385'>2385</a>
<a id='n2386' href='#n2386'>2386</a>
<a id='n2387' href='#n2387'>2387</a>
<a id='n2388' href='#n2388'>2388</a>
<a id='n2389' href='#n2389'>2389</a>
<a id='n2390' href='#n2390'>2390</a>
<a id='n2391' href='#n2391'>2391</a>
<a id='n2392' href='#n2392'>2392</a>
<a id='n2393' href='#n2393'>2393</a>
<a id='n2394' href='#n2394'>2394</a>
<a id='n2395' href='#n2395'>2395</a>
<a id='n2396' href='#n2396'>2396</a>
<a id='n2397' href='#n2397'>2397</a>
<a id='n2398' href='#n2398'>2398</a>
<a id='n2399' href='#n2399'>2399</a>
<a id='n2400' href='#n2400'>2400</a>
<a id='n2401' href='#n2401'>2401</a>
<a id='n2402' href='#n2402'>2402</a>
<a id='n2403' href='#n2403'>2403</a>
<a id='n2404' href='#n2404'>2404</a>
<a id='n2405' href='#n2405'>2405</a>
<a id='n2406' href='#n2406'>2406</a>
<a id='n2407' href='#n2407'>2407</a>
<a id='n2408' href='#n2408'>2408</a>
<a id='n2409' href='#n2409'>2409</a>
<a id='n2410' href='#n2410'>2410</a>
<a id='n2411' href='#n2411'>2411</a>
<a id='n2412' href='#n2412'>2412</a>
<a id='n2413' href='#n2413'>2413</a>
<a id='n2414' href='#n2414'>2414</a>
<a id='n2415' href='#n2415'>2415</a>
<a id='n2416' href='#n2416'>2416</a>
<a id='n2417' href='#n2417'>2417</a>
<a id='n2418' href='#n2418'>2418</a>
<a id='n2419' href='#n2419'>2419</a>
<a id='n2420' href='#n2420'>2420</a>
<a id='n2421' href='#n2421'>2421</a>
<a id='n2422' href='#n2422'>2422</a>
<a id='n2423' href='#n2423'>2423</a>
<a id='n2424' href='#n2424'>2424</a>
<a id='n2425' href='#n2425'>2425</a>
<a id='n2426' href='#n2426'>2426</a>
<a id='n2427' href='#n2427'>2427</a>
<a id='n2428' href='#n2428'>2428</a>
<a id='n2429' href='#n2429'>2429</a>
<a id='n2430' href='#n2430'>2430</a>
<a id='n2431' href='#n2431'>2431</a>
<a id='n2432' href='#n2432'>2432</a>
<a id='n2433' href='#n2433'>2433</a>
<a id='n2434' href='#n2434'>2434</a>
<a id='n2435' href='#n2435'>2435</a>
<a id='n2436' href='#n2436'>2436</a>
<a id='n2437' href='#n2437'>2437</a>
<a id='n2438' href='#n2438'>2438</a>
<a id='n2439' href='#n2439'>2439</a>
<a id='n2440' href='#n2440'>2440</a>
<a id='n2441' href='#n2441'>2441</a>
<a id='n2442' href='#n2442'>2442</a>
<a id='n2443' href='#n2443'>2443</a>
<a id='n2444' href='#n2444'>2444</a>
<a id='n2445' href='#n2445'>2445</a>
<a id='n2446' href='#n2446'>2446</a>
<a id='n2447' href='#n2447'>2447</a>
<a id='n2448' href='#n2448'>2448</a>
<a id='n2449' href='#n2449'>2449</a>
<a id='n2450' href='#n2450'>2450</a>
<a id='n2451' href='#n2451'>2451</a>
<a id='n2452' href='#n2452'>2452</a>
<a id='n2453' href='#n2453'>2453</a>
<a id='n2454' href='#n2454'>2454</a>
<a id='n2455' href='#n2455'>2455</a>
<a id='n2456' href='#n2456'>2456</a>
<a id='n2457' href='#n2457'>2457</a>
<a id='n2458' href='#n2458'>2458</a>
<a id='n2459' href='#n2459'>2459</a>
<a id='n2460' href='#n2460'>2460</a>
<a id='n2461' href='#n2461'>2461</a>
<a id='n2462' href='#n2462'>2462</a>
<a id='n2463' href='#n2463'>2463</a>
<a id='n2464' href='#n2464'>2464</a>
<a id='n2465' href='#n2465'>2465</a>
<a id='n2466' href='#n2466'>2466</a>
<a id='n2467' href='#n2467'>2467</a>
<a id='n2468' href='#n2468'>2468</a>
<a id='n2469' href='#n2469'>2469</a>
<a id='n2470' href='#n2470'>2470</a>
<a id='n2471' href='#n2471'>2471</a>
<a id='n2472' href='#n2472'>2472</a>
<a id='n2473' href='#n2473'>2473</a>
<a id='n2474' href='#n2474'>2474</a>
<a id='n2475' href='#n2475'>2475</a>
<a id='n2476' href='#n2476'>2476</a>
<a id='n2477' href='#n2477'>2477</a>
<a id='n2478' href='#n2478'>2478</a>
<a id='n2479' href='#n2479'>2479</a>
<a id='n2480' href='#n2480'>2480</a>
<a id='n2481' href='#n2481'>2481</a>
<a id='n2482' href='#n2482'>2482</a>
<a id='n2483' href='#n2483'>2483</a>
<a id='n2484' href='#n2484'>2484</a>
<a id='n2485' href='#n2485'>2485</a>
<a id='n2486' href='#n2486'>2486</a>
<a id='n2487' href='#n2487'>2487</a>
<a id='n2488' href='#n2488'>2488</a>
<a id='n2489' href='#n2489'>2489</a>
<a id='n2490' href='#n2490'>2490</a>
<a id='n2491' href='#n2491'>2491</a>
<a id='n2492' href='#n2492'>2492</a>
<a id='n2493' href='#n2493'>2493</a>
<a id='n2494' href='#n2494'>2494</a>
<a id='n2495' href='#n2495'>2495</a>
<a id='n2496' href='#n2496'>2496</a>
<a id='n2497' href='#n2497'>2497</a>
<a id='n2498' href='#n2498'>2498</a>
<a id='n2499' href='#n2499'>2499</a>
<a id='n2500' href='#n2500'>2500</a>
<a id='n2501' href='#n2501'>2501</a>
<a id='n2502' href='#n2502'>2502</a>
<a id='n2503' href='#n2503'>2503</a>
<a id='n2504' href='#n2504'>2504</a>
<a id='n2505' href='#n2505'>2505</a>
<a id='n2506' href='#n2506'>2506</a>
<a id='n2507' href='#n2507'>2507</a>
<a id='n2508' href='#n2508'>2508</a>
<a id='n2509' href='#n2509'>2509</a>
<a id='n2510' href='#n2510'>2510</a>
<a id='n2511' href='#n2511'>2511</a>
<a id='n2512' href='#n2512'>2512</a>
<a id='n2513' href='#n2513'>2513</a>
<a id='n2514' href='#n2514'>2514</a>
<a id='n2515' href='#n2515'>2515</a>
<a id='n2516' href='#n2516'>2516</a>
<a id='n2517' href='#n2517'>2517</a>
<a id='n2518' href='#n2518'>2518</a>
<a id='n2519' href='#n2519'>2519</a>
<a id='n2520' href='#n2520'>2520</a>
<a id='n2521' href='#n2521'>2521</a>
<a id='n2522' href='#n2522'>2522</a>
<a id='n2523' href='#n2523'>2523</a>
<a id='n2524' href='#n2524'>2524</a>
<a id='n2525' href='#n2525'>2525</a>
<a id='n2526' href='#n2526'>2526</a>
<a id='n2527' href='#n2527'>2527</a>
<a id='n2528' href='#n2528'>2528</a>
<a id='n2529' href='#n2529'>2529</a>
<a id='n2530' href='#n2530'>2530</a>
<a id='n2531' href='#n2531'>2531</a>
<a id='n2532' href='#n2532'>2532</a>
<a id='n2533' href='#n2533'>2533</a>
<a id='n2534' href='#n2534'>2534</a>
<a id='n2535' href='#n2535'>2535</a>
<a id='n2536' href='#n2536'>2536</a>
<a id='n2537' href='#n2537'>2537</a>
<a id='n2538' href='#n2538'>2538</a>
<a id='n2539' href='#n2539'>2539</a>
<a id='n2540' href='#n2540'>2540</a>
<a id='n2541' href='#n2541'>2541</a>
<a id='n2542' href='#n2542'>2542</a>
<a id='n2543' href='#n2543'>2543</a>
<a id='n2544' href='#n2544'>2544</a>
<a id='n2545' href='#n2545'>2545</a>
<a id='n2546' href='#n2546'>2546</a>
<a id='n2547' href='#n2547'>2547</a>
<a id='n2548' href='#n2548'>2548</a>
<a id='n2549' href='#n2549'>2549</a>
<a id='n2550' href='#n2550'>2550</a>
<a id='n2551' href='#n2551'>2551</a>
<a id='n2552' href='#n2552'>2552</a>
<a id='n2553' href='#n2553'>2553</a>
<a id='n2554' href='#n2554'>2554</a>
<a id='n2555' href='#n2555'>2555</a>
<a id='n2556' href='#n2556'>2556</a>
<a id='n2557' href='#n2557'>2557</a>
<a id='n2558' href='#n2558'>2558</a>
<a id='n2559' href='#n2559'>2559</a>
<a id='n2560' href='#n2560'>2560</a>
<a id='n2561' href='#n2561'>2561</a>
<a id='n2562' href='#n2562'>2562</a>
<a id='n2563' href='#n2563'>2563</a>
<a id='n2564' href='#n2564'>2564</a>
<a id='n2565' href='#n2565'>2565</a>
<a id='n2566' href='#n2566'>2566</a>
<a id='n2567' href='#n2567'>2567</a>
<a id='n2568' href='#n2568'>2568</a>
<a id='n2569' href='#n2569'>2569</a>
<a id='n2570' href='#n2570'>2570</a>
<a id='n2571' href='#n2571'>2571</a>
<a id='n2572' href='#n2572'>2572</a>
<a id='n2573' href='#n2573'>2573</a>
<a id='n2574' href='#n2574'>2574</a>
<a id='n2575' href='#n2575'>2575</a>
<a id='n2576' href='#n2576'>2576</a>
<a id='n2577' href='#n2577'>2577</a>
<a id='n2578' href='#n2578'>2578</a>
<a id='n2579' href='#n2579'>2579</a>
<a id='n2580' href='#n2580'>2580</a>
<a id='n2581' href='#n2581'>2581</a>
<a id='n2582' href='#n2582'>2582</a>
<a id='n2583' href='#n2583'>2583</a>
<a id='n2584' href='#n2584'>2584</a>
<a id='n2585' href='#n2585'>2585</a>
<a id='n2586' href='#n2586'>2586</a>
<a id='n2587' href='#n2587'>2587</a>
<a id='n2588' href='#n2588'>2588</a>
<a id='n2589' href='#n2589'>2589</a>
<a id='n2590' href='#n2590'>2590</a>
<a id='n2591' href='#n2591'>2591</a>
<a id='n2592' href='#n2592'>2592</a>
<a id='n2593' href='#n2593'>2593</a>
<a id='n2594' href='#n2594'>2594</a>
<a id='n2595' href='#n2595'>2595</a>
<a id='n2596' href='#n2596'>2596</a>
<a id='n2597' href='#n2597'>2597</a>
<a id='n2598' href='#n2598'>2598</a>
<a id='n2599' href='#n2599'>2599</a>
<a id='n2600' href='#n2600'>2600</a>
<a id='n2601' href='#n2601'>2601</a>
<a id='n2602' href='#n2602'>2602</a>
<a id='n2603' href='#n2603'>2603</a>
<a id='n2604' href='#n2604'>2604</a>
<a id='n2605' href='#n2605'>2605</a>
<a id='n2606' href='#n2606'>2606</a>
<a id='n2607' href='#n2607'>2607</a>
<a id='n2608' href='#n2608'>2608</a>
<a id='n2609' href='#n2609'>2609</a>
<a id='n2610' href='#n2610'>2610</a>
<a id='n2611' href='#n2611'>2611</a>
<a id='n2612' href='#n2612'>2612</a>
<a id='n2613' href='#n2613'>2613</a>
<a id='n2614' href='#n2614'>2614</a>
<a id='n2615' href='#n2615'>2615</a>
<a id='n2616' href='#n2616'>2616</a>
<a id='n2617' href='#n2617'>2617</a>
<a id='n2618' href='#n2618'>2618</a>
<a id='n2619' href='#n2619'>2619</a>
<a id='n2620' href='#n2620'>2620</a>
<a id='n2621' href='#n2621'>2621</a>
<a id='n2622' href='#n2622'>2622</a>
<a id='n2623' href='#n2623'>2623</a>
<a id='n2624' href='#n2624'>2624</a>
<a id='n2625' href='#n2625'>2625</a>
<a id='n2626' href='#n2626'>2626</a>
<a id='n2627' href='#n2627'>2627</a>
<a id='n2628' href='#n2628'>2628</a>
<a id='n2629' href='#n2629'>2629</a>
<a id='n2630' href='#n2630'>2630</a>
<a id='n2631' href='#n2631'>2631</a>
<a id='n2632' href='#n2632'>2632</a>
<a id='n2633' href='#n2633'>2633</a>
<a id='n2634' href='#n2634'>2634</a>
<a id='n2635' href='#n2635'>2635</a>
<a id='n2636' href='#n2636'>2636</a>
<a id='n2637' href='#n2637'>2637</a>
<a id='n2638' href='#n2638'>2638</a>
<a id='n2639' href='#n2639'>2639</a>
<a id='n2640' href='#n2640'>2640</a>
<a id='n2641' href='#n2641'>2641</a>
<a id='n2642' href='#n2642'>2642</a>
<a id='n2643' href='#n2643'>2643</a>
<a id='n2644' href='#n2644'>2644</a>
<a id='n2645' href='#n2645'>2645</a>
<a id='n2646' href='#n2646'>2646</a>
<a id='n2647' href='#n2647'>2647</a>
<a id='n2648' href='#n2648'>2648</a>
<a id='n2649' href='#n2649'>2649</a>
<a id='n2650' href='#n2650'>2650</a>
<a id='n2651' href='#n2651'>2651</a>
<a id='n2652' href='#n2652'>2652</a>
<a id='n2653' href='#n2653'>2653</a>
<a id='n2654' href='#n2654'>2654</a>
<a id='n2655' href='#n2655'>2655</a>
<a id='n2656' href='#n2656'>2656</a>
<a id='n2657' href='#n2657'>2657</a>
<a id='n2658' href='#n2658'>2658</a>
<a id='n2659' href='#n2659'>2659</a>
<a id='n2660' href='#n2660'>2660</a>
<a id='n2661' href='#n2661'>2661</a>
<a id='n2662' href='#n2662'>2662</a>
<a id='n2663' href='#n2663'>2663</a>
<a id='n2664' href='#n2664'>2664</a>
<a id='n2665' href='#n2665'>2665</a>
<a id='n2666' href='#n2666'>2666</a>
<a id='n2667' href='#n2667'>2667</a>
<a id='n2668' href='#n2668'>2668</a>
<a id='n2669' href='#n2669'>2669</a>
<a id='n2670' href='#n2670'>2670</a>
<a id='n2671' href='#n2671'>2671</a>
<a id='n2672' href='#n2672'>2672</a>
<a id='n2673' href='#n2673'>2673</a>
<a id='n2674' href='#n2674'>2674</a>
<a id='n2675' href='#n2675'>2675</a>
<a id='n2676' href='#n2676'>2676</a>
<a id='n2677' href='#n2677'>2677</a>
<a id='n2678' href='#n2678'>2678</a>
<a id='n2679' href='#n2679'>2679</a>
<a id='n2680' href='#n2680'>2680</a>
<a id='n2681' href='#n2681'>2681</a>
<a id='n2682' href='#n2682'>2682</a>
<a id='n2683' href='#n2683'>2683</a>
<a id='n2684' href='#n2684'>2684</a>
<a id='n2685' href='#n2685'>2685</a>
<a id='n2686' href='#n2686'>2686</a>
<a id='n2687' href='#n2687'>2687</a>
<a id='n2688' href='#n2688'>2688</a>
<a id='n2689' href='#n2689'>2689</a>
<a id='n2690' href='#n2690'>2690</a>
<a id='n2691' href='#n2691'>2691</a>
<a id='n2692' href='#n2692'>2692</a>
<a id='n2693' href='#n2693'>2693</a>
<a id='n2694' href='#n2694'>2694</a>
<a id='n2695' href='#n2695'>2695</a>
<a id='n2696' href='#n2696'>2696</a>
<a id='n2697' href='#n2697'>2697</a>
<a id='n2698' href='#n2698'>2698</a>
<a id='n2699' href='#n2699'>2699</a>
<a id='n2700' href='#n2700'>2700</a>
<a id='n2701' href='#n2701'>2701</a>
<a id='n2702' href='#n2702'>2702</a>
<a id='n2703' href='#n2703'>2703</a>
<a id='n2704' href='#n2704'>2704</a>
<a id='n2705' href='#n2705'>2705</a>
<a id='n2706' href='#n2706'>2706</a>
<a id='n2707' href='#n2707'>2707</a>
<a id='n2708' href='#n2708'>2708</a>
<a id='n2709' href='#n2709'>2709</a>
<a id='n2710' href='#n2710'>2710</a>
<a id='n2711' href='#n2711'>2711</a>
<a id='n2712' href='#n2712'>2712</a>
<a id='n2713' href='#n2713'>2713</a>
<a id='n2714' href='#n2714'>2714</a>
<a id='n2715' href='#n2715'>2715</a>
<a id='n2716' href='#n2716'>2716</a>
<a id='n2717' href='#n2717'>2717</a>
<a id='n2718' href='#n2718'>2718</a>
<a id='n2719' href='#n2719'>2719</a>
<a id='n2720' href='#n2720'>2720</a>
<a id='n2721' href='#n2721'>2721</a>
<a id='n2722' href='#n2722'>2722</a>
<a id='n2723' href='#n2723'>2723</a>
<a id='n2724' href='#n2724'>2724</a>
<a id='n2725' href='#n2725'>2725</a>
<a id='n2726' href='#n2726'>2726</a>
<a id='n2727' href='#n2727'>2727</a>
<a id='n2728' href='#n2728'>2728</a>
<a id='n2729' href='#n2729'>2729</a>
<a id='n2730' href='#n2730'>2730</a>
<a id='n2731' href='#n2731'>2731</a>
<a id='n2732' href='#n2732'>2732</a>
<a id='n2733' href='#n2733'>2733</a>
<a id='n2734' href='#n2734'>2734</a>
<a id='n2735' href='#n2735'>2735</a>
<a id='n2736' href='#n2736'>2736</a>
<a id='n2737' href='#n2737'>2737</a>
<a id='n2738' href='#n2738'>2738</a>
<a id='n2739' href='#n2739'>2739</a>
<a id='n2740' href='#n2740'>2740</a>
<a id='n2741' href='#n2741'>2741</a>
<a id='n2742' href='#n2742'>2742</a>
<a id='n2743' href='#n2743'>2743</a>
<a id='n2744' href='#n2744'>2744</a>
<a id='n2745' href='#n2745'>2745</a>
<a id='n2746' href='#n2746'>2746</a>
<a id='n2747' href='#n2747'>2747</a>
<a id='n2748' href='#n2748'>2748</a>
<a id='n2749' href='#n2749'>2749</a>
<a id='n2750' href='#n2750'>2750</a>
<a id='n2751' href='#n2751'>2751</a>
<a id='n2752' href='#n2752'>2752</a>
<a id='n2753' href='#n2753'>2753</a>
<a id='n2754' href='#n2754'>2754</a>
<a id='n2755' href='#n2755'>2755</a>
<a id='n2756' href='#n2756'>2756</a>
<a id='n2757' href='#n2757'>2757</a>
<a id='n2758' href='#n2758'>2758</a>
<a id='n2759' href='#n2759'>2759</a>
<a id='n2760' href='#n2760'>2760</a>
<a id='n2761' href='#n2761'>2761</a>
<a id='n2762' href='#n2762'>2762</a>
<a id='n2763' href='#n2763'>2763</a>
<a id='n2764' href='#n2764'>2764</a>
<a id='n2765' href='#n2765'>2765</a>
<a id='n2766' href='#n2766'>2766</a>
<a id='n2767' href='#n2767'>2767</a>
<a id='n2768' href='#n2768'>2768</a>
<a id='n2769' href='#n2769'>2769</a>
<a id='n2770' href='#n2770'>2770</a>
<a id='n2771' href='#n2771'>2771</a>
<a id='n2772' href='#n2772'>2772</a>
<a id='n2773' href='#n2773'>2773</a>
<a id='n2774' href='#n2774'>2774</a>
<a id='n2775' href='#n2775'>2775</a>
<a id='n2776' href='#n2776'>2776</a>
<a id='n2777' href='#n2777'>2777</a>
<a id='n2778' href='#n2778'>2778</a>
<a id='n2779' href='#n2779'>2779</a>
<a id='n2780' href='#n2780'>2780</a>
<a id='n2781' href='#n2781'>2781</a>
<a id='n2782' href='#n2782'>2782</a>
<a id='n2783' href='#n2783'>2783</a>
<a id='n2784' href='#n2784'>2784</a>
<a id='n2785' href='#n2785'>2785</a>
<a id='n2786' href='#n2786'>2786</a>
<a id='n2787' href='#n2787'>2787</a>
<a id='n2788' href='#n2788'>2788</a>
<a id='n2789' href='#n2789'>2789</a>
<a id='n2790' href='#n2790'>2790</a>
<a id='n2791' href='#n2791'>2791</a>
<a id='n2792' href='#n2792'>2792</a>
<a id='n2793' href='#n2793'>2793</a>
<a id='n2794' href='#n2794'>2794</a>
<a id='n2795' href='#n2795'>2795</a>
<a id='n2796' href='#n2796'>2796</a>
<a id='n2797' href='#n2797'>2797</a>
<a id='n2798' href='#n2798'>2798</a>
<a id='n2799' href='#n2799'>2799</a>
<a id='n2800' href='#n2800'>2800</a>
<a id='n2801' href='#n2801'>2801</a>
<a id='n2802' href='#n2802'>2802</a>
<a id='n2803' href='#n2803'>2803</a>
<a id='n2804' href='#n2804'>2804</a>
<a id='n2805' href='#n2805'>2805</a>
<a id='n2806' href='#n2806'>2806</a>
<a id='n2807' href='#n2807'>2807</a>
<a id='n2808' href='#n2808'>2808</a>
<a id='n2809' href='#n2809'>2809</a>
<a id='n2810' href='#n2810'>2810</a>
<a id='n2811' href='#n2811'>2811</a>
<a id='n2812' href='#n2812'>2812</a>
<a id='n2813' href='#n2813'>2813</a>
<a id='n2814' href='#n2814'>2814</a>
<a id='n2815' href='#n2815'>2815</a>
<a id='n2816' href='#n2816'>2816</a>
<a id='n2817' href='#n2817'>2817</a>
<a id='n2818' href='#n2818'>2818</a>
<a id='n2819' href='#n2819'>2819</a>
<a id='n2820' href='#n2820'>2820</a>
<a id='n2821' href='#n2821'>2821</a>
<a id='n2822' href='#n2822'>2822</a>
<a id='n2823' href='#n2823'>2823</a>
<a id='n2824' href='#n2824'>2824</a>
<a id='n2825' href='#n2825'>2825</a>
<a id='n2826' href='#n2826'>2826</a>
<a id='n2827' href='#n2827'>2827</a>
<a id='n2828' href='#n2828'>2828</a>
<a id='n2829' href='#n2829'>2829</a>
<a id='n2830' href='#n2830'>2830</a>
<a id='n2831' href='#n2831'>2831</a>
<a id='n2832' href='#n2832'>2832</a>
<a id='n2833' href='#n2833'>2833</a>
<a id='n2834' href='#n2834'>2834</a>
<a id='n2835' href='#n2835'>2835</a>
<a id='n2836' href='#n2836'>2836</a>
<a id='n2837' href='#n2837'>2837</a>
<a id='n2838' href='#n2838'>2838</a>
<a id='n2839' href='#n2839'>2839</a>
<a id='n2840' href='#n2840'>2840</a>
<a id='n2841' href='#n2841'>2841</a>
<a id='n2842' href='#n2842'>2842</a>
<a id='n2843' href='#n2843'>2843</a>
<a id='n2844' href='#n2844'>2844</a>
<a id='n2845' href='#n2845'>2845</a>
<a id='n2846' href='#n2846'>2846</a>
<a id='n2847' href='#n2847'>2847</a>
<a id='n2848' href='#n2848'>2848</a>
<a id='n2849' href='#n2849'>2849</a>
<a id='n2850' href='#n2850'>2850</a>
<a id='n2851' href='#n2851'>2851</a>
<a id='n2852' href='#n2852'>2852</a>
<a id='n2853' href='#n2853'>2853</a>
<a id='n2854' href='#n2854'>2854</a>
<a id='n2855' href='#n2855'>2855</a>
<a id='n2856' href='#n2856'>2856</a>
<a id='n2857' href='#n2857'>2857</a>
<a id='n2858' href='#n2858'>2858</a>
<a id='n2859' href='#n2859'>2859</a>
<a id='n2860' href='#n2860'>2860</a>
<a id='n2861' href='#n2861'>2861</a>
<a id='n2862' href='#n2862'>2862</a>
<a id='n2863' href='#n2863'>2863</a>
<a id='n2864' href='#n2864'>2864</a>
<a id='n2865' href='#n2865'>2865</a>
<a id='n2866' href='#n2866'>2866</a>
<a id='n2867' href='#n2867'>2867</a>
<a id='n2868' href='#n2868'>2868</a>
<a id='n2869' href='#n2869'>2869</a>
<a id='n2870' href='#n2870'>2870</a>
<a id='n2871' href='#n2871'>2871</a>
<a id='n2872' href='#n2872'>2872</a>
<a id='n2873' href='#n2873'>2873</a>
<a id='n2874' href='#n2874'>2874</a>
<a id='n2875' href='#n2875'>2875</a>
<a id='n2876' href='#n2876'>2876</a>
<a id='n2877' href='#n2877'>2877</a>
<a id='n2878' href='#n2878'>2878</a>
<a id='n2879' href='#n2879'>2879</a>
<a id='n2880' href='#n2880'>2880</a>
<a id='n2881' href='#n2881'>2881</a>
<a id='n2882' href='#n2882'>2882</a>
<a id='n2883' href='#n2883'>2883</a>
<a id='n2884' href='#n2884'>2884</a>
<a id='n2885' href='#n2885'>2885</a>
<a id='n2886' href='#n2886'>2886</a>
<a id='n2887' href='#n2887'>2887</a>
<a id='n2888' href='#n2888'>2888</a>
<a id='n2889' href='#n2889'>2889</a>
<a id='n2890' href='#n2890'>2890</a>
<a id='n2891' href='#n2891'>2891</a>
<a id='n2892' href='#n2892'>2892</a>
<a id='n2893' href='#n2893'>2893</a>
<a id='n2894' href='#n2894'>2894</a>
<a id='n2895' href='#n2895'>2895</a>
<a id='n2896' href='#n2896'>2896</a>
<a id='n2897' href='#n2897'>2897</a>
<a id='n2898' href='#n2898'>2898</a>
<a id='n2899' href='#n2899'>2899</a>
<a id='n2900' href='#n2900'>2900</a>
<a id='n2901' href='#n2901'>2901</a>
<a id='n2902' href='#n2902'>2902</a>
<a id='n2903' href='#n2903'>2903</a>
<a id='n2904' href='#n2904'>2904</a>
<a id='n2905' href='#n2905'>2905</a>
<a id='n2906' href='#n2906'>2906</a>
<a id='n2907' href='#n2907'>2907</a>
<a id='n2908' href='#n2908'>2908</a>
<a id='n2909' href='#n2909'>2909</a>
<a id='n2910' href='#n2910'>2910</a>
<a id='n2911' href='#n2911'>2911</a>
<a id='n2912' href='#n2912'>2912</a>
<a id='n2913' href='#n2913'>2913</a>
<a id='n2914' href='#n2914'>2914</a>
<a id='n2915' href='#n2915'>2915</a>
<a id='n2916' href='#n2916'>2916</a>
<a id='n2917' href='#n2917'>2917</a>
<a id='n2918' href='#n2918'>2918</a>
<a id='n2919' href='#n2919'>2919</a>
<a id='n2920' href='#n2920'>2920</a>
<a id='n2921' href='#n2921'>2921</a>
<a id='n2922' href='#n2922'>2922</a>
<a id='n2923' href='#n2923'>2923</a>
<a id='n2924' href='#n2924'>2924</a>
<a id='n2925' href='#n2925'>2925</a>
<a id='n2926' href='#n2926'>2926</a>
<a id='n2927' href='#n2927'>2927</a>
<a id='n2928' href='#n2928'>2928</a>
<a id='n2929' href='#n2929'>2929</a>
<a id='n2930' href='#n2930'>2930</a>
<a id='n2931' href='#n2931'>2931</a>
<a id='n2932' href='#n2932'>2932</a>
<a id='n2933' href='#n2933'>2933</a>
<a id='n2934' href='#n2934'>2934</a>
<a id='n2935' href='#n2935'>2935</a>
<a id='n2936' href='#n2936'>2936</a>
<a id='n2937' href='#n2937'>2937</a>
<a id='n2938' href='#n2938'>2938</a>
<a id='n2939' href='#n2939'>2939</a>
<a id='n2940' href='#n2940'>2940</a>
<a id='n2941' href='#n2941'>2941</a>
<a id='n2942' href='#n2942'>2942</a>
<a id='n2943' href='#n2943'>2943</a>
<a id='n2944' href='#n2944'>2944</a>
<a id='n2945' href='#n2945'>2945</a>
<a id='n2946' href='#n2946'>2946</a>
<a id='n2947' href='#n2947'>2947</a>
<a id='n2948' href='#n2948'>2948</a>
<a id='n2949' href='#n2949'>2949</a>
<a id='n2950' href='#n2950'>2950</a>
<a id='n2951' href='#n2951'>2951</a>
<a id='n2952' href='#n2952'>2952</a>
<a id='n2953' href='#n2953'>2953</a>
<a id='n2954' href='#n2954'>2954</a>
<a id='n2955' href='#n2955'>2955</a>
<a id='n2956' href='#n2956'>2956</a>
<a id='n2957' href='#n2957'>2957</a>
<a id='n2958' href='#n2958'>2958</a>
<a id='n2959' href='#n2959'>2959</a>
<a id='n2960' href='#n2960'>2960</a>
<a id='n2961' href='#n2961'>2961</a>
<a id='n2962' href='#n2962'>2962</a>
<a id='n2963' href='#n2963'>2963</a>
<a id='n2964' href='#n2964'>2964</a>
<a id='n2965' href='#n2965'>2965</a>
<a id='n2966' href='#n2966'>2966</a>
<a id='n2967' href='#n2967'>2967</a>
<a id='n2968' href='#n2968'>2968</a>
<a id='n2969' href='#n2969'>2969</a>
<a id='n2970' href='#n2970'>2970</a>
<a id='n2971' href='#n2971'>2971</a>
<a id='n2972' href='#n2972'>2972</a>
<a id='n2973' href='#n2973'>2973</a>
<a id='n2974' href='#n2974'>2974</a>
<a id='n2975' href='#n2975'>2975</a>
<a id='n2976' href='#n2976'>2976</a>
<a id='n2977' href='#n2977'>2977</a>
<a id='n2978' href='#n2978'>2978</a>
<a id='n2979' href='#n2979'>2979</a>
<a id='n2980' href='#n2980'>2980</a>
<a id='n2981' href='#n2981'>2981</a>
<a id='n2982' href='#n2982'>2982</a>
<a id='n2983' href='#n2983'>2983</a>
<a id='n2984' href='#n2984'>2984</a>
<a id='n2985' href='#n2985'>2985</a>
<a id='n2986' href='#n2986'>2986</a>
<a id='n2987' href='#n2987'>2987</a>
<a id='n2988' href='#n2988'>2988</a>
<a id='n2989' href='#n2989'>2989</a>
<a id='n2990' href='#n2990'>2990</a>
<a id='n2991' href='#n2991'>2991</a>
<a id='n2992' href='#n2992'>2992</a>
<a id='n2993' href='#n2993'>2993</a>
<a id='n2994' href='#n2994'>2994</a>
<a id='n2995' href='#n2995'>2995</a>
<a id='n2996' href='#n2996'>2996</a>
<a id='n2997' href='#n2997'>2997</a>
<a id='n2998' href='#n2998'>2998</a>
<a id='n2999' href='#n2999'>2999</a>
<a id='n3000' href='#n3000'>3000</a>
<a id='n3001' href='#n3001'>3001</a>
<a id='n3002' href='#n3002'>3002</a>
<a id='n3003' href='#n3003'>3003</a>
<a id='n3004' href='#n3004'>3004</a>
<a id='n3005' href='#n3005'>3005</a>
<a id='n3006' href='#n3006'>3006</a>
<a id='n3007' href='#n3007'>3007</a>
<a id='n3008' href='#n3008'>3008</a>
<a id='n3009' href='#n3009'>3009</a>
<a id='n3010' href='#n3010'>3010</a>
<a id='n3011' href='#n3011'>3011</a>
<a id='n3012' href='#n3012'>3012</a>
<a id='n3013' href='#n3013'>3013</a>
<a id='n3014' href='#n3014'>3014</a>
<a id='n3015' href='#n3015'>3015</a>
<a id='n3016' href='#n3016'>3016</a>
<a id='n3017' href='#n3017'>3017</a>
<a id='n3018' href='#n3018'>3018</a>
<a id='n3019' href='#n3019'>3019</a>
<a id='n3020' href='#n3020'>3020</a>
<a id='n3021' href='#n3021'>3021</a>
<a id='n3022' href='#n3022'>3022</a>
<a id='n3023' href='#n3023'>3023</a>
<a id='n3024' href='#n3024'>3024</a>
<a id='n3025' href='#n3025'>3025</a>
<a id='n3026' href='#n3026'>3026</a>
<a id='n3027' href='#n3027'>3027</a>
<a id='n3028' href='#n3028'>3028</a>
<a id='n3029' href='#n3029'>3029</a>
<a id='n3030' href='#n3030'>3030</a>
<a id='n3031' href='#n3031'>3031</a>
<a id='n3032' href='#n3032'>3032</a>
<a id='n3033' href='#n3033'>3033</a>
<a id='n3034' href='#n3034'>3034</a>
<a id='n3035' href='#n3035'>3035</a>
<a id='n3036' href='#n3036'>3036</a>
<a id='n3037' href='#n3037'>3037</a>
<a id='n3038' href='#n3038'>3038</a>
<a id='n3039' href='#n3039'>3039</a>
<a id='n3040' href='#n3040'>3040</a>
<a id='n3041' href='#n3041'>3041</a>
<a id='n3042' href='#n3042'>3042</a>
<a id='n3043' href='#n3043'>3043</a>
<a id='n3044' href='#n3044'>3044</a>
<a id='n3045' href='#n3045'>3045</a>
<a id='n3046' href='#n3046'>3046</a>
<a id='n3047' href='#n3047'>3047</a>
<a id='n3048' href='#n3048'>3048</a>
<a id='n3049' href='#n3049'>3049</a>
<a id='n3050' href='#n3050'>3050</a>
<a id='n3051' href='#n3051'>3051</a>
<a id='n3052' href='#n3052'>3052</a>
<a id='n3053' href='#n3053'>3053</a>
<a id='n3054' href='#n3054'>3054</a>
<a id='n3055' href='#n3055'>3055</a>
<a id='n3056' href='#n3056'>3056</a>
<a id='n3057' href='#n3057'>3057</a>
<a id='n3058' href='#n3058'>3058</a>
<a id='n3059' href='#n3059'>3059</a>
<a id='n3060' href='#n3060'>3060</a>
<a id='n3061' href='#n3061'>3061</a>
<a id='n3062' href='#n3062'>3062</a>
<a id='n3063' href='#n3063'>3063</a>
<a id='n3064' href='#n3064'>3064</a>
<a id='n3065' href='#n3065'>3065</a>
<a id='n3066' href='#n3066'>3066</a>
<a id='n3067' href='#n3067'>3067</a>
<a id='n3068' href='#n3068'>3068</a>
<a id='n3069' href='#n3069'>3069</a>
<a id='n3070' href='#n3070'>3070</a>
<a id='n3071' href='#n3071'>3071</a>
<a id='n3072' href='#n3072'>3072</a>
<a id='n3073' href='#n3073'>3073</a>
<a id='n3074' href='#n3074'>3074</a>
<a id='n3075' href='#n3075'>3075</a>
<a id='n3076' href='#n3076'>3076</a>
<a id='n3077' href='#n3077'>3077</a>
<a id='n3078' href='#n3078'>3078</a>
<a id='n3079' href='#n3079'>3079</a>
<a id='n3080' href='#n3080'>3080</a>
<a id='n3081' href='#n3081'>3081</a>
<a id='n3082' href='#n3082'>3082</a>
<a id='n3083' href='#n3083'>3083</a>
<a id='n3084' href='#n3084'>3084</a>
<a id='n3085' href='#n3085'>3085</a>
<a id='n3086' href='#n3086'>3086</a>
<a id='n3087' href='#n3087'>3087</a>
<a id='n3088' href='#n3088'>3088</a>
<a id='n3089' href='#n3089'>3089</a>
<a id='n3090' href='#n3090'>3090</a>
<a id='n3091' href='#n3091'>3091</a>
<a id='n3092' href='#n3092'>3092</a>
<a id='n3093' href='#n3093'>3093</a>
<a id='n3094' href='#n3094'>3094</a>
<a id='n3095' href='#n3095'>3095</a>
<a id='n3096' href='#n3096'>3096</a>
<a id='n3097' href='#n3097'>3097</a>
<a id='n3098' href='#n3098'>3098</a>
<a id='n3099' href='#n3099'>3099</a>
<a id='n3100' href='#n3100'>3100</a>
<a id='n3101' href='#n3101'>3101</a>
<a id='n3102' href='#n3102'>3102</a>
<a id='n3103' href='#n3103'>3103</a>
<a id='n3104' href='#n3104'>3104</a>
<a id='n3105' href='#n3105'>3105</a>
<a id='n3106' href='#n3106'>3106</a>
<a id='n3107' href='#n3107'>3107</a>
<a id='n3108' href='#n3108'>3108</a>
<a id='n3109' href='#n3109'>3109</a>
<a id='n3110' href='#n3110'>3110</a>
<a id='n3111' href='#n3111'>3111</a>
<a id='n3112' href='#n3112'>3112</a>
<a id='n3113' href='#n3113'>3113</a>
<a id='n3114' href='#n3114'>3114</a>
<a id='n3115' href='#n3115'>3115</a>
<a id='n3116' href='#n3116'>3116</a>
<a id='n3117' href='#n3117'>3117</a>
<a id='n3118' href='#n3118'>3118</a>
<a id='n3119' href='#n3119'>3119</a>
<a id='n3120' href='#n3120'>3120</a>
<a id='n3121' href='#n3121'>3121</a>
<a id='n3122' href='#n3122'>3122</a>
<a id='n3123' href='#n3123'>3123</a>
<a id='n3124' href='#n3124'>3124</a>
<a id='n3125' href='#n3125'>3125</a>
<a id='n3126' href='#n3126'>3126</a>
<a id='n3127' href='#n3127'>3127</a>
<a id='n3128' href='#n3128'>3128</a>
<a id='n3129' href='#n3129'>3129</a>
<a id='n3130' href='#n3130'>3130</a>
<a id='n3131' href='#n3131'>3131</a>
<a id='n3132' href='#n3132'>3132</a>
<a id='n3133' href='#n3133'>3133</a>
<a id='n3134' href='#n3134'>3134</a>
<a id='n3135' href='#n3135'>3135</a>
<a id='n3136' href='#n3136'>3136</a>
<a id='n3137' href='#n3137'>3137</a>
<a id='n3138' href='#n3138'>3138</a>
<a id='n3139' href='#n3139'>3139</a>
<a id='n3140' href='#n3140'>3140</a>
<a id='n3141' href='#n3141'>3141</a>
<a id='n3142' href='#n3142'>3142</a>
<a id='n3143' href='#n3143'>3143</a>
<a id='n3144' href='#n3144'>3144</a>
<a id='n3145' href='#n3145'>3145</a>
<a id='n3146' href='#n3146'>3146</a>
<a id='n3147' href='#n3147'>3147</a>
<a id='n3148' href='#n3148'>3148</a>
<a id='n3149' href='#n3149'>3149</a>
<a id='n3150' href='#n3150'>3150</a>
<a id='n3151' href='#n3151'>3151</a>
<a id='n3152' href='#n3152'>3152</a>
<a id='n3153' href='#n3153'>3153</a>
<a id='n3154' href='#n3154'>3154</a>
<a id='n3155' href='#n3155'>3155</a>
<a id='n3156' href='#n3156'>3156</a>
<a id='n3157' href='#n3157'>3157</a>
<a id='n3158' href='#n3158'>3158</a>
<a id='n3159' href='#n3159'>3159</a>
<a id='n3160' href='#n3160'>3160</a>
<a id='n3161' href='#n3161'>3161</a>
<a id='n3162' href='#n3162'>3162</a>
<a id='n3163' href='#n3163'>3163</a>
<a id='n3164' href='#n3164'>3164</a>
<a id='n3165' href='#n3165'>3165</a>
<a id='n3166' href='#n3166'>3166</a>
<a id='n3167' href='#n3167'>3167</a>
<a id='n3168' href='#n3168'>3168</a>
<a id='n3169' href='#n3169'>3169</a>
<a id='n3170' href='#n3170'>3170</a>
<a id='n3171' href='#n3171'>3171</a>
<a id='n3172' href='#n3172'>3172</a>
<a id='n3173' href='#n3173'>3173</a>
<a id='n3174' href='#n3174'>3174</a>
<a id='n3175' href='#n3175'>3175</a>
<a id='n3176' href='#n3176'>3176</a>
<a id='n3177' href='#n3177'>3177</a>
<a id='n3178' href='#n3178'>3178</a>
<a id='n3179' href='#n3179'>3179</a>
<a id='n3180' href='#n3180'>3180</a>
<a id='n3181' href='#n3181'>3181</a>
<a id='n3182' href='#n3182'>3182</a>
<a id='n3183' href='#n3183'>3183</a>
<a id='n3184' href='#n3184'>3184</a>
<a id='n3185' href='#n3185'>3185</a>
<a id='n3186' href='#n3186'>3186</a>
<a id='n3187' href='#n3187'>3187</a>
<a id='n3188' href='#n3188'>3188</a>
<a id='n3189' href='#n3189'>3189</a>
<a id='n3190' href='#n3190'>3190</a>
<a id='n3191' href='#n3191'>3191</a>
<a id='n3192' href='#n3192'>3192</a>
<a id='n3193' href='#n3193'>3193</a>
<a id='n3194' href='#n3194'>3194</a>
<a id='n3195' href='#n3195'>3195</a>
<a id='n3196' href='#n3196'>3196</a>
<a id='n3197' href='#n3197'>3197</a>
<a id='n3198' href='#n3198'>3198</a>
<a id='n3199' href='#n3199'>3199</a>
<a id='n3200' href='#n3200'>3200</a>
<a id='n3201' href='#n3201'>3201</a>
<a id='n3202' href='#n3202'>3202</a>
<a id='n3203' href='#n3203'>3203</a>
<a id='n3204' href='#n3204'>3204</a>
<a id='n3205' href='#n3205'>3205</a>
<a id='n3206' href='#n3206'>3206</a>
<a id='n3207' href='#n3207'>3207</a>
<a id='n3208' href='#n3208'>3208</a>
<a id='n3209' href='#n3209'>3209</a>
<a id='n3210' href='#n3210'>3210</a>
<a id='n3211' href='#n3211'>3211</a>
<a id='n3212' href='#n3212'>3212</a>
<a id='n3213' href='#n3213'>3213</a>
<a id='n3214' href='#n3214'>3214</a>
<a id='n3215' href='#n3215'>3215</a>
<a id='n3216' href='#n3216'>3216</a>
<a id='n3217' href='#n3217'>3217</a>
<a id='n3218' href='#n3218'>3218</a>
<a id='n3219' href='#n3219'>3219</a>
<a id='n3220' href='#n3220'>3220</a>
<a id='n3221' href='#n3221'>3221</a>
<a id='n3222' href='#n3222'>3222</a>
<a id='n3223' href='#n3223'>3223</a>
<a id='n3224' href='#n3224'>3224</a>
<a id='n3225' href='#n3225'>3225</a>
<a id='n3226' href='#n3226'>3226</a>
<a id='n3227' href='#n3227'>3227</a>
<a id='n3228' href='#n3228'>3228</a>
<a id='n3229' href='#n3229'>3229</a>
<a id='n3230' href='#n3230'>3230</a>
<a id='n3231' href='#n3231'>3231</a>
<a id='n3232' href='#n3232'>3232</a>
<a id='n3233' href='#n3233'>3233</a>
<a id='n3234' href='#n3234'>3234</a>
<a id='n3235' href='#n3235'>3235</a>
<a id='n3236' href='#n3236'>3236</a>
<a id='n3237' href='#n3237'>3237</a>
<a id='n3238' href='#n3238'>3238</a>
<a id='n3239' href='#n3239'>3239</a>
<a id='n3240' href='#n3240'>3240</a>
<a id='n3241' href='#n3241'>3241</a>
<a id='n3242' href='#n3242'>3242</a>
<a id='n3243' href='#n3243'>3243</a>
<a id='n3244' href='#n3244'>3244</a>
<a id='n3245' href='#n3245'>3245</a>
<a id='n3246' href='#n3246'>3246</a>
<a id='n3247' href='#n3247'>3247</a>
<a id='n3248' href='#n3248'>3248</a>
<a id='n3249' href='#n3249'>3249</a>
<a id='n3250' href='#n3250'>3250</a>
<a id='n3251' href='#n3251'>3251</a>
<a id='n3252' href='#n3252'>3252</a>
<a id='n3253' href='#n3253'>3253</a>
<a id='n3254' href='#n3254'>3254</a>
<a id='n3255' href='#n3255'>3255</a>
<a id='n3256' href='#n3256'>3256</a>
<a id='n3257' href='#n3257'>3257</a>
<a id='n3258' href='#n3258'>3258</a>
<a id='n3259' href='#n3259'>3259</a>
<a id='n3260' href='#n3260'>3260</a>
<a id='n3261' href='#n3261'>3261</a>
<a id='n3262' href='#n3262'>3262</a>
<a id='n3263' href='#n3263'>3263</a>
<a id='n3264' href='#n3264'>3264</a>
<a id='n3265' href='#n3265'>3265</a>
<a id='n3266' href='#n3266'>3266</a>
<a id='n3267' href='#n3267'>3267</a>
<a id='n3268' href='#n3268'>3268</a>
<a id='n3269' href='#n3269'>3269</a>
<a id='n3270' href='#n3270'>3270</a>
<a id='n3271' href='#n3271'>3271</a>
<a id='n3272' href='#n3272'>3272</a>
<a id='n3273' href='#n3273'>3273</a>
<a id='n3274' href='#n3274'>3274</a>
<a id='n3275' href='#n3275'>3275</a>
<a id='n3276' href='#n3276'>3276</a>
<a id='n3277' href='#n3277'>3277</a>
<a id='n3278' href='#n3278'>3278</a>
<a id='n3279' href='#n3279'>3279</a>
<a id='n3280' href='#n3280'>3280</a>
<a id='n3281' href='#n3281'>3281</a>
<a id='n3282' href='#n3282'>3282</a>
<a id='n3283' href='#n3283'>3283</a>
<a id='n3284' href='#n3284'>3284</a>
<a id='n3285' href='#n3285'>3285</a>
<a id='n3286' href='#n3286'>3286</a>
<a id='n3287' href='#n3287'>3287</a>
<a id='n3288' href='#n3288'>3288</a>
<a id='n3289' href='#n3289'>3289</a>
<a id='n3290' href='#n3290'>3290</a>
<a id='n3291' href='#n3291'>3291</a>
<a id='n3292' href='#n3292'>3292</a>
<a id='n3293' href='#n3293'>3293</a>
<a id='n3294' href='#n3294'>3294</a>
<a id='n3295' href='#n3295'>3295</a>
<a id='n3296' href='#n3296'>3296</a>
<a id='n3297' href='#n3297'>3297</a>
<a id='n3298' href='#n3298'>3298</a>
<a id='n3299' href='#n3299'>3299</a>
<a id='n3300' href='#n3300'>3300</a>
<a id='n3301' href='#n3301'>3301</a>
<a id='n3302' href='#n3302'>3302</a>
<a id='n3303' href='#n3303'>3303</a>
<a id='n3304' href='#n3304'>3304</a>
<a id='n3305' href='#n3305'>3305</a>
<a id='n3306' href='#n3306'>3306</a>
<a id='n3307' href='#n3307'>3307</a>
<a id='n3308' href='#n3308'>3308</a>
<a id='n3309' href='#n3309'>3309</a>
<a id='n3310' href='#n3310'>3310</a>
<a id='n3311' href='#n3311'>3311</a>
<a id='n3312' href='#n3312'>3312</a>
<a id='n3313' href='#n3313'>3313</a>
<a id='n3314' href='#n3314'>3314</a>
<a id='n3315' href='#n3315'>3315</a>
<a id='n3316' href='#n3316'>3316</a>
<a id='n3317' href='#n3317'>3317</a>
<a id='n3318' href='#n3318'>3318</a>
<a id='n3319' href='#n3319'>3319</a>
<a id='n3320' href='#n3320'>3320</a>
<a id='n3321' href='#n3321'>3321</a>
<a id='n3322' href='#n3322'>3322</a>
<a id='n3323' href='#n3323'>3323</a>
<a id='n3324' href='#n3324'>3324</a>
<a id='n3325' href='#n3325'>3325</a>
<a id='n3326' href='#n3326'>3326</a>
<a id='n3327' href='#n3327'>3327</a>
<a id='n3328' href='#n3328'>3328</a>
<a id='n3329' href='#n3329'>3329</a>
<a id='n3330' href='#n3330'>3330</a>
<a id='n3331' href='#n3331'>3331</a>
<a id='n3332' href='#n3332'>3332</a>
<a id='n3333' href='#n3333'>3333</a>
<a id='n3334' href='#n3334'>3334</a>
<a id='n3335' href='#n3335'>3335</a>
<a id='n3336' href='#n3336'>3336</a>
<a id='n3337' href='#n3337'>3337</a>
<a id='n3338' href='#n3338'>3338</a>
<a id='n3339' href='#n3339'>3339</a>
<a id='n3340' href='#n3340'>3340</a>
<a id='n3341' href='#n3341'>3341</a>
<a id='n3342' href='#n3342'>3342</a>
<a id='n3343' href='#n3343'>3343</a>
<a id='n3344' href='#n3344'>3344</a>
<a id='n3345' href='#n3345'>3345</a>
<a id='n3346' href='#n3346'>3346</a>
<a id='n3347' href='#n3347'>3347</a>
<a id='n3348' href='#n3348'>3348</a>
<a id='n3349' href='#n3349'>3349</a>
<a id='n3350' href='#n3350'>3350</a>
<a id='n3351' href='#n3351'>3351</a>
<a id='n3352' href='#n3352'>3352</a>
<a id='n3353' href='#n3353'>3353</a>
<a id='n3354' href='#n3354'>3354</a>
<a id='n3355' href='#n3355'>3355</a>
<a id='n3356' href='#n3356'>3356</a>
<a id='n3357' href='#n3357'>3357</a>
<a id='n3358' href='#n3358'>3358</a>
<a id='n3359' href='#n3359'>3359</a>
<a id='n3360' href='#n3360'>3360</a>
<a id='n3361' href='#n3361'>3361</a>
<a id='n3362' href='#n3362'>3362</a>
<a id='n3363' href='#n3363'>3363</a>
<a id='n3364' href='#n3364'>3364</a>
<a id='n3365' href='#n3365'>3365</a>
<a id='n3366' href='#n3366'>3366</a>
<a id='n3367' href='#n3367'>3367</a>
<a id='n3368' href='#n3368'>3368</a>
<a id='n3369' href='#n3369'>3369</a>
<a id='n3370' href='#n3370'>3370</a>
<a id='n3371' href='#n3371'>3371</a>
<a id='n3372' href='#n3372'>3372</a>
<a id='n3373' href='#n3373'>3373</a>
<a id='n3374' href='#n3374'>3374</a>
<a id='n3375' href='#n3375'>3375</a>
<a id='n3376' href='#n3376'>3376</a>
<a id='n3377' href='#n3377'>3377</a>
<a id='n3378' href='#n3378'>3378</a>
<a id='n3379' href='#n3379'>3379</a>
<a id='n3380' href='#n3380'>3380</a>
<a id='n3381' href='#n3381'>3381</a>
<a id='n3382' href='#n3382'>3382</a>
<a id='n3383' href='#n3383'>3383</a>
<a id='n3384' href='#n3384'>3384</a>
<a id='n3385' href='#n3385'>3385</a>
<a id='n3386' href='#n3386'>3386</a>
<a id='n3387' href='#n3387'>3387</a>
<a id='n3388' href='#n3388'>3388</a>
<a id='n3389' href='#n3389'>3389</a>
<a id='n3390' href='#n3390'>3390</a>
<a id='n3391' href='#n3391'>3391</a>
<a id='n3392' href='#n3392'>3392</a>
<a id='n3393' href='#n3393'>3393</a>
<a id='n3394' href='#n3394'>3394</a>
<a id='n3395' href='#n3395'>3395</a>
<a id='n3396' href='#n3396'>3396</a>
<a id='n3397' href='#n3397'>3397</a>
<a id='n3398' href='#n3398'>3398</a>
<a id='n3399' href='#n3399'>3399</a>
<a id='n3400' href='#n3400'>3400</a>
<a id='n3401' href='#n3401'>3401</a>
<a id='n3402' href='#n3402'>3402</a>
<a id='n3403' href='#n3403'>3403</a>
<a id='n3404' href='#n3404'>3404</a>
<a id='n3405' href='#n3405'>3405</a>
<a id='n3406' href='#n3406'>3406</a>
<a id='n3407' href='#n3407'>3407</a>
<a id='n3408' href='#n3408'>3408</a>
<a id='n3409' href='#n3409'>3409</a>
<a id='n3410' href='#n3410'>3410</a>
<a id='n3411' href='#n3411'>3411</a>
<a id='n3412' href='#n3412'>3412</a>
<a id='n3413' href='#n3413'>3413</a>
<a id='n3414' href='#n3414'>3414</a>
<a id='n3415' href='#n3415'>3415</a>
<a id='n3416' href='#n3416'>3416</a>
<a id='n3417' href='#n3417'>3417</a>
<a id='n3418' href='#n3418'>3418</a>
<a id='n3419' href='#n3419'>3419</a>
<a id='n3420' href='#n3420'>3420</a>
<a id='n3421' href='#n3421'>3421</a>
<a id='n3422' href='#n3422'>3422</a>
<a id='n3423' href='#n3423'>3423</a>
<a id='n3424' href='#n3424'>3424</a>
<a id='n3425' href='#n3425'>3425</a>
<a id='n3426' href='#n3426'>3426</a>
<a id='n3427' href='#n3427'>3427</a>
<a id='n3428' href='#n3428'>3428</a>
<a id='n3429' href='#n3429'>3429</a>
<a id='n3430' href='#n3430'>3430</a>
<a id='n3431' href='#n3431'>3431</a>
<a id='n3432' href='#n3432'>3432</a>
<a id='n3433' href='#n3433'>3433</a>
<a id='n3434' href='#n3434'>3434</a>
<a id='n3435' href='#n3435'>3435</a>
<a id='n3436' href='#n3436'>3436</a>
<a id='n3437' href='#n3437'>3437</a>
<a id='n3438' href='#n3438'>3438</a>
<a id='n3439' href='#n3439'>3439</a>
<a id='n3440' href='#n3440'>3440</a>
<a id='n3441' href='#n3441'>3441</a>
<a id='n3442' href='#n3442'>3442</a>
<a id='n3443' href='#n3443'>3443</a>
<a id='n3444' href='#n3444'>3444</a>
<a id='n3445' href='#n3445'>3445</a>
<a id='n3446' href='#n3446'>3446</a>
<a id='n3447' href='#n3447'>3447</a>
<a id='n3448' href='#n3448'>3448</a>
<a id='n3449' href='#n3449'>3449</a>
<a id='n3450' href='#n3450'>3450</a>
<a id='n3451' href='#n3451'>3451</a>
<a id='n3452' href='#n3452'>3452</a>
<a id='n3453' href='#n3453'>3453</a>
<a id='n3454' href='#n3454'>3454</a>
<a id='n3455' href='#n3455'>3455</a>
<a id='n3456' href='#n3456'>3456</a>
<a id='n3457' href='#n3457'>3457</a>
<a id='n3458' href='#n3458'>3458</a>
<a id='n3459' href='#n3459'>3459</a>
<a id='n3460' href='#n3460'>3460</a>
<a id='n3461' href='#n3461'>3461</a>
<a id='n3462' href='#n3462'>3462</a>
<a id='n3463' href='#n3463'>3463</a>
<a id='n3464' href='#n3464'>3464</a>
<a id='n3465' href='#n3465'>3465</a>
<a id='n3466' href='#n3466'>3466</a>
<a id='n3467' href='#n3467'>3467</a>
<a id='n3468' href='#n3468'>3468</a>
<a id='n3469' href='#n3469'>3469</a>
<a id='n3470' href='#n3470'>3470</a>
<a id='n3471' href='#n3471'>3471</a>
<a id='n3472' href='#n3472'>3472</a>
<a id='n3473' href='#n3473'>3473</a>
<a id='n3474' href='#n3474'>3474</a>
<a id='n3475' href='#n3475'>3475</a>
<a id='n3476' href='#n3476'>3476</a>
<a id='n3477' href='#n3477'>3477</a>
<a id='n3478' href='#n3478'>3478</a>
<a id='n3479' href='#n3479'>3479</a>
<a id='n3480' href='#n3480'>3480</a>
<a id='n3481' href='#n3481'>3481</a>
<a id='n3482' href='#n3482'>3482</a>
<a id='n3483' href='#n3483'>3483</a>
<a id='n3484' href='#n3484'>3484</a>
<a id='n3485' href='#n3485'>3485</a>
<a id='n3486' href='#n3486'>3486</a>
<a id='n3487' href='#n3487'>3487</a>
<a id='n3488' href='#n3488'>3488</a>
<a id='n3489' href='#n3489'>3489</a>
<a id='n3490' href='#n3490'>3490</a>
<a id='n3491' href='#n3491'>3491</a>
<a id='n3492' href='#n3492'>3492</a>
<a id='n3493' href='#n3493'>3493</a>
<a id='n3494' href='#n3494'>3494</a>
<a id='n3495' href='#n3495'>3495</a>
<a id='n3496' href='#n3496'>3496</a>
<a id='n3497' href='#n3497'>3497</a>
<a id='n3498' href='#n3498'>3498</a>
<a id='n3499' href='#n3499'>3499</a>
<a id='n3500' href='#n3500'>3500</a>
<a id='n3501' href='#n3501'>3501</a>
<a id='n3502' href='#n3502'>3502</a>
<a id='n3503' href='#n3503'>3503</a>
<a id='n3504' href='#n3504'>3504</a>
<a id='n3505' href='#n3505'>3505</a>
<a id='n3506' href='#n3506'>3506</a>
<a id='n3507' href='#n3507'>3507</a>
<a id='n3508' href='#n3508'>3508</a>
<a id='n3509' href='#n3509'>3509</a>
<a id='n3510' href='#n3510'>3510</a>
<a id='n3511' href='#n3511'>3511</a>
<a id='n3512' href='#n3512'>3512</a>
<a id='n3513' href='#n3513'>3513</a>
<a id='n3514' href='#n3514'>3514</a>
<a id='n3515' href='#n3515'>3515</a>
<a id='n3516' href='#n3516'>3516</a>
<a id='n3517' href='#n3517'>3517</a>
<a id='n3518' href='#n3518'>3518</a>
<a id='n3519' href='#n3519'>3519</a>
<a id='n3520' href='#n3520'>3520</a>
<a id='n3521' href='#n3521'>3521</a>
<a id='n3522' href='#n3522'>3522</a>
<a id='n3523' href='#n3523'>3523</a>
<a id='n3524' href='#n3524'>3524</a>
<a id='n3525' href='#n3525'>3525</a>
<a id='n3526' href='#n3526'>3526</a>
<a id='n3527' href='#n3527'>3527</a>
<a id='n3528' href='#n3528'>3528</a>
<a id='n3529' href='#n3529'>3529</a>
<a id='n3530' href='#n3530'>3530</a>
<a id='n3531' href='#n3531'>3531</a>
<a id='n3532' href='#n3532'>3532</a>
<a id='n3533' href='#n3533'>3533</a>
<a id='n3534' href='#n3534'>3534</a>
<a id='n3535' href='#n3535'>3535</a>
<a id='n3536' href='#n3536'>3536</a>
<a id='n3537' href='#n3537'>3537</a>
<a id='n3538' href='#n3538'>3538</a>
<a id='n3539' href='#n3539'>3539</a>
<a id='n3540' href='#n3540'>3540</a>
<a id='n3541' href='#n3541'>3541</a>
<a id='n3542' href='#n3542'>3542</a>
<a id='n3543' href='#n3543'>3543</a>
<a id='n3544' href='#n3544'>3544</a>
<a id='n3545' href='#n3545'>3545</a>
<a id='n3546' href='#n3546'>3546</a>
<a id='n3547' href='#n3547'>3547</a>
<a id='n3548' href='#n3548'>3548</a>
<a id='n3549' href='#n3549'>3549</a>
<a id='n3550' href='#n3550'>3550</a>
<a id='n3551' href='#n3551'>3551</a>
<a id='n3552' href='#n3552'>3552</a>
<a id='n3553' href='#n3553'>3553</a>
<a id='n3554' href='#n3554'>3554</a>
<a id='n3555' href='#n3555'>3555</a>
<a id='n3556' href='#n3556'>3556</a>
<a id='n3557' href='#n3557'>3557</a>
<a id='n3558' href='#n3558'>3558</a>
<a id='n3559' href='#n3559'>3559</a>
<a id='n3560' href='#n3560'>3560</a>
<a id='n3561' href='#n3561'>3561</a>
<a id='n3562' href='#n3562'>3562</a>
<a id='n3563' href='#n3563'>3563</a>
<a id='n3564' href='#n3564'>3564</a>
<a id='n3565' href='#n3565'>3565</a>
<a id='n3566' href='#n3566'>3566</a>
<a id='n3567' href='#n3567'>3567</a>
<a id='n3568' href='#n3568'>3568</a>
<a id='n3569' href='#n3569'>3569</a>
<a id='n3570' href='#n3570'>3570</a>
<a id='n3571' href='#n3571'>3571</a>
<a id='n3572' href='#n3572'>3572</a>
<a id='n3573' href='#n3573'>3573</a>
<a id='n3574' href='#n3574'>3574</a>
<a id='n3575' href='#n3575'>3575</a>
<a id='n3576' href='#n3576'>3576</a>
<a id='n3577' href='#n3577'>3577</a>
<a id='n3578' href='#n3578'>3578</a>
<a id='n3579' href='#n3579'>3579</a>
<a id='n3580' href='#n3580'>3580</a>
<a id='n3581' href='#n3581'>3581</a>
<a id='n3582' href='#n3582'>3582</a>
<a id='n3583' href='#n3583'>3583</a>
<a id='n3584' href='#n3584'>3584</a>
<a id='n3585' href='#n3585'>3585</a>
<a id='n3586' href='#n3586'>3586</a>
<a id='n3587' href='#n3587'>3587</a>
<a id='n3588' href='#n3588'>3588</a>
<a id='n3589' href='#n3589'>3589</a>
<a id='n3590' href='#n3590'>3590</a>
<a id='n3591' href='#n3591'>3591</a>
<a id='n3592' href='#n3592'>3592</a>
<a id='n3593' href='#n3593'>3593</a>
<a id='n3594' href='#n3594'>3594</a>
<a id='n3595' href='#n3595'>3595</a>
<a id='n3596' href='#n3596'>3596</a>
<a id='n3597' href='#n3597'>3597</a>
<a id='n3598' href='#n3598'>3598</a>
<a id='n3599' href='#n3599'>3599</a>
<a id='n3600' href='#n3600'>3600</a>
<a id='n3601' href='#n3601'>3601</a>
<a id='n3602' href='#n3602'>3602</a>
<a id='n3603' href='#n3603'>3603</a>
<a id='n3604' href='#n3604'>3604</a>
<a id='n3605' href='#n3605'>3605</a>
<a id='n3606' href='#n3606'>3606</a>
<a id='n3607' href='#n3607'>3607</a>
<a id='n3608' href='#n3608'>3608</a>
<a id='n3609' href='#n3609'>3609</a>
<a id='n3610' href='#n3610'>3610</a>
<a id='n3611' href='#n3611'>3611</a>
<a id='n3612' href='#n3612'>3612</a>
<a id='n3613' href='#n3613'>3613</a>
<a id='n3614' href='#n3614'>3614</a>
<a id='n3615' href='#n3615'>3615</a>
<a id='n3616' href='#n3616'>3616</a>
<a id='n3617' href='#n3617'>3617</a>
<a id='n3618' href='#n3618'>3618</a>
<a id='n3619' href='#n3619'>3619</a>
<a id='n3620' href='#n3620'>3620</a>
<a id='n3621' href='#n3621'>3621</a>
<a id='n3622' href='#n3622'>3622</a>
<a id='n3623' href='#n3623'>3623</a>
<a id='n3624' href='#n3624'>3624</a>
<a id='n3625' href='#n3625'>3625</a>
<a id='n3626' href='#n3626'>3626</a>
<a id='n3627' href='#n3627'>3627</a>
<a id='n3628' href='#n3628'>3628</a>
<a id='n3629' href='#n3629'>3629</a>
<a id='n3630' href='#n3630'>3630</a>
<a id='n3631' href='#n3631'>3631</a>
<a id='n3632' href='#n3632'>3632</a>
<a id='n3633' href='#n3633'>3633</a>
<a id='n3634' href='#n3634'>3634</a>
<a id='n3635' href='#n3635'>3635</a>
<a id='n3636' href='#n3636'>3636</a>
<a id='n3637' href='#n3637'>3637</a>
<a id='n3638' href='#n3638'>3638</a>
<a id='n3639' href='#n3639'>3639</a>
<a id='n3640' href='#n3640'>3640</a>
<a id='n3641' href='#n3641'>3641</a>
<a id='n3642' href='#n3642'>3642</a>
<a id='n3643' href='#n3643'>3643</a>
<a id='n3644' href='#n3644'>3644</a>
<a id='n3645' href='#n3645'>3645</a>
<a id='n3646' href='#n3646'>3646</a>
<a id='n3647' href='#n3647'>3647</a>
<a id='n3648' href='#n3648'>3648</a>
<a id='n3649' href='#n3649'>3649</a>
<a id='n3650' href='#n3650'>3650</a>
<a id='n3651' href='#n3651'>3651</a>
<a id='n3652' href='#n3652'>3652</a>
<a id='n3653' href='#n3653'>3653</a>
<a id='n3654' href='#n3654'>3654</a>
<a id='n3655' href='#n3655'>3655</a>
<a id='n3656' href='#n3656'>3656</a>
<a id='n3657' href='#n3657'>3657</a>
<a id='n3658' href='#n3658'>3658</a>
<a id='n3659' href='#n3659'>3659</a>
<a id='n3660' href='#n3660'>3660</a>
<a id='n3661' href='#n3661'>3661</a>
<a id='n3662' href='#n3662'>3662</a>
<a id='n3663' href='#n3663'>3663</a>
<a id='n3664' href='#n3664'>3664</a>
<a id='n3665' href='#n3665'>3665</a>
<a id='n3666' href='#n3666'>3666</a>
<a id='n3667' href='#n3667'>3667</a>
<a id='n3668' href='#n3668'>3668</a>
<a id='n3669' href='#n3669'>3669</a>
<a id='n3670' href='#n3670'>3670</a>
<a id='n3671' href='#n3671'>3671</a>
<a id='n3672' href='#n3672'>3672</a>
<a id='n3673' href='#n3673'>3673</a>
<a id='n3674' href='#n3674'>3674</a>
<a id='n3675' href='#n3675'>3675</a>
<a id='n3676' href='#n3676'>3676</a>
<a id='n3677' href='#n3677'>3677</a>
<a id='n3678' href='#n3678'>3678</a>
<a id='n3679' href='#n3679'>3679</a>
<a id='n3680' href='#n3680'>3680</a>
<a id='n3681' href='#n3681'>3681</a>
<a id='n3682' href='#n3682'>3682</a>
<a id='n3683' href='#n3683'>3683</a>
<a id='n3684' href='#n3684'>3684</a>
<a id='n3685' href='#n3685'>3685</a>
<a id='n3686' href='#n3686'>3686</a>
<a id='n3687' href='#n3687'>3687</a>
<a id='n3688' href='#n3688'>3688</a>
<a id='n3689' href='#n3689'>3689</a>
<a id='n3690' href='#n3690'>3690</a>
<a id='n3691' href='#n3691'>3691</a>
<a id='n3692' href='#n3692'>3692</a>
<a id='n3693' href='#n3693'>3693</a>
<a id='n3694' href='#n3694'>3694</a>
<a id='n3695' href='#n3695'>3695</a>
<a id='n3696' href='#n3696'>3696</a>
<a id='n3697' href='#n3697'>3697</a>
<a id='n3698' href='#n3698'>3698</a>
<a id='n3699' href='#n3699'>3699</a>
<a id='n3700' href='#n3700'>3700</a>
<a id='n3701' href='#n3701'>3701</a>
<a id='n3702' href='#n3702'>3702</a>
<a id='n3703' href='#n3703'>3703</a>
<a id='n3704' href='#n3704'>3704</a>
<a id='n3705' href='#n3705'>3705</a>
<a id='n3706' href='#n3706'>3706</a>
<a id='n3707' href='#n3707'>3707</a>
<a id='n3708' href='#n3708'>3708</a>
<a id='n3709' href='#n3709'>3709</a>
<a id='n3710' href='#n3710'>3710</a>
<a id='n3711' href='#n3711'>3711</a>
<a id='n3712' href='#n3712'>3712</a>
<a id='n3713' href='#n3713'>3713</a>
<a id='n3714' href='#n3714'>3714</a>
<a id='n3715' href='#n3715'>3715</a>
<a id='n3716' href='#n3716'>3716</a>
<a id='n3717' href='#n3717'>3717</a>
<a id='n3718' href='#n3718'>3718</a>
<a id='n3719' href='#n3719'>3719</a>
<a id='n3720' href='#n3720'>3720</a>
<a id='n3721' href='#n3721'>3721</a>
<a id='n3722' href='#n3722'>3722</a>
<a id='n3723' href='#n3723'>3723</a>
<a id='n3724' href='#n3724'>3724</a>
<a id='n3725' href='#n3725'>3725</a>
<a id='n3726' href='#n3726'>3726</a>
<a id='n3727' href='#n3727'>3727</a>
<a id='n3728' href='#n3728'>3728</a>
<a id='n3729' href='#n3729'>3729</a>
<a id='n3730' href='#n3730'>3730</a>
<a id='n3731' href='#n3731'>3731</a>
<a id='n3732' href='#n3732'>3732</a>
<a id='n3733' href='#n3733'>3733</a>
<a id='n3734' href='#n3734'>3734</a>
<a id='n3735' href='#n3735'>3735</a>
<a id='n3736' href='#n3736'>3736</a>
<a id='n3737' href='#n3737'>3737</a>
<a id='n3738' href='#n3738'>3738</a>
<a id='n3739' href='#n3739'>3739</a>
<a id='n3740' href='#n3740'>3740</a>
<a id='n3741' href='#n3741'>3741</a>
<a id='n3742' href='#n3742'>3742</a>
<a id='n3743' href='#n3743'>3743</a>
<a id='n3744' href='#n3744'>3744</a>
<a id='n3745' href='#n3745'>3745</a>
<a id='n3746' href='#n3746'>3746</a>
<a id='n3747' href='#n3747'>3747</a>
<a id='n3748' href='#n3748'>3748</a>
<a id='n3749' href='#n3749'>3749</a>
<a id='n3750' href='#n3750'>3750</a>
<a id='n3751' href='#n3751'>3751</a>
<a id='n3752' href='#n3752'>3752</a>
<a id='n3753' href='#n3753'>3753</a>
<a id='n3754' href='#n3754'>3754</a>
<a id='n3755' href='#n3755'>3755</a>
<a id='n3756' href='#n3756'>3756</a>
<a id='n3757' href='#n3757'>3757</a>
<a id='n3758' href='#n3758'>3758</a>
<a id='n3759' href='#n3759'>3759</a>
<a id='n3760' href='#n3760'>3760</a>
<a id='n3761' href='#n3761'>3761</a>
<a id='n3762' href='#n3762'>3762</a>
<a id='n3763' href='#n3763'>3763</a>
<a id='n3764' href='#n3764'>3764</a>
<a id='n3765' href='#n3765'>3765</a>
<a id='n3766' href='#n3766'>3766</a>
<a id='n3767' href='#n3767'>3767</a>
<a id='n3768' href='#n3768'>3768</a>
<a id='n3769' href='#n3769'>3769</a>
<a id='n3770' href='#n3770'>3770</a>
<a id='n3771' href='#n3771'>3771</a>
<a id='n3772' href='#n3772'>3772</a>
<a id='n3773' href='#n3773'>3773</a>
<a id='n3774' href='#n3774'>3774</a>
<a id='n3775' href='#n3775'>3775</a>
<a id='n3776' href='#n3776'>3776</a>
<a id='n3777' href='#n3777'>3777</a>
<a id='n3778' href='#n3778'>3778</a>
<a id='n3779' href='#n3779'>3779</a>
<a id='n3780' href='#n3780'>3780</a>
<a id='n3781' href='#n3781'>3781</a>
<a id='n3782' href='#n3782'>3782</a>
<a id='n3783' href='#n3783'>3783</a>
<a id='n3784' href='#n3784'>3784</a>
<a id='n3785' href='#n3785'>3785</a>
<a id='n3786' href='#n3786'>3786</a>
<a id='n3787' href='#n3787'>3787</a>
<a id='n3788' href='#n3788'>3788</a>
<a id='n3789' href='#n3789'>3789</a>
<a id='n3790' href='#n3790'>3790</a>
<a id='n3791' href='#n3791'>3791</a>
<a id='n3792' href='#n3792'>3792</a>
<a id='n3793' href='#n3793'>3793</a>
<a id='n3794' href='#n3794'>3794</a>
<a id='n3795' href='#n3795'>3795</a>
<a id='n3796' href='#n3796'>3796</a>
<a id='n3797' href='#n3797'>3797</a>
<a id='n3798' href='#n3798'>3798</a>
<a id='n3799' href='#n3799'>3799</a>
<a id='n3800' href='#n3800'>3800</a>
<a id='n3801' href='#n3801'>3801</a>
<a id='n3802' href='#n3802'>3802</a>
<a id='n3803' href='#n3803'>3803</a>
<a id='n3804' href='#n3804'>3804</a>
<a id='n3805' href='#n3805'>3805</a>
<a id='n3806' href='#n3806'>3806</a>
<a id='n3807' href='#n3807'>3807</a>
<a id='n3808' href='#n3808'>3808</a>
<a id='n3809' href='#n3809'>3809</a>
<a id='n3810' href='#n3810'>3810</a>
<a id='n3811' href='#n3811'>3811</a>
<a id='n3812' href='#n3812'>3812</a>
<a id='n3813' href='#n3813'>3813</a>
<a id='n3814' href='#n3814'>3814</a>
<a id='n3815' href='#n3815'>3815</a>
<a id='n3816' href='#n3816'>3816</a>
<a id='n3817' href='#n3817'>3817</a>
<a id='n3818' href='#n3818'>3818</a>
<a id='n3819' href='#n3819'>3819</a>
<a id='n3820' href='#n3820'>3820</a>
<a id='n3821' href='#n3821'>3821</a>
<a id='n3822' href='#n3822'>3822</a>
<a id='n3823' href='#n3823'>3823</a>
<a id='n3824' href='#n3824'>3824</a>
<a id='n3825' href='#n3825'>3825</a>
<a id='n3826' href='#n3826'>3826</a>
<a id='n3827' href='#n3827'>3827</a>
<a id='n3828' href='#n3828'>3828</a>
<a id='n3829' href='#n3829'>3829</a>
<a id='n3830' href='#n3830'>3830</a>
<a id='n3831' href='#n3831'>3831</a>
<a id='n3832' href='#n3832'>3832</a>
<a id='n3833' href='#n3833'>3833</a>
<a id='n3834' href='#n3834'>3834</a>
<a id='n3835' href='#n3835'>3835</a>
<a id='n3836' href='#n3836'>3836</a>
<a id='n3837' href='#n3837'>3837</a>
<a id='n3838' href='#n3838'>3838</a>
<a id='n3839' href='#n3839'>3839</a>
<a id='n3840' href='#n3840'>3840</a>
<a id='n3841' href='#n3841'>3841</a>
<a id='n3842' href='#n3842'>3842</a>
<a id='n3843' href='#n3843'>3843</a>
<a id='n3844' href='#n3844'>3844</a>
<a id='n3845' href='#n3845'>3845</a>
<a id='n3846' href='#n3846'>3846</a>
<a id='n3847' href='#n3847'>3847</a>
<a id='n3848' href='#n3848'>3848</a>
<a id='n3849' href='#n3849'>3849</a>
<a id='n3850' href='#n3850'>3850</a>
<a id='n3851' href='#n3851'>3851</a>
<a id='n3852' href='#n3852'>3852</a>
<a id='n3853' href='#n3853'>3853</a>
<a id='n3854' href='#n3854'>3854</a>
<a id='n3855' href='#n3855'>3855</a>
<a id='n3856' href='#n3856'>3856</a>
<a id='n3857' href='#n3857'>3857</a>
<a id='n3858' href='#n3858'>3858</a>
<a id='n3859' href='#n3859'>3859</a>
<a id='n3860' href='#n3860'>3860</a>
<a id='n3861' href='#n3861'>3861</a>
<a id='n3862' href='#n3862'>3862</a>
<a id='n3863' href='#n3863'>3863</a>
<a id='n3864' href='#n3864'>3864</a>
<a id='n3865' href='#n3865'>3865</a>
<a id='n3866' href='#n3866'>3866</a>
<a id='n3867' href='#n3867'>3867</a>
<a id='n3868' href='#n3868'>3868</a>
<a id='n3869' href='#n3869'>3869</a>
<a id='n3870' href='#n3870'>3870</a>
<a id='n3871' href='#n3871'>3871</a>
<a id='n3872' href='#n3872'>3872</a>
<a id='n3873' href='#n3873'>3873</a>
<a id='n3874' href='#n3874'>3874</a>
<a id='n3875' href='#n3875'>3875</a>
<a id='n3876' href='#n3876'>3876</a>
<a id='n3877' href='#n3877'>3877</a>
<a id='n3878' href='#n3878'>3878</a>
<a id='n3879' href='#n3879'>3879</a>
<a id='n3880' href='#n3880'>3880</a>
<a id='n3881' href='#n3881'>3881</a>
<a id='n3882' href='#n3882'>3882</a>
<a id='n3883' href='#n3883'>3883</a>
<a id='n3884' href='#n3884'>3884</a>
<a id='n3885' href='#n3885'>3885</a>
<a id='n3886' href='#n3886'>3886</a>
<a id='n3887' href='#n3887'>3887</a>
<a id='n3888' href='#n3888'>3888</a>
<a id='n3889' href='#n3889'>3889</a>
<a id='n3890' href='#n3890'>3890</a>
<a id='n3891' href='#n3891'>3891</a>
<a id='n3892' href='#n3892'>3892</a>
<a id='n3893' href='#n3893'>3893</a>
<a id='n3894' href='#n3894'>3894</a>
<a id='n3895' href='#n3895'>3895</a>
<a id='n3896' href='#n3896'>3896</a>
<a id='n3897' href='#n3897'>3897</a>
<a id='n3898' href='#n3898'>3898</a>
<a id='n3899' href='#n3899'>3899</a>
<a id='n3900' href='#n3900'>3900</a>
<a id='n3901' href='#n3901'>3901</a>
<a id='n3902' href='#n3902'>3902</a>
<a id='n3903' href='#n3903'>3903</a>
<a id='n3904' href='#n3904'>3904</a>
<a id='n3905' href='#n3905'>3905</a>
<a id='n3906' href='#n3906'>3906</a>
<a id='n3907' href='#n3907'>3907</a>
<a id='n3908' href='#n3908'>3908</a>
<a id='n3909' href='#n3909'>3909</a>
<a id='n3910' href='#n3910'>3910</a>
<a id='n3911' href='#n3911'>3911</a>
<a id='n3912' href='#n3912'>3912</a>
<a id='n3913' href='#n3913'>3913</a>
<a id='n3914' href='#n3914'>3914</a>
<a id='n3915' href='#n3915'>3915</a>
<a id='n3916' href='#n3916'>3916</a>
<a id='n3917' href='#n3917'>3917</a>
<a id='n3918' href='#n3918'>3918</a>
<a id='n3919' href='#n3919'>3919</a>
<a id='n3920' href='#n3920'>3920</a>
<a id='n3921' href='#n3921'>3921</a>
<a id='n3922' href='#n3922'>3922</a>
<a id='n3923' href='#n3923'>3923</a>
<a id='n3924' href='#n3924'>3924</a>
<a id='n3925' href='#n3925'>3925</a>
<a id='n3926' href='#n3926'>3926</a>
<a id='n3927' href='#n3927'>3927</a>
<a id='n3928' href='#n3928'>3928</a>
<a id='n3929' href='#n3929'>3929</a>
<a id='n3930' href='#n3930'>3930</a>
<a id='n3931' href='#n3931'>3931</a>
<a id='n3932' href='#n3932'>3932</a>
<a id='n3933' href='#n3933'>3933</a>
<a id='n3934' href='#n3934'>3934</a>
<a id='n3935' href='#n3935'>3935</a>
<a id='n3936' href='#n3936'>3936</a>
<a id='n3937' href='#n3937'>3937</a>
<a id='n3938' href='#n3938'>3938</a>
<a id='n3939' href='#n3939'>3939</a>
<a id='n3940' href='#n3940'>3940</a>
<a id='n3941' href='#n3941'>3941</a>
<a id='n3942' href='#n3942'>3942</a>
<a id='n3943' href='#n3943'>3943</a>
<a id='n3944' href='#n3944'>3944</a>
<a id='n3945' href='#n3945'>3945</a>
<a id='n3946' href='#n3946'>3946</a>
<a id='n3947' href='#n3947'>3947</a>
<a id='n3948' href='#n3948'>3948</a>
<a id='n3949' href='#n3949'>3949</a>
<a id='n3950' href='#n3950'>3950</a>
<a id='n3951' href='#n3951'>3951</a>
<a id='n3952' href='#n3952'>3952</a>
<a id='n3953' href='#n3953'>3953</a>
<a id='n3954' href='#n3954'>3954</a>
<a id='n3955' href='#n3955'>3955</a>
<a id='n3956' href='#n3956'>3956</a>
<a id='n3957' href='#n3957'>3957</a>
<a id='n3958' href='#n3958'>3958</a>
<a id='n3959' href='#n3959'>3959</a>
<a id='n3960' href='#n3960'>3960</a>
<a id='n3961' href='#n3961'>3961</a>
<a id='n3962' href='#n3962'>3962</a>
<a id='n3963' href='#n3963'>3963</a>
<a id='n3964' href='#n3964'>3964</a>
<a id='n3965' href='#n3965'>3965</a>
<a id='n3966' href='#n3966'>3966</a>
<a id='n3967' href='#n3967'>3967</a>
<a id='n3968' href='#n3968'>3968</a>
<a id='n3969' href='#n3969'>3969</a>
<a id='n3970' href='#n3970'>3970</a>
<a id='n3971' href='#n3971'>3971</a>
<a id='n3972' href='#n3972'>3972</a>
<a id='n3973' href='#n3973'>3973</a>
<a id='n3974' href='#n3974'>3974</a>
<a id='n3975' href='#n3975'>3975</a>
<a id='n3976' href='#n3976'>3976</a>
<a id='n3977' href='#n3977'>3977</a>
<a id='n3978' href='#n3978'>3978</a>
<a id='n3979' href='#n3979'>3979</a>
<a id='n3980' href='#n3980'>3980</a>
<a id='n3981' href='#n3981'>3981</a>
<a id='n3982' href='#n3982'>3982</a>
<a id='n3983' href='#n3983'>3983</a>
<a id='n3984' href='#n3984'>3984</a>
<a id='n3985' href='#n3985'>3985</a>
<a id='n3986' href='#n3986'>3986</a>
<a id='n3987' href='#n3987'>3987</a>
<a id='n3988' href='#n3988'>3988</a>
<a id='n3989' href='#n3989'>3989</a>
<a id='n3990' href='#n3990'>3990</a>
<a id='n3991' href='#n3991'>3991</a>
<a id='n3992' href='#n3992'>3992</a>
<a id='n3993' href='#n3993'>3993</a>
<a id='n3994' href='#n3994'>3994</a>
<a id='n3995' href='#n3995'>3995</a>
<a id='n3996' href='#n3996'>3996</a>
<a id='n3997' href='#n3997'>3997</a>
<a id='n3998' href='#n3998'>3998</a>
<a id='n3999' href='#n3999'>3999</a>
<a id='n4000' href='#n4000'>4000</a>
<a id='n4001' href='#n4001'>4001</a>
<a id='n4002' href='#n4002'>4002</a>
<a id='n4003' href='#n4003'>4003</a>
<a id='n4004' href='#n4004'>4004</a>
<a id='n4005' href='#n4005'>4005</a>
<a id='n4006' href='#n4006'>4006</a>
<a id='n4007' href='#n4007'>4007</a>
<a id='n4008' href='#n4008'>4008</a>
<a id='n4009' href='#n4009'>4009</a>
<a id='n4010' href='#n4010'>4010</a>
<a id='n4011' href='#n4011'>4011</a>
<a id='n4012' href='#n4012'>4012</a>
<a id='n4013' href='#n4013'>4013</a>
<a id='n4014' href='#n4014'>4014</a>
<a id='n4015' href='#n4015'>4015</a>
<a id='n4016' href='#n4016'>4016</a>
<a id='n4017' href='#n4017'>4017</a>
<a id='n4018' href='#n4018'>4018</a>
<a id='n4019' href='#n4019'>4019</a>
<a id='n4020' href='#n4020'>4020</a>
<a id='n4021' href='#n4021'>4021</a>
<a id='n4022' href='#n4022'>4022</a>
<a id='n4023' href='#n4023'>4023</a>
<a id='n4024' href='#n4024'>4024</a>
<a id='n4025' href='#n4025'>4025</a>
<a id='n4026' href='#n4026'>4026</a>
<a id='n4027' href='#n4027'>4027</a>
<a id='n4028' href='#n4028'>4028</a>
<a id='n4029' href='#n4029'>4029</a>
<a id='n4030' href='#n4030'>4030</a>
<a id='n4031' href='#n4031'>4031</a>
<a id='n4032' href='#n4032'>4032</a>
<a id='n4033' href='#n4033'>4033</a>
<a id='n4034' href='#n4034'>4034</a>
<a id='n4035' href='#n4035'>4035</a>
<a id='n4036' href='#n4036'>4036</a>
<a id='n4037' href='#n4037'>4037</a>
<a id='n4038' href='#n4038'>4038</a>
<a id='n4039' href='#n4039'>4039</a>
<a id='n4040' href='#n4040'>4040</a>
<a id='n4041' href='#n4041'>4041</a>
<a id='n4042' href='#n4042'>4042</a>
<a id='n4043' href='#n4043'>4043</a>
<a id='n4044' href='#n4044'>4044</a>
<a id='n4045' href='#n4045'>4045</a>
<a id='n4046' href='#n4046'>4046</a>
<a id='n4047' href='#n4047'>4047</a>
<a id='n4048' href='#n4048'>4048</a>
<a id='n4049' href='#n4049'>4049</a>
<a id='n4050' href='#n4050'>4050</a>
<a id='n4051' href='#n4051'>4051</a>
<a id='n4052' href='#n4052'>4052</a>
<a id='n4053' href='#n4053'>4053</a>
<a id='n4054' href='#n4054'>4054</a>
<a id='n4055' href='#n4055'>4055</a>
<a id='n4056' href='#n4056'>4056</a>
<a id='n4057' href='#n4057'>4057</a>
<a id='n4058' href='#n4058'>4058</a>
<a id='n4059' href='#n4059'>4059</a>
<a id='n4060' href='#n4060'>4060</a>
<a id='n4061' href='#n4061'>4061</a>
<a id='n4062' href='#n4062'>4062</a>
<a id='n4063' href='#n4063'>4063</a>
<a id='n4064' href='#n4064'>4064</a>
<a id='n4065' href='#n4065'>4065</a>
<a id='n4066' href='#n4066'>4066</a>
<a id='n4067' href='#n4067'>4067</a>
<a id='n4068' href='#n4068'>4068</a>
<a id='n4069' href='#n4069'>4069</a>
<a id='n4070' href='#n4070'>4070</a>
<a id='n4071' href='#n4071'>4071</a>
<a id='n4072' href='#n4072'>4072</a>
<a id='n4073' href='#n4073'>4073</a>
<a id='n4074' href='#n4074'>4074</a>
<a id='n4075' href='#n4075'>4075</a>
<a id='n4076' href='#n4076'>4076</a>
<a id='n4077' href='#n4077'>4077</a>
<a id='n4078' href='#n4078'>4078</a>
<a id='n4079' href='#n4079'>4079</a>
<a id='n4080' href='#n4080'>4080</a>
<a id='n4081' href='#n4081'>4081</a>
<a id='n4082' href='#n4082'>4082</a>
<a id='n4083' href='#n4083'>4083</a>
<a id='n4084' href='#n4084'>4084</a>
<a id='n4085' href='#n4085'>4085</a>
<a id='n4086' href='#n4086'>4086</a>
<a id='n4087' href='#n4087'>4087</a>
<a id='n4088' href='#n4088'>4088</a>
<a id='n4089' href='#n4089'>4089</a>
<a id='n4090' href='#n4090'>4090</a>
<a id='n4091' href='#n4091'>4091</a>
<a id='n4092' href='#n4092'>4092</a>
<a id='n4093' href='#n4093'>4093</a>
<a id='n4094' href='#n4094'>4094</a>
<a id='n4095' href='#n4095'>4095</a>
<a id='n4096' href='#n4096'>4096</a>
<a id='n4097' href='#n4097'>4097</a>
<a id='n4098' href='#n4098'>4098</a>
<a id='n4099' href='#n4099'>4099</a>
<a id='n4100' href='#n4100'>4100</a>
<a id='n4101' href='#n4101'>4101</a>
<a id='n4102' href='#n4102'>4102</a>
<a id='n4103' href='#n4103'>4103</a>
<a id='n4104' href='#n4104'>4104</a>
<a id='n4105' href='#n4105'>4105</a>
<a id='n4106' href='#n4106'>4106</a>
<a id='n4107' href='#n4107'>4107</a>
<a id='n4108' href='#n4108'>4108</a>
<a id='n4109' href='#n4109'>4109</a>
<a id='n4110' href='#n4110'>4110</a>
<a id='n4111' href='#n4111'>4111</a>
<a id='n4112' href='#n4112'>4112</a>
<a id='n4113' href='#n4113'>4113</a>
<a id='n4114' href='#n4114'>4114</a>
<a id='n4115' href='#n4115'>4115</a>
<a id='n4116' href='#n4116'>4116</a>
<a id='n4117' href='#n4117'>4117</a>
<a id='n4118' href='#n4118'>4118</a>
<a id='n4119' href='#n4119'>4119</a>
<a id='n4120' href='#n4120'>4120</a>
<a id='n4121' href='#n4121'>4121</a>
<a id='n4122' href='#n4122'>4122</a>
<a id='n4123' href='#n4123'>4123</a>
<a id='n4124' href='#n4124'>4124</a>
<a id='n4125' href='#n4125'>4125</a>
<a id='n4126' href='#n4126'>4126</a>
<a id='n4127' href='#n4127'>4127</a>
<a id='n4128' href='#n4128'>4128</a>
<a id='n4129' href='#n4129'>4129</a>
<a id='n4130' href='#n4130'>4130</a>
<a id='n4131' href='#n4131'>4131</a>
<a id='n4132' href='#n4132'>4132</a>
<a id='n4133' href='#n4133'>4133</a>
<a id='n4134' href='#n4134'>4134</a>
<a id='n4135' href='#n4135'>4135</a>
<a id='n4136' href='#n4136'>4136</a>
<a id='n4137' href='#n4137'>4137</a>
<a id='n4138' href='#n4138'>4138</a>
<a id='n4139' href='#n4139'>4139</a>
<a id='n4140' href='#n4140'>4140</a>
<a id='n4141' href='#n4141'>4141</a>
<a id='n4142' href='#n4142'>4142</a>
<a id='n4143' href='#n4143'>4143</a>
<a id='n4144' href='#n4144'>4144</a>
<a id='n4145' href='#n4145'>4145</a>
<a id='n4146' href='#n4146'>4146</a>
<a id='n4147' href='#n4147'>4147</a>
<a id='n4148' href='#n4148'>4148</a>
<a id='n4149' href='#n4149'>4149</a>
<a id='n4150' href='#n4150'>4150</a>
<a id='n4151' href='#n4151'>4151</a>
<a id='n4152' href='#n4152'>4152</a>
<a id='n4153' href='#n4153'>4153</a>
<a id='n4154' href='#n4154'>4154</a>
<a id='n4155' href='#n4155'>4155</a>
<a id='n4156' href='#n4156'>4156</a>
<a id='n4157' href='#n4157'>4157</a>
<a id='n4158' href='#n4158'>4158</a>
<a id='n4159' href='#n4159'>4159</a>
<a id='n4160' href='#n4160'>4160</a>
<a id='n4161' href='#n4161'>4161</a>
<a id='n4162' href='#n4162'>4162</a>
<a id='n4163' href='#n4163'>4163</a>
<a id='n4164' href='#n4164'>4164</a>
<a id='n4165' href='#n4165'>4165</a>
<a id='n4166' href='#n4166'>4166</a>
<a id='n4167' href='#n4167'>4167</a>
<a id='n4168' href='#n4168'>4168</a>
<a id='n4169' href='#n4169'>4169</a>
<a id='n4170' href='#n4170'>4170</a>
<a id='n4171' href='#n4171'>4171</a>
<a id='n4172' href='#n4172'>4172</a>
<a id='n4173' href='#n4173'>4173</a>
<a id='n4174' href='#n4174'>4174</a>
<a id='n4175' href='#n4175'>4175</a>
<a id='n4176' href='#n4176'>4176</a>
<a id='n4177' href='#n4177'>4177</a>
<a id='n4178' href='#n4178'>4178</a>
<a id='n4179' href='#n4179'>4179</a>
<a id='n4180' href='#n4180'>4180</a>
<a id='n4181' href='#n4181'>4181</a>
<a id='n4182' href='#n4182'>4182</a>
<a id='n4183' href='#n4183'>4183</a>
<a id='n4184' href='#n4184'>4184</a>
<a id='n4185' href='#n4185'>4185</a>
<a id='n4186' href='#n4186'>4186</a>
<a id='n4187' href='#n4187'>4187</a>
<a id='n4188' href='#n4188'>4188</a>
<a id='n4189' href='#n4189'>4189</a>
<a id='n4190' href='#n4190'>4190</a>
<a id='n4191' href='#n4191'>4191</a>
<a id='n4192' href='#n4192'>4192</a>
<a id='n4193' href='#n4193'>4193</a>
<a id='n4194' href='#n4194'>4194</a>
<a id='n4195' href='#n4195'>4195</a>
<a id='n4196' href='#n4196'>4196</a>
<a id='n4197' href='#n4197'>4197</a>
<a id='n4198' href='#n4198'>4198</a>
<a id='n4199' href='#n4199'>4199</a>
<a id='n4200' href='#n4200'>4200</a>
<a id='n4201' href='#n4201'>4201</a>
<a id='n4202' href='#n4202'>4202</a>
<a id='n4203' href='#n4203'>4203</a>
<a id='n4204' href='#n4204'>4204</a>
<a id='n4205' href='#n4205'>4205</a>
<a id='n4206' href='#n4206'>4206</a>
<a id='n4207' href='#n4207'>4207</a>
<a id='n4208' href='#n4208'>4208</a>
<a id='n4209' href='#n4209'>4209</a>
<a id='n4210' href='#n4210'>4210</a>
<a id='n4211' href='#n4211'>4211</a>
<a id='n4212' href='#n4212'>4212</a>
<a id='n4213' href='#n4213'>4213</a>
<a id='n4214' href='#n4214'>4214</a>
<a id='n4215' href='#n4215'>4215</a>
<a id='n4216' href='#n4216'>4216</a>
<a id='n4217' href='#n4217'>4217</a>
<a id='n4218' href='#n4218'>4218</a>
<a id='n4219' href='#n4219'>4219</a>
<a id='n4220' href='#n4220'>4220</a>
<a id='n4221' href='#n4221'>4221</a>
<a id='n4222' href='#n4222'>4222</a>
<a id='n4223' href='#n4223'>4223</a>
<a id='n4224' href='#n4224'>4224</a>
<a id='n4225' href='#n4225'>4225</a>
<a id='n4226' href='#n4226'>4226</a>
<a id='n4227' href='#n4227'>4227</a>
<a id='n4228' href='#n4228'>4228</a>
<a id='n4229' href='#n4229'>4229</a>
<a id='n4230' href='#n4230'>4230</a>
<a id='n4231' href='#n4231'>4231</a>
<a id='n4232' href='#n4232'>4232</a>
<a id='n4233' href='#n4233'>4233</a>
<a id='n4234' href='#n4234'>4234</a>
<a id='n4235' href='#n4235'>4235</a>
<a id='n4236' href='#n4236'>4236</a>
<a id='n4237' href='#n4237'>4237</a>
<a id='n4238' href='#n4238'>4238</a>
<a id='n4239' href='#n4239'>4239</a>
<a id='n4240' href='#n4240'>4240</a>
<a id='n4241' href='#n4241'>4241</a>
<a id='n4242' href='#n4242'>4242</a>
<a id='n4243' href='#n4243'>4243</a>
<a id='n4244' href='#n4244'>4244</a>
<a id='n4245' href='#n4245'>4245</a>
<a id='n4246' href='#n4246'>4246</a>
<a id='n4247' href='#n4247'>4247</a>
<a id='n4248' href='#n4248'>4248</a>
<a id='n4249' href='#n4249'>4249</a>
<a id='n4250' href='#n4250'>4250</a>
<a id='n4251' href='#n4251'>4251</a>
<a id='n4252' href='#n4252'>4252</a>
<a id='n4253' href='#n4253'>4253</a>
<a id='n4254' href='#n4254'>4254</a>
<a id='n4255' href='#n4255'>4255</a>
<a id='n4256' href='#n4256'>4256</a>
<a id='n4257' href='#n4257'>4257</a>
<a id='n4258' href='#n4258'>4258</a>
<a id='n4259' href='#n4259'>4259</a>
<a id='n4260' href='#n4260'>4260</a>
<a id='n4261' href='#n4261'>4261</a>
<a id='n4262' href='#n4262'>4262</a>
<a id='n4263' href='#n4263'>4263</a>
<a id='n4264' href='#n4264'>4264</a>
<a id='n4265' href='#n4265'>4265</a>
<a id='n4266' href='#n4266'>4266</a>
<a id='n4267' href='#n4267'>4267</a>
<a id='n4268' href='#n4268'>4268</a>
<a id='n4269' href='#n4269'>4269</a>
<a id='n4270' href='#n4270'>4270</a>
<a id='n4271' href='#n4271'>4271</a>
<a id='n4272' href='#n4272'>4272</a>
<a id='n4273' href='#n4273'>4273</a>
<a id='n4274' href='#n4274'>4274</a>
<a id='n4275' href='#n4275'>4275</a>
<a id='n4276' href='#n4276'>4276</a>
<a id='n4277' href='#n4277'>4277</a>
<a id='n4278' href='#n4278'>4278</a>
<a id='n4279' href='#n4279'>4279</a>
<a id='n4280' href='#n4280'>4280</a>
<a id='n4281' href='#n4281'>4281</a>
<a id='n4282' href='#n4282'>4282</a>
<a id='n4283' href='#n4283'>4283</a>
<a id='n4284' href='#n4284'>4284</a>
<a id='n4285' href='#n4285'>4285</a>
<a id='n4286' href='#n4286'>4286</a>
<a id='n4287' href='#n4287'>4287</a>
<a id='n4288' href='#n4288'>4288</a>
<a id='n4289' href='#n4289'>4289</a>
<a id='n4290' href='#n4290'>4290</a>
<a id='n4291' href='#n4291'>4291</a>
<a id='n4292' href='#n4292'>4292</a>
<a id='n4293' href='#n4293'>4293</a>
<a id='n4294' href='#n4294'>4294</a>
<a id='n4295' href='#n4295'>4295</a>
<a id='n4296' href='#n4296'>4296</a>
<a id='n4297' href='#n4297'>4297</a>
<a id='n4298' href='#n4298'>4298</a>
<a id='n4299' href='#n4299'>4299</a>
<a id='n4300' href='#n4300'>4300</a>
<a id='n4301' href='#n4301'>4301</a>
<a id='n4302' href='#n4302'>4302</a>
<a id='n4303' href='#n4303'>4303</a>
<a id='n4304' href='#n4304'>4304</a>
<a id='n4305' href='#n4305'>4305</a>
<a id='n4306' href='#n4306'>4306</a>
<a id='n4307' href='#n4307'>4307</a>
<a id='n4308' href='#n4308'>4308</a>
<a id='n4309' href='#n4309'>4309</a>
<a id='n4310' href='#n4310'>4310</a>
<a id='n4311' href='#n4311'>4311</a>
<a id='n4312' href='#n4312'>4312</a>
<a id='n4313' href='#n4313'>4313</a>
<a id='n4314' href='#n4314'>4314</a>
<a id='n4315' href='#n4315'>4315</a>
<a id='n4316' href='#n4316'>4316</a>
<a id='n4317' href='#n4317'>4317</a>
<a id='n4318' href='#n4318'>4318</a>
<a id='n4319' href='#n4319'>4319</a>
<a id='n4320' href='#n4320'>4320</a>
<a id='n4321' href='#n4321'>4321</a>
<a id='n4322' href='#n4322'>4322</a>
<a id='n4323' href='#n4323'>4323</a>
<a id='n4324' href='#n4324'>4324</a>
<a id='n4325' href='#n4325'>4325</a>
<a id='n4326' href='#n4326'>4326</a>
<a id='n4327' href='#n4327'>4327</a>
<a id='n4328' href='#n4328'>4328</a>
<a id='n4329' href='#n4329'>4329</a>
<a id='n4330' href='#n4330'>4330</a>
<a id='n4331' href='#n4331'>4331</a>
<a id='n4332' href='#n4332'>4332</a>
<a id='n4333' href='#n4333'>4333</a>
<a id='n4334' href='#n4334'>4334</a>
<a id='n4335' href='#n4335'>4335</a>
<a id='n4336' href='#n4336'>4336</a>
<a id='n4337' href='#n4337'>4337</a>
<a id='n4338' href='#n4338'>4338</a>
<a id='n4339' href='#n4339'>4339</a>
<a id='n4340' href='#n4340'>4340</a>
<a id='n4341' href='#n4341'>4341</a>
<a id='n4342' href='#n4342'>4342</a>
<a id='n4343' href='#n4343'>4343</a>
<a id='n4344' href='#n4344'>4344</a>
<a id='n4345' href='#n4345'>4345</a>
<a id='n4346' href='#n4346'>4346</a>
<a id='n4347' href='#n4347'>4347</a>
<a id='n4348' href='#n4348'>4348</a>
<a id='n4349' href='#n4349'>4349</a>
<a id='n4350' href='#n4350'>4350</a>
<a id='n4351' href='#n4351'>4351</a>
<a id='n4352' href='#n4352'>4352</a>
<a id='n4353' href='#n4353'>4353</a>
<a id='n4354' href='#n4354'>4354</a>
<a id='n4355' href='#n4355'>4355</a>
<a id='n4356' href='#n4356'>4356</a>
<a id='n4357' href='#n4357'>4357</a>
<a id='n4358' href='#n4358'>4358</a>
<a id='n4359' href='#n4359'>4359</a>
<a id='n4360' href='#n4360'>4360</a>
<a id='n4361' href='#n4361'>4361</a>
<a id='n4362' href='#n4362'>4362</a>
<a id='n4363' href='#n4363'>4363</a>
<a id='n4364' href='#n4364'>4364</a>
<a id='n4365' href='#n4365'>4365</a>
<a id='n4366' href='#n4366'>4366</a>
<a id='n4367' href='#n4367'>4367</a>
<a id='n4368' href='#n4368'>4368</a>
<a id='n4369' href='#n4369'>4369</a>
<a id='n4370' href='#n4370'>4370</a>
<a id='n4371' href='#n4371'>4371</a>
<a id='n4372' href='#n4372'>4372</a>
<a id='n4373' href='#n4373'>4373</a>
<a id='n4374' href='#n4374'>4374</a>
<a id='n4375' href='#n4375'>4375</a>
<a id='n4376' href='#n4376'>4376</a>
<a id='n4377' href='#n4377'>4377</a>
<a id='n4378' href='#n4378'>4378</a>
<a id='n4379' href='#n4379'>4379</a>
<a id='n4380' href='#n4380'>4380</a>
<a id='n4381' href='#n4381'>4381</a>
<a id='n4382' href='#n4382'>4382</a>
<a id='n4383' href='#n4383'>4383</a>
<a id='n4384' href='#n4384'>4384</a>
<a id='n4385' href='#n4385'>4385</a>
<a id='n4386' href='#n4386'>4386</a>
<a id='n4387' href='#n4387'>4387</a>
<a id='n4388' href='#n4388'>4388</a>
<a id='n4389' href='#n4389'>4389</a>
<a id='n4390' href='#n4390'>4390</a>
<a id='n4391' href='#n4391'>4391</a>
<a id='n4392' href='#n4392'>4392</a>
<a id='n4393' href='#n4393'>4393</a>
<a id='n4394' href='#n4394'>4394</a>
<a id='n4395' href='#n4395'>4395</a>
<a id='n4396' href='#n4396'>4396</a>
<a id='n4397' href='#n4397'>4397</a>
<a id='n4398' href='#n4398'>4398</a>
<a id='n4399' href='#n4399'>4399</a>
<a id='n4400' href='#n4400'>4400</a>
<a id='n4401' href='#n4401'>4401</a>
<a id='n4402' href='#n4402'>4402</a>
<a id='n4403' href='#n4403'>4403</a>
<a id='n4404' href='#n4404'>4404</a>
<a id='n4405' href='#n4405'>4405</a>
<a id='n4406' href='#n4406'>4406</a>
<a id='n4407' href='#n4407'>4407</a>
<a id='n4408' href='#n4408'>4408</a>
<a id='n4409' href='#n4409'>4409</a>
<a id='n4410' href='#n4410'>4410</a>
<a id='n4411' href='#n4411'>4411</a>
<a id='n4412' href='#n4412'>4412</a>
<a id='n4413' href='#n4413'>4413</a>
<a id='n4414' href='#n4414'>4414</a>
<a id='n4415' href='#n4415'>4415</a>
<a id='n4416' href='#n4416'>4416</a>
<a id='n4417' href='#n4417'>4417</a>
<a id='n4418' href='#n4418'>4418</a>
<a id='n4419' href='#n4419'>4419</a>
<a id='n4420' href='#n4420'>4420</a>
<a id='n4421' href='#n4421'>4421</a>
<a id='n4422' href='#n4422'>4422</a>
<a id='n4423' href='#n4423'>4423</a>
<a id='n4424' href='#n4424'>4424</a>
<a id='n4425' href='#n4425'>4425</a>
<a id='n4426' href='#n4426'>4426</a>
<a id='n4427' href='#n4427'>4427</a>
<a id='n4428' href='#n4428'>4428</a>
<a id='n4429' href='#n4429'>4429</a>
<a id='n4430' href='#n4430'>4430</a>
<a id='n4431' href='#n4431'>4431</a>
<a id='n4432' href='#n4432'>4432</a>
<a id='n4433' href='#n4433'>4433</a>
<a id='n4434' href='#n4434'>4434</a>
<a id='n4435' href='#n4435'>4435</a>
<a id='n4436' href='#n4436'>4436</a>
<a id='n4437' href='#n4437'>4437</a>
<a id='n4438' href='#n4438'>4438</a>
<a id='n4439' href='#n4439'>4439</a>
<a id='n4440' href='#n4440'>4440</a>
<a id='n4441' href='#n4441'>4441</a>
<a id='n4442' href='#n4442'>4442</a>
<a id='n4443' href='#n4443'>4443</a>
<a id='n4444' href='#n4444'>4444</a>
<a id='n4445' href='#n4445'>4445</a>
<a id='n4446' href='#n4446'>4446</a>
<a id='n4447' href='#n4447'>4447</a>
<a id='n4448' href='#n4448'>4448</a>
<a id='n4449' href='#n4449'>4449</a>
<a id='n4450' href='#n4450'>4450</a>
<a id='n4451' href='#n4451'>4451</a>
<a id='n4452' href='#n4452'>4452</a>
<a id='n4453' href='#n4453'>4453</a>
<a id='n4454' href='#n4454'>4454</a>
<a id='n4455' href='#n4455'>4455</a>
<a id='n4456' href='#n4456'>4456</a>
<a id='n4457' href='#n4457'>4457</a>
<a id='n4458' href='#n4458'>4458</a>
<a id='n4459' href='#n4459'>4459</a>
<a id='n4460' href='#n4460'>4460</a>
<a id='n4461' href='#n4461'>4461</a>
<a id='n4462' href='#n4462'>4462</a>
<a id='n4463' href='#n4463'>4463</a>
<a id='n4464' href='#n4464'>4464</a>
<a id='n4465' href='#n4465'>4465</a>
<a id='n4466' href='#n4466'>4466</a>
<a id='n4467' href='#n4467'>4467</a>
<a id='n4468' href='#n4468'>4468</a>
<a id='n4469' href='#n4469'>4469</a>
<a id='n4470' href='#n4470'>4470</a>
<a id='n4471' href='#n4471'>4471</a>
<a id='n4472' href='#n4472'>4472</a>
<a id='n4473' href='#n4473'>4473</a>
<a id='n4474' href='#n4474'>4474</a>
<a id='n4475' href='#n4475'>4475</a>
<a id='n4476' href='#n4476'>4476</a>
<a id='n4477' href='#n4477'>4477</a>
<a id='n4478' href='#n4478'>4478</a>
<a id='n4479' href='#n4479'>4479</a>
<a id='n4480' href='#n4480'>4480</a>
<a id='n4481' href='#n4481'>4481</a>
<a id='n4482' href='#n4482'>4482</a>
<a id='n4483' href='#n4483'>4483</a>
<a id='n4484' href='#n4484'>4484</a>
<a id='n4485' href='#n4485'>4485</a>
<a id='n4486' href='#n4486'>4486</a>
<a id='n4487' href='#n4487'>4487</a>
<a id='n4488' href='#n4488'>4488</a>
<a id='n4489' href='#n4489'>4489</a>
<a id='n4490' href='#n4490'>4490</a>
<a id='n4491' href='#n4491'>4491</a>
<a id='n4492' href='#n4492'>4492</a>
<a id='n4493' href='#n4493'>4493</a>
<a id='n4494' href='#n4494'>4494</a>
<a id='n4495' href='#n4495'>4495</a>
<a id='n4496' href='#n4496'>4496</a>
<a id='n4497' href='#n4497'>4497</a>
<a id='n4498' href='#n4498'>4498</a>
<a id='n4499' href='#n4499'>4499</a>
<a id='n4500' href='#n4500'>4500</a>
<a id='n4501' href='#n4501'>4501</a>
<a id='n4502' href='#n4502'>4502</a>
<a id='n4503' href='#n4503'>4503</a>
<a id='n4504' href='#n4504'>4504</a>
<a id='n4505' href='#n4505'>4505</a>
<a id='n4506' href='#n4506'>4506</a>
<a id='n4507' href='#n4507'>4507</a>
<a id='n4508' href='#n4508'>4508</a>
<a id='n4509' href='#n4509'>4509</a>
<a id='n4510' href='#n4510'>4510</a>
<a id='n4511' href='#n4511'>4511</a>
<a id='n4512' href='#n4512'>4512</a>
<a id='n4513' href='#n4513'>4513</a>
<a id='n4514' href='#n4514'>4514</a>
<a id='n4515' href='#n4515'>4515</a>
<a id='n4516' href='#n4516'>4516</a>
<a id='n4517' href='#n4517'>4517</a>
<a id='n4518' href='#n4518'>4518</a>
<a id='n4519' href='#n4519'>4519</a>
<a id='n4520' href='#n4520'>4520</a>
<a id='n4521' href='#n4521'>4521</a>
<a id='n4522' href='#n4522'>4522</a>
<a id='n4523' href='#n4523'>4523</a>
<a id='n4524' href='#n4524'>4524</a>
<a id='n4525' href='#n4525'>4525</a>
<a id='n4526' href='#n4526'>4526</a>
<a id='n4527' href='#n4527'>4527</a>
<a id='n4528' href='#n4528'>4528</a>
<a id='n4529' href='#n4529'>4529</a>
<a id='n4530' href='#n4530'>4530</a>
<a id='n4531' href='#n4531'>4531</a>
<a id='n4532' href='#n4532'>4532</a>
<a id='n4533' href='#n4533'>4533</a>
<a id='n4534' href='#n4534'>4534</a>
<a id='n4535' href='#n4535'>4535</a>
<a id='n4536' href='#n4536'>4536</a>
<a id='n4537' href='#n4537'>4537</a>
<a id='n4538' href='#n4538'>4538</a>
<a id='n4539' href='#n4539'>4539</a>
<a id='n4540' href='#n4540'>4540</a>
<a id='n4541' href='#n4541'>4541</a>
<a id='n4542' href='#n4542'>4542</a>
<a id='n4543' href='#n4543'>4543</a>
<a id='n4544' href='#n4544'>4544</a>
<a id='n4545' href='#n4545'>4545</a>
<a id='n4546' href='#n4546'>4546</a>
<a id='n4547' href='#n4547'>4547</a>
<a id='n4548' href='#n4548'>4548</a>
<a id='n4549' href='#n4549'>4549</a>
<a id='n4550' href='#n4550'>4550</a>
<a id='n4551' href='#n4551'>4551</a>
<a id='n4552' href='#n4552'>4552</a>
<a id='n4553' href='#n4553'>4553</a>
<a id='n4554' href='#n4554'>4554</a>
<a id='n4555' href='#n4555'>4555</a>
<a id='n4556' href='#n4556'>4556</a>
<a id='n4557' href='#n4557'>4557</a>
<a id='n4558' href='#n4558'>4558</a>
<a id='n4559' href='#n4559'>4559</a>
<a id='n4560' href='#n4560'>4560</a>
<a id='n4561' href='#n4561'>4561</a>
<a id='n4562' href='#n4562'>4562</a>
<a id='n4563' href='#n4563'>4563</a>
<a id='n4564' href='#n4564'>4564</a>
<a id='n4565' href='#n4565'>4565</a>
<a id='n4566' href='#n4566'>4566</a>
<a id='n4567' href='#n4567'>4567</a>
<a id='n4568' href='#n4568'>4568</a>
<a id='n4569' href='#n4569'>4569</a>
<a id='n4570' href='#n4570'>4570</a>
<a id='n4571' href='#n4571'>4571</a>
<a id='n4572' href='#n4572'>4572</a>
<a id='n4573' href='#n4573'>4573</a>
<a id='n4574' href='#n4574'>4574</a>
<a id='n4575' href='#n4575'>4575</a>
<a id='n4576' href='#n4576'>4576</a>
<a id='n4577' href='#n4577'>4577</a>
<a id='n4578' href='#n4578'>4578</a>
<a id='n4579' href='#n4579'>4579</a>
<a id='n4580' href='#n4580'>4580</a>
<a id='n4581' href='#n4581'>4581</a>
<a id='n4582' href='#n4582'>4582</a>
<a id='n4583' href='#n4583'>4583</a>
<a id='n4584' href='#n4584'>4584</a>
<a id='n4585' href='#n4585'>4585</a>
<a id='n4586' href='#n4586'>4586</a>
<a id='n4587' href='#n4587'>4587</a>
<a id='n4588' href='#n4588'>4588</a>
<a id='n4589' href='#n4589'>4589</a>
<a id='n4590' href='#n4590'>4590</a>
<a id='n4591' href='#n4591'>4591</a>
<a id='n4592' href='#n4592'>4592</a>
<a id='n4593' href='#n4593'>4593</a>
<a id='n4594' href='#n4594'>4594</a>
<a id='n4595' href='#n4595'>4595</a>
<a id='n4596' href='#n4596'>4596</a>
<a id='n4597' href='#n4597'>4597</a>
<a id='n4598' href='#n4598'>4598</a>
<a id='n4599' href='#n4599'>4599</a>
<a id='n4600' href='#n4600'>4600</a>
<a id='n4601' href='#n4601'>4601</a>
<a id='n4602' href='#n4602'>4602</a>
<a id='n4603' href='#n4603'>4603</a>
<a id='n4604' href='#n4604'>4604</a>
<a id='n4605' href='#n4605'>4605</a>
<a id='n4606' href='#n4606'>4606</a>
<a id='n4607' href='#n4607'>4607</a>
<a id='n4608' href='#n4608'>4608</a>
<a id='n4609' href='#n4609'>4609</a>
<a id='n4610' href='#n4610'>4610</a>
<a id='n4611' href='#n4611'>4611</a>
<a id='n4612' href='#n4612'>4612</a>
<a id='n4613' href='#n4613'>4613</a>
<a id='n4614' href='#n4614'>4614</a>
<a id='n4615' href='#n4615'>4615</a>
<a id='n4616' href='#n4616'>4616</a>
<a id='n4617' href='#n4617'>4617</a>
<a id='n4618' href='#n4618'>4618</a>
<a id='n4619' href='#n4619'>4619</a>
<a id='n4620' href='#n4620'>4620</a>
<a id='n4621' href='#n4621'>4621</a>
<a id='n4622' href='#n4622'>4622</a>
<a id='n4623' href='#n4623'>4623</a>
<a id='n4624' href='#n4624'>4624</a>
<a id='n4625' href='#n4625'>4625</a>
<a id='n4626' href='#n4626'>4626</a>
<a id='n4627' href='#n4627'>4627</a>
<a id='n4628' href='#n4628'>4628</a>
<a id='n4629' href='#n4629'>4629</a>
<a id='n4630' href='#n4630'>4630</a>
<a id='n4631' href='#n4631'>4631</a>
<a id='n4632' href='#n4632'>4632</a>
<a id='n4633' href='#n4633'>4633</a>
<a id='n4634' href='#n4634'>4634</a>
<a id='n4635' href='#n4635'>4635</a>
<a id='n4636' href='#n4636'>4636</a>
<a id='n4637' href='#n4637'>4637</a>
<a id='n4638' href='#n4638'>4638</a>
<a id='n4639' href='#n4639'>4639</a>
<a id='n4640' href='#n4640'>4640</a>
<a id='n4641' href='#n4641'>4641</a>
<a id='n4642' href='#n4642'>4642</a>
<a id='n4643' href='#n4643'>4643</a>
<a id='n4644' href='#n4644'>4644</a>
<a id='n4645' href='#n4645'>4645</a>
<a id='n4646' href='#n4646'>4646</a>
<a id='n4647' href='#n4647'>4647</a>
<a id='n4648' href='#n4648'>4648</a>
<a id='n4649' href='#n4649'>4649</a>
<a id='n4650' href='#n4650'>4650</a>
<a id='n4651' href='#n4651'>4651</a>
<a id='n4652' href='#n4652'>4652</a>
<a id='n4653' href='#n4653'>4653</a>
<a id='n4654' href='#n4654'>4654</a>
<a id='n4655' href='#n4655'>4655</a>
<a id='n4656' href='#n4656'>4656</a>
<a id='n4657' href='#n4657'>4657</a>
<a id='n4658' href='#n4658'>4658</a>
<a id='n4659' href='#n4659'>4659</a>
<a id='n4660' href='#n4660'>4660</a>
<a id='n4661' href='#n4661'>4661</a>
<a id='n4662' href='#n4662'>4662</a>
<a id='n4663' href='#n4663'>4663</a>
<a id='n4664' href='#n4664'>4664</a>
<a id='n4665' href='#n4665'>4665</a>
<a id='n4666' href='#n4666'>4666</a>
<a id='n4667' href='#n4667'>4667</a>
<a id='n4668' href='#n4668'>4668</a>
<a id='n4669' href='#n4669'>4669</a>
<a id='n4670' href='#n4670'>4670</a>
<a id='n4671' href='#n4671'>4671</a>
<a id='n4672' href='#n4672'>4672</a>
<a id='n4673' href='#n4673'>4673</a>
<a id='n4674' href='#n4674'>4674</a>
<a id='n4675' href='#n4675'>4675</a>
<a id='n4676' href='#n4676'>4676</a>
<a id='n4677' href='#n4677'>4677</a>
<a id='n4678' href='#n4678'>4678</a>
<a id='n4679' href='#n4679'>4679</a>
<a id='n4680' href='#n4680'>4680</a>
<a id='n4681' href='#n4681'>4681</a>
<a id='n4682' href='#n4682'>4682</a>
<a id='n4683' href='#n4683'>4683</a>
<a id='n4684' href='#n4684'>4684</a>
<a id='n4685' href='#n4685'>4685</a>
<a id='n4686' href='#n4686'>4686</a>
<a id='n4687' href='#n4687'>4687</a>
<a id='n4688' href='#n4688'>4688</a>
<a id='n4689' href='#n4689'>4689</a>
<a id='n4690' href='#n4690'>4690</a>
<a id='n4691' href='#n4691'>4691</a>
<a id='n4692' href='#n4692'>4692</a>
<a id='n4693' href='#n4693'>4693</a>
<a id='n4694' href='#n4694'>4694</a>
<a id='n4695' href='#n4695'>4695</a>
<a id='n4696' href='#n4696'>4696</a>
<a id='n4697' href='#n4697'>4697</a>
<a id='n4698' href='#n4698'>4698</a>
<a id='n4699' href='#n4699'>4699</a>
<a id='n4700' href='#n4700'>4700</a>
<a id='n4701' href='#n4701'>4701</a>
<a id='n4702' href='#n4702'>4702</a>
<a id='n4703' href='#n4703'>4703</a>
<a id='n4704' href='#n4704'>4704</a>
<a id='n4705' href='#n4705'>4705</a>
<a id='n4706' href='#n4706'>4706</a>
<a id='n4707' href='#n4707'>4707</a>
<a id='n4708' href='#n4708'>4708</a>
<a id='n4709' href='#n4709'>4709</a>
<a id='n4710' href='#n4710'>4710</a>
<a id='n4711' href='#n4711'>4711</a>
<a id='n4712' href='#n4712'>4712</a>
<a id='n4713' href='#n4713'>4713</a>
<a id='n4714' href='#n4714'>4714</a>
<a id='n4715' href='#n4715'>4715</a>
<a id='n4716' href='#n4716'>4716</a>
<a id='n4717' href='#n4717'>4717</a>
<a id='n4718' href='#n4718'>4718</a>
<a id='n4719' href='#n4719'>4719</a>
<a id='n4720' href='#n4720'>4720</a>
<a id='n4721' href='#n4721'>4721</a>
<a id='n4722' href='#n4722'>4722</a>
<a id='n4723' href='#n4723'>4723</a>
<a id='n4724' href='#n4724'>4724</a>
<a id='n4725' href='#n4725'>4725</a>
<a id='n4726' href='#n4726'>4726</a>
<a id='n4727' href='#n4727'>4727</a>
<a id='n4728' href='#n4728'>4728</a>
<a id='n4729' href='#n4729'>4729</a>
<a id='n4730' href='#n4730'>4730</a>
<a id='n4731' href='#n4731'>4731</a>
<a id='n4732' href='#n4732'>4732</a>
<a id='n4733' href='#n4733'>4733</a>
<a id='n4734' href='#n4734'>4734</a>
<a id='n4735' href='#n4735'>4735</a>
<a id='n4736' href='#n4736'>4736</a>
<a id='n4737' href='#n4737'>4737</a>
<a id='n4738' href='#n4738'>4738</a>
<a id='n4739' href='#n4739'>4739</a>
<a id='n4740' href='#n4740'>4740</a>
<a id='n4741' href='#n4741'>4741</a>
<a id='n4742' href='#n4742'>4742</a>
<a id='n4743' href='#n4743'>4743</a>
<a id='n4744' href='#n4744'>4744</a>
<a id='n4745' href='#n4745'>4745</a>
<a id='n4746' href='#n4746'>4746</a>
<a id='n4747' href='#n4747'>4747</a>
<a id='n4748' href='#n4748'>4748</a>
<a id='n4749' href='#n4749'>4749</a>
<a id='n4750' href='#n4750'>4750</a>
<a id='n4751' href='#n4751'>4751</a>
<a id='n4752' href='#n4752'>4752</a>
<a id='n4753' href='#n4753'>4753</a>
<a id='n4754' href='#n4754'>4754</a>
<a id='n4755' href='#n4755'>4755</a>
<a id='n4756' href='#n4756'>4756</a>
<a id='n4757' href='#n4757'>4757</a>
<a id='n4758' href='#n4758'>4758</a>
<a id='n4759' href='#n4759'>4759</a>
<a id='n4760' href='#n4760'>4760</a>
<a id='n4761' href='#n4761'>4761</a>
<a id='n4762' href='#n4762'>4762</a>
<a id='n4763' href='#n4763'>4763</a>
<a id='n4764' href='#n4764'>4764</a>
<a id='n4765' href='#n4765'>4765</a>
<a id='n4766' href='#n4766'>4766</a>
<a id='n4767' href='#n4767'>4767</a>
<a id='n4768' href='#n4768'>4768</a>
<a id='n4769' href='#n4769'>4769</a>
<a id='n4770' href='#n4770'>4770</a>
<a id='n4771' href='#n4771'>4771</a>
<a id='n4772' href='#n4772'>4772</a>
<a id='n4773' href='#n4773'>4773</a>
<a id='n4774' href='#n4774'>4774</a>
<a id='n4775' href='#n4775'>4775</a>
<a id='n4776' href='#n4776'>4776</a>
<a id='n4777' href='#n4777'>4777</a>
<a id='n4778' href='#n4778'>4778</a>
<a id='n4779' href='#n4779'>4779</a>
<a id='n4780' href='#n4780'>4780</a>
<a id='n4781' href='#n4781'>4781</a>
<a id='n4782' href='#n4782'>4782</a>
<a id='n4783' href='#n4783'>4783</a>
<a id='n4784' href='#n4784'>4784</a>
<a id='n4785' href='#n4785'>4785</a>
<a id='n4786' href='#n4786'>4786</a>
<a id='n4787' href='#n4787'>4787</a>
<a id='n4788' href='#n4788'>4788</a>
<a id='n4789' href='#n4789'>4789</a>
<a id='n4790' href='#n4790'>4790</a>
<a id='n4791' href='#n4791'>4791</a>
<a id='n4792' href='#n4792'>4792</a>
<a id='n4793' href='#n4793'>4793</a>
<a id='n4794' href='#n4794'>4794</a>
<a id='n4795' href='#n4795'>4795</a>
<a id='n4796' href='#n4796'>4796</a>
<a id='n4797' href='#n4797'>4797</a>
<a id='n4798' href='#n4798'>4798</a>
<a id='n4799' href='#n4799'>4799</a>
<a id='n4800' href='#n4800'>4800</a>
<a id='n4801' href='#n4801'>4801</a>
<a id='n4802' href='#n4802'>4802</a>
<a id='n4803' href='#n4803'>4803</a>
<a id='n4804' href='#n4804'>4804</a>
<a id='n4805' href='#n4805'>4805</a>
<a id='n4806' href='#n4806'>4806</a>
<a id='n4807' href='#n4807'>4807</a>
<a id='n4808' href='#n4808'>4808</a>
<a id='n4809' href='#n4809'>4809</a>
<a id='n4810' href='#n4810'>4810</a>
<a id='n4811' href='#n4811'>4811</a>
<a id='n4812' href='#n4812'>4812</a>
<a id='n4813' href='#n4813'>4813</a>
<a id='n4814' href='#n4814'>4814</a>
<a id='n4815' href='#n4815'>4815</a>
<a id='n4816' href='#n4816'>4816</a>
<a id='n4817' href='#n4817'>4817</a>
<a id='n4818' href='#n4818'>4818</a>
<a id='n4819' href='#n4819'>4819</a>
<a id='n4820' href='#n4820'>4820</a>
<a id='n4821' href='#n4821'>4821</a>
<a id='n4822' href='#n4822'>4822</a>
<a id='n4823' href='#n4823'>4823</a>
<a id='n4824' href='#n4824'>4824</a>
<a id='n4825' href='#n4825'>4825</a>
<a id='n4826' href='#n4826'>4826</a>
<a id='n4827' href='#n4827'>4827</a>
<a id='n4828' href='#n4828'>4828</a>
<a id='n4829' href='#n4829'>4829</a>
<a id='n4830' href='#n4830'>4830</a>
<a id='n4831' href='#n4831'>4831</a>
<a id='n4832' href='#n4832'>4832</a>
<a id='n4833' href='#n4833'>4833</a>
<a id='n4834' href='#n4834'>4834</a>
<a id='n4835' href='#n4835'>4835</a>
<a id='n4836' href='#n4836'>4836</a>
<a id='n4837' href='#n4837'>4837</a>
<a id='n4838' href='#n4838'>4838</a>
<a id='n4839' href='#n4839'>4839</a>
<a id='n4840' href='#n4840'>4840</a>
<a id='n4841' href='#n4841'>4841</a>
<a id='n4842' href='#n4842'>4842</a>
<a id='n4843' href='#n4843'>4843</a>
<a id='n4844' href='#n4844'>4844</a>
<a id='n4845' href='#n4845'>4845</a>
<a id='n4846' href='#n4846'>4846</a>
<a id='n4847' href='#n4847'>4847</a>
<a id='n4848' href='#n4848'>4848</a>
<a id='n4849' href='#n4849'>4849</a>
<a id='n4850' href='#n4850'>4850</a>
<a id='n4851' href='#n4851'>4851</a>
<a id='n4852' href='#n4852'>4852</a>
<a id='n4853' href='#n4853'>4853</a>
<a id='n4854' href='#n4854'>4854</a>
<a id='n4855' href='#n4855'>4855</a>
<a id='n4856' href='#n4856'>4856</a>
<a id='n4857' href='#n4857'>4857</a>
<a id='n4858' href='#n4858'>4858</a>
<a id='n4859' href='#n4859'>4859</a>
<a id='n4860' href='#n4860'>4860</a>
<a id='n4861' href='#n4861'>4861</a>
<a id='n4862' href='#n4862'>4862</a>
<a id='n4863' href='#n4863'>4863</a>
<a id='n4864' href='#n4864'>4864</a>
<a id='n4865' href='#n4865'>4865</a>
<a id='n4866' href='#n4866'>4866</a>
<a id='n4867' href='#n4867'>4867</a>
<a id='n4868' href='#n4868'>4868</a>
<a id='n4869' href='#n4869'>4869</a>
<a id='n4870' href='#n4870'>4870</a>
<a id='n4871' href='#n4871'>4871</a>
<a id='n4872' href='#n4872'>4872</a>
<a id='n4873' href='#n4873'>4873</a>
<a id='n4874' href='#n4874'>4874</a>
<a id='n4875' href='#n4875'>4875</a>
<a id='n4876' href='#n4876'>4876</a>
<a id='n4877' href='#n4877'>4877</a>
<a id='n4878' href='#n4878'>4878</a>
<a id='n4879' href='#n4879'>4879</a>
<a id='n4880' href='#n4880'>4880</a>
<a id='n4881' href='#n4881'>4881</a>
<a id='n4882' href='#n4882'>4882</a>
<a id='n4883' href='#n4883'>4883</a>
<a id='n4884' href='#n4884'>4884</a>
<a id='n4885' href='#n4885'>4885</a>
<a id='n4886' href='#n4886'>4886</a>
<a id='n4887' href='#n4887'>4887</a>
<a id='n4888' href='#n4888'>4888</a>
<a id='n4889' href='#n4889'>4889</a>
<a id='n4890' href='#n4890'>4890</a>
<a id='n4891' href='#n4891'>4891</a>
<a id='n4892' href='#n4892'>4892</a>
<a id='n4893' href='#n4893'>4893</a>
<a id='n4894' href='#n4894'>4894</a>
<a id='n4895' href='#n4895'>4895</a>
<a id='n4896' href='#n4896'>4896</a>
<a id='n4897' href='#n4897'>4897</a>
<a id='n4898' href='#n4898'>4898</a>
<a id='n4899' href='#n4899'>4899</a>
<a id='n4900' href='#n4900'>4900</a>
<a id='n4901' href='#n4901'>4901</a>
<a id='n4902' href='#n4902'>4902</a>
<a id='n4903' href='#n4903'>4903</a>
<a id='n4904' href='#n4904'>4904</a>
<a id='n4905' href='#n4905'>4905</a>
<a id='n4906' href='#n4906'>4906</a>
<a id='n4907' href='#n4907'>4907</a>
<a id='n4908' href='#n4908'>4908</a>
<a id='n4909' href='#n4909'>4909</a>
<a id='n4910' href='#n4910'>4910</a>
<a id='n4911' href='#n4911'>4911</a>
<a id='n4912' href='#n4912'>4912</a>
<a id='n4913' href='#n4913'>4913</a>
<a id='n4914' href='#n4914'>4914</a>
<a id='n4915' href='#n4915'>4915</a>
<a id='n4916' href='#n4916'>4916</a>
<a id='n4917' href='#n4917'>4917</a>
<a id='n4918' href='#n4918'>4918</a>
<a id='n4919' href='#n4919'>4919</a>
<a id='n4920' href='#n4920'>4920</a>
<a id='n4921' href='#n4921'>4921</a>
<a id='n4922' href='#n4922'>4922</a>
<a id='n4923' href='#n4923'>4923</a>
<a id='n4924' href='#n4924'>4924</a>
<a id='n4925' href='#n4925'>4925</a>
<a id='n4926' href='#n4926'>4926</a>
<a id='n4927' href='#n4927'>4927</a>
<a id='n4928' href='#n4928'>4928</a>
<a id='n4929' href='#n4929'>4929</a>
<a id='n4930' href='#n4930'>4930</a>
<a id='n4931' href='#n4931'>4931</a>
<a id='n4932' href='#n4932'>4932</a>
<a id='n4933' href='#n4933'>4933</a>
<a id='n4934' href='#n4934'>4934</a>
<a id='n4935' href='#n4935'>4935</a>
<a id='n4936' href='#n4936'>4936</a>
<a id='n4937' href='#n4937'>4937</a>
<a id='n4938' href='#n4938'>4938</a>
<a id='n4939' href='#n4939'>4939</a>
<a id='n4940' href='#n4940'>4940</a>
<a id='n4941' href='#n4941'>4941</a>
<a id='n4942' href='#n4942'>4942</a>
<a id='n4943' href='#n4943'>4943</a>
<a id='n4944' href='#n4944'>4944</a>
<a id='n4945' href='#n4945'>4945</a>
<a id='n4946' href='#n4946'>4946</a>
<a id='n4947' href='#n4947'>4947</a>
<a id='n4948' href='#n4948'>4948</a>
<a id='n4949' href='#n4949'>4949</a>
<a id='n4950' href='#n4950'>4950</a>
<a id='n4951' href='#n4951'>4951</a>
<a id='n4952' href='#n4952'>4952</a>
<a id='n4953' href='#n4953'>4953</a>
<a id='n4954' href='#n4954'>4954</a>
<a id='n4955' href='#n4955'>4955</a>
<a id='n4956' href='#n4956'>4956</a>
<a id='n4957' href='#n4957'>4957</a>
<a id='n4958' href='#n4958'>4958</a>
<a id='n4959' href='#n4959'>4959</a>
<a id='n4960' href='#n4960'>4960</a>
<a id='n4961' href='#n4961'>4961</a>
<a id='n4962' href='#n4962'>4962</a>
<a id='n4963' href='#n4963'>4963</a>
<a id='n4964' href='#n4964'>4964</a>
<a id='n4965' href='#n4965'>4965</a>
<a id='n4966' href='#n4966'>4966</a>
<a id='n4967' href='#n4967'>4967</a>
<a id='n4968' href='#n4968'>4968</a>
<a id='n4969' href='#n4969'>4969</a>
<a id='n4970' href='#n4970'>4970</a>
<a id='n4971' href='#n4971'>4971</a>
<a id='n4972' href='#n4972'>4972</a>
<a id='n4973' href='#n4973'>4973</a>
<a id='n4974' href='#n4974'>4974</a>
<a id='n4975' href='#n4975'>4975</a>
<a id='n4976' href='#n4976'>4976</a>
<a id='n4977' href='#n4977'>4977</a>
<a id='n4978' href='#n4978'>4978</a>
<a id='n4979' href='#n4979'>4979</a>
<a id='n4980' href='#n4980'>4980</a>
<a id='n4981' href='#n4981'>4981</a>
<a id='n4982' href='#n4982'>4982</a>
<a id='n4983' href='#n4983'>4983</a>
<a id='n4984' href='#n4984'>4984</a>
<a id='n4985' href='#n4985'>4985</a>
<a id='n4986' href='#n4986'>4986</a>
<a id='n4987' href='#n4987'>4987</a>
<a id='n4988' href='#n4988'>4988</a>
<a id='n4989' href='#n4989'>4989</a>
<a id='n4990' href='#n4990'>4990</a>
<a id='n4991' href='#n4991'>4991</a>
<a id='n4992' href='#n4992'>4992</a>
<a id='n4993' href='#n4993'>4993</a>
<a id='n4994' href='#n4994'>4994</a>
<a id='n4995' href='#n4995'>4995</a>
<a id='n4996' href='#n4996'>4996</a>
<a id='n4997' href='#n4997'>4997</a>
<a id='n4998' href='#n4998'>4998</a>
<a id='n4999' href='#n4999'>4999</a>
<a id='n5000' href='#n5000'>5000</a>
<a id='n5001' href='#n5001'>5001</a>
<a id='n5002' href='#n5002'>5002</a>
<a id='n5003' href='#n5003'>5003</a>
<a id='n5004' href='#n5004'>5004</a>
<a id='n5005' href='#n5005'>5005</a>
<a id='n5006' href='#n5006'>5006</a>
<a id='n5007' href='#n5007'>5007</a>
<a id='n5008' href='#n5008'>5008</a>
<a id='n5009' href='#n5009'>5009</a>
<a id='n5010' href='#n5010'>5010</a>
<a id='n5011' href='#n5011'>5011</a>
<a id='n5012' href='#n5012'>5012</a>
<a id='n5013' href='#n5013'>5013</a>
<a id='n5014' href='#n5014'>5014</a>
<a id='n5015' href='#n5015'>5015</a>
<a id='n5016' href='#n5016'>5016</a>
<a id='n5017' href='#n5017'>5017</a>
<a id='n5018' href='#n5018'>5018</a>
<a id='n5019' href='#n5019'>5019</a>
<a id='n5020' href='#n5020'>5020</a>
<a id='n5021' href='#n5021'>5021</a>
<a id='n5022' href='#n5022'>5022</a>
<a id='n5023' href='#n5023'>5023</a>
<a id='n5024' href='#n5024'>5024</a>
<a id='n5025' href='#n5025'>5025</a>
<a id='n5026' href='#n5026'>5026</a>
<a id='n5027' href='#n5027'>5027</a>
<a id='n5028' href='#n5028'>5028</a>
<a id='n5029' href='#n5029'>5029</a>
<a id='n5030' href='#n5030'>5030</a>
<a id='n5031' href='#n5031'>5031</a>
<a id='n5032' href='#n5032'>5032</a>
<a id='n5033' href='#n5033'>5033</a>
<a id='n5034' href='#n5034'>5034</a>
<a id='n5035' href='#n5035'>5035</a>
<a id='n5036' href='#n5036'>5036</a>
<a id='n5037' href='#n5037'>5037</a>
<a id='n5038' href='#n5038'>5038</a>
<a id='n5039' href='#n5039'>5039</a>
<a id='n5040' href='#n5040'>5040</a>
<a id='n5041' href='#n5041'>5041</a>
<a id='n5042' href='#n5042'>5042</a>
<a id='n5043' href='#n5043'>5043</a>
<a id='n5044' href='#n5044'>5044</a>
<a id='n5045' href='#n5045'>5045</a>
<a id='n5046' href='#n5046'>5046</a>
</pre></td>
<td class='lines'><pre><code>/* vi: set sw=4 ts=4: */
/*
 * tiny vi.c: A small 'vi' clone
 * Copyright (C) 2000, 2001 Sterling Huxley &lt;sterling@europa.com&gt;
 *
 * Licensed under GPLv2 or later, see file LICENSE in this source tree.
 */
//
//Things To Do:
//	./.exrc
//	add magic to search	/foo.*bar
//	add :help command
//	:map macros
//	if mark[] values were line numbers rather than pointers
//	it would be easier to change the mark when add/delete lines
//	More intelligence in refresh()
//	":r !cmd"  and  "!cmd"  to filter text through an external command
//	An "ex" line oriented mode- maybe using "cmdedit"

//config:config VI
//config:	bool "vi (23 kb)"
//config:	default y
//config:	help
//config:	'vi' is a text editor. More specifically, it is the One True
//config:	text editor &lt;grin&gt;. It does, however, have a rather steep
//config:	learning curve. If you are not already comfortable with 'vi'
//config:	you may wish to use something else.
//config:
//config:config FEATURE_VI_MAX_LEN
//config:	int "Maximum screen width"
//config:	range 256 16384
//config:	default 4096
//config:	depends on VI
//config:	help
//config:	Contrary to what you may think, this is not eating much.
//config:	Make it smaller than 4k only if you are very limited on memory.
//config:
//config:config FEATURE_VI_8BIT
//config:	bool "Allow to display 8-bit chars (otherwise shows dots)"
//config:	default n
//config:	depends on VI
//config:	help
//config:	If your terminal can display characters with high bit set,
//config:	you may want to enable this. Note: vi is not Unicode-capable.
//config:	If your terminal combines several 8-bit bytes into one character
//config:	(as in Unicode mode), this will not work properly.
//config:
//config:config FEATURE_VI_COLON
//config:	bool "Enable \":\" colon commands (no \"ex\" mode)"
//config:	default y
//config:	depends on VI
//config:	help
//config:	Enable a limited set of colon commands. This does not
//config:	provide an "ex" mode.
//config:
//config:config FEATURE_VI_COLON_EXPAND
//config:	bool "Expand \"%\" and \"#\" in colon commands"
//config:	default y
//config:	depends on FEATURE_VI_COLON
//config:	help
//config:	Expand the special characters \"%\" (current filename)
//config:	and \"#\" (alternate filename) in colon commands.
//config:
//config:config FEATURE_VI_YANKMARK
//config:	bool "Enable yank/put commands and mark cmds"
//config:	default y
//config:	depends on VI
//config:	help
//config:	This enables you to use yank and put, as well as mark.
//config:
//config:config FEATURE_VI_SEARCH
//config:	bool "Enable search and replace cmds"
//config:	default y
//config:	depends on VI
//config:	help
//config:	Select this if you wish to be able to do search and replace.
//config:
//config:config FEATURE_VI_REGEX_SEARCH
//config:	bool "Enable regex in search and replace"
//config:	default n   # Uses GNU regex, which may be unavailable. FIXME
//config:	depends on FEATURE_VI_SEARCH
//config:	help
//config:	Use extended regex search.
//config:
//config:config FEATURE_VI_USE_SIGNALS
//config:	bool "Catch signals"
//config:	default y
//config:	depends on VI
//config:	help
//config:	Selecting this option will make vi signal aware. This will support
//config:	SIGWINCH to deal with Window Changes, catch ^Z and ^C and alarms.
//config:
//config:config FEATURE_VI_DOT_CMD
//config:	bool "Remember previous cmd and \".\" cmd"
//config:	default y
//config:	depends on VI
//config:	help
//config:	Make vi remember the last command and be able to repeat it.
//config:
//config:config FEATURE_VI_READONLY
//config:	bool "Enable -R option and \"view\" mode"
//config:	default y
//config:	depends on VI
//config:	help
//config:	Enable the read-only command line option, which allows the user to
//config:	open a file in read-only mode.
//config:
//config:config FEATURE_VI_SETOPTS
//config:	bool "Enable settable options, ai ic showmatch"
//config:	default y
//config:	depends on VI
//config:	help
//config:	Enable the editor to set some (ai, ic, showmatch) options.
//config:
//config:config FEATURE_VI_SET
//config:	bool "Support :set"
//config:	default y
//config:	depends on VI
//config:
//config:config FEATURE_VI_WIN_RESIZE
//config:	bool "Handle window resize"
//config:	default y
//config:	depends on VI
//config:	help
//config:	Behave nicely with terminals that get resized.
//config:
//config:config FEATURE_VI_ASK_TERMINAL
//config:	bool "Use 'tell me cursor position' ESC sequence to measure window"
//config:	default y
//config:	depends on VI
//config:	help
//config:	If terminal size can't be retrieved and $LINES/$COLUMNS are not set,
//config:	this option makes vi perform a last-ditch effort to find it:
//config:	position cursor to 999,999 and ask terminal to report real
//config:	cursor position using "ESC [ 6 n" escape sequence, then read stdin.
//config:	This is not clean but helps a lot on serial lines and such.
//config:
//config:config FEATURE_VI_UNDO
//config:	bool "Support undo command \"u\""
//config:	default y
//config:	depends on VI
//config:	help
//config:	Support the 'u' command to undo insertion, deletion, and replacement
//config:	of text.
//config:
//config:config FEATURE_VI_UNDO_QUEUE
//config:	bool "Enable undo operation queuing"
//config:	default y
//config:	depends on FEATURE_VI_UNDO
//config:	help
//config:	The vi undo functions can use an intermediate queue to greatly lower
//config:	malloc() calls and overhead. When the maximum size of this queue is
//config:	reached, the contents of the queue are committed to the undo stack.
//config:	This increases the size of the undo code and allows some undo
//config:	operations (especially un-typing/backspacing) to be far more useful.
//config:
//config:config FEATURE_VI_UNDO_QUEUE_MAX
//config:	int "Maximum undo character queue size"
//config:	default 256
//config:	range 32 65536
//config:	depends on FEATURE_VI_UNDO_QUEUE
//config:	help
//config:	This option sets the number of bytes used at runtime for the queue.
//config:	Smaller values will create more undo objects and reduce the amount
//config:	of typed or backspaced characters that are grouped into one undo
//config:	operation; larger values increase the potential size of each undo
//config:	and will generally malloc() larger objects and less frequently.
//config:	Unless you want more (or less) frequent "undo points" while typing,
//config:	you should probably leave this unchanged.
//config:
//config:config FEATURE_VI_VERBOSE_STATUS
//config:	bool "Enable verbose status reporting"
//config:	default y
//config:	depends on VI
//config:	help
//config:	Enable more verbose reporting of the results of yank, change,
//config:	delete, undo and substitution commands.

//applet:IF_VI(APPLET(vi, BB_DIR_BIN, BB_SUID_DROP))

//kbuild:lib-$(CONFIG_VI) += vi.o

//usage:#define vi_trivial_usage
//usage:       IF_FEATURE_VI_COLON("[-c CMD] ")IF_FEATURE_VI_READONLY("[-R] ")"[-H] [FILE]..."
//usage:#define vi_full_usage "\n\n"
//usage:       "Edit FILE\n"
//usage:	IF_FEATURE_VI_COLON(
//usage:     "\n	-c CMD	Initial command to run ($EXINIT and ~/.exrc also available)"
//usage:	)
//usage:	IF_FEATURE_VI_READONLY(
//usage:     "\n	-R	Read-only"
//usage:	)
//usage:     "\n	-H	List available features"
// note: non-standard, "vim -H" is Hebrew mode (bidi support)

#include "libbb.h"
// Should be after libbb.h: on some systems regex.h needs sys/types.h:
#if ENABLE_FEATURE_VI_REGEX_SEARCH
# include &lt;regex.h&gt;
#endif

// the CRASHME code is unmaintained, and doesn't currently build
#define ENABLE_FEATURE_VI_CRASHME 0
#define IF_FEATURE_VI_CRASHME(...)


#if ENABLE_LOCALE_SUPPORT

#if ENABLE_FEATURE_VI_8BIT
//FIXME: this does not work properly for Unicode anyway
# define Isprint(c) (isprint)(c)
#else
# define Isprint(c) isprint_asciionly(c)
#endif

#else

// 0x9b is Meta-ESC
#if ENABLE_FEATURE_VI_8BIT
# define Isprint(c) ((unsigned char)(c) &gt;= ' ' &amp;&amp; (c) != 0x7f &amp;&amp; (unsigned char)(c) != 0x9b)
#else
# define Isprint(c) ((unsigned char)(c) &gt;= ' ' &amp;&amp; (unsigned char)(c) &lt; 0x7f)
#endif

#endif

#define isbackspace(c) ((c) == term_orig.c_cc[VERASE] || (c) == 8 || (c) == 127)

enum {
	MAX_TABSTOP = 32, // sanity limit
	// User input len. Need not be extra big.
	// Lines in file being edited *can* be bigger than this.
	MAX_INPUT_LEN = 128,
	// Sanity limits. We have only one buffer of this size.
	MAX_SCR_COLS = CONFIG_FEATURE_VI_MAX_LEN,
	MAX_SCR_ROWS = CONFIG_FEATURE_VI_MAX_LEN,
};

// VT102 ESC sequences.
// See "Xterm Control Sequences"
// http://invisible-island.net/xterm/ctlseqs/ctlseqs.html
#define ESC "\033"
// Inverse/Normal text
#define ESC_BOLD_TEXT ESC"[7m"
#define ESC_NORM_TEXT ESC"[m"
// Bell
#define ESC_BELL "\007"
// Clear-to-end-of-line
#define ESC_CLEAR2EOL ESC"[K"
// Clear-to-end-of-screen.
// (We use default param here.
// Full sequence is "ESC [ &lt;num&gt; J",
// &lt;num&gt; is 0/1/2 = "erase below/above/all".)
#define ESC_CLEAR2EOS          ESC"[J"
// Cursor to given coordinate (1,1: top left)
#define ESC_SET_CURSOR_POS     ESC"[%u;%uH"
#define ESC_SET_CURSOR_TOPLEFT ESC"[H"
//UNUSED
//// Cursor up and down
//#define ESC_CURSOR_UP   ESC"[A"
//#define ESC_CURSOR_DOWN "\n"

#if ENABLE_FEATURE_VI_DOT_CMD
// cmds modifying text[]
static const char modifying_cmds[] ALIGN1 = "aAcCdDiIJoOpPrRs""xX&lt;&gt;~";
#endif

enum {
	YANKONLY = FALSE,
	YANKDEL = TRUE,
	FORWARD = 1,	// code depends on "1"  for array index
	BACK = -1,	// code depends on "-1" for array index
	LIMITED = 0,	// char_search() only current line
	FULL = 1,	// char_search() to the end/beginning of entire text
	PARTIAL = 0,	// buffer contains partial line
	WHOLE = 1,	// buffer contains whole lines
	MULTI = 2,	// buffer may include newlines

	S_BEFORE_WS = 1,	// used in skip_thing() for moving "dot"
	S_TO_WS = 2,		// used in skip_thing() for moving "dot"
	S_OVER_WS = 3,		// used in skip_thing() for moving "dot"
	S_END_PUNCT = 4,	// used in skip_thing() for moving "dot"
	S_END_ALNUM = 5,	// used in skip_thing() for moving "dot"

	C_END = -1,	// cursor is at end of line due to '$' command
};


// vi.c expects chars to be unsigned.
// busybox build system provides that, but it's better
// to audit and fix the source

struct globals {
	// many references - keep near the top of globals
	char *text, *end;       // pointers to the user data in memory
	char *dot;              // where all the action takes place
	int text_size;		// size of the allocated buffer

	// the rest
#if ENABLE_FEATURE_VI_SETOPTS
	smallint vi_setops;     // set by setops()
#define VI_AUTOINDENT (1 &lt;&lt; 0)
#define VI_EXPANDTAB  (1 &lt;&lt; 1)
#define VI_ERR_METHOD (1 &lt;&lt; 2)
#define VI_IGNORECASE (1 &lt;&lt; 3)
#define VI_SHOWMATCH  (1 &lt;&lt; 4)
#define VI_TABSTOP    (1 &lt;&lt; 5)
#define autoindent (vi_setops &amp; VI_AUTOINDENT)
#define expandtab  (vi_setops &amp; VI_EXPANDTAB )
#define err_method (vi_setops &amp; VI_ERR_METHOD) // indicate error with beep or flash
#define ignorecase (vi_setops &amp; VI_IGNORECASE)
#define showmatch  (vi_setops &amp; VI_SHOWMATCH )
// order of constants and strings must match
#define OPTS_STR \
		"ai\0""autoindent\0" \
		"et\0""expandtab\0" \
		"fl\0""flash\0" \
		"ic\0""ignorecase\0" \
		"sm\0""showmatch\0" \
		"ts\0""tabstop\0"
#else
#define autoindent (0)
#define expandtab  (0)
#define err_method (0)
#define ignorecase (0)
#endif

#if ENABLE_FEATURE_VI_READONLY
	smallint readonly_mode;
#define SET_READONLY_FILE(flags)        ((flags) |= 0x01)
#define SET_READONLY_MODE(flags)        ((flags) |= 0x02)
#define UNSET_READONLY_FILE(flags)      ((flags) &amp;= 0xfe)
#else
#define SET_READONLY_FILE(flags)        ((void)0)
#define SET_READONLY_MODE(flags)        ((void)0)
#define UNSET_READONLY_FILE(flags)      ((void)0)
#endif

	smallint editing;        // &gt;0 while we are editing a file
	                         // [code audit says "can be 0, 1 or 2 only"]
	smallint cmd_mode;       // 0=command  1=insert 2=replace
	int modified_count;      // buffer contents changed if !0
	int last_modified_count; // = -1;
	int cmdline_filecnt;     // how many file names on cmd line
	int cmdcnt;              // repetition count
	char *rstart;            // start of text in Replace mode
	unsigned rows, columns;	 // the terminal screen is this size
#if ENABLE_FEATURE_VI_ASK_TERMINAL
	int get_rowcol_error;
#endif
	int crow, ccol;          // cursor is on Crow x Ccol
	int offset;              // chars scrolled off the screen to the left
	int have_status_msg;     // is default edit status needed?
	                         // [don't make smallint!]
	int last_status_cksum;   // hash of current status line
	char *current_filename;
#if ENABLE_FEATURE_VI_COLON_EXPAND
	char *alt_filename;
#endif
	char *screenbegin;       // index into text[], of top line on the screen
	char *screen;            // pointer to the virtual screen buffer
	int screensize;          //            and its size
	int tabstop;
	int last_search_char;    // last char searched for (int because of Unicode)
	smallint last_search_cmd;    // command used to invoke last char search
#if ENABLE_FEATURE_VI_CRASHME
	char last_input_char;    // last char read from user
#endif
#if ENABLE_FEATURE_VI_UNDO_QUEUE
	char undo_queue_state;   // One of UNDO_INS, UNDO_DEL, UNDO_EMPTY
#endif

#if ENABLE_FEATURE_VI_DOT_CMD
	smallint adding2q;	 // are we currently adding user input to q
	int lmc_len;             // length of last_modifying_cmd
	char *ioq, *ioq_start;   // pointer to string for get_one_char to "read"
	int dotcnt;              // number of times to repeat '.' command
#endif
#if ENABLE_FEATURE_VI_SEARCH
	char *last_search_pattern; // last pattern from a '/' or '?' search
#endif
#if ENABLE_FEATURE_VI_SETOPTS
	int char_insert__indentcol;		// column of recent autoindent or 0
	int newindent;		// autoindent value for 'O'/'cc' commands
						// or -1 to use indent from previous line
#endif
	smallint cmd_error;

	// former statics
#if ENABLE_FEATURE_VI_YANKMARK
	char *edit_file__cur_line;
#endif
	int refresh__old_offset;
	int format_edit_status__tot;

	// a few references only
#if ENABLE_FEATURE_VI_YANKMARK
	smalluint YDreg;//,Ureg;// default delete register and orig line for "U"
#define Ureg 27
	char *reg[28];          // named register a-z, "D", and "U" 0-25,26,27
	char regtype[28];       // buffer type: WHOLE, MULTI or PARTIAL
	char *mark[28];         // user marks points somewhere in text[]-  a-z and previous context ''
#endif
#if ENABLE_FEATURE_VI_USE_SIGNALS
	sigjmp_buf restart;     // int_handler() jumps to location remembered here
#endif
	struct termios term_orig; // remember what the cooked mode was
	int cindex;               // saved character index for up/down motion
	smallint keep_index;      // retain saved character index
#if ENABLE_FEATURE_VI_COLON
	llist_t *initial_cmds;
#endif
	// Should be just enough to hold a key sequence,
	// but CRASHME mode uses it as generated command buffer too
#if ENABLE_FEATURE_VI_CRASHME
	char readbuffer[128];
#else
	char readbuffer[KEYCODE_BUFFER_SIZE];
#endif
#define STATUS_BUFFER_LEN  200
	char status_buffer[STATUS_BUFFER_LEN]; // messages to the user
#if ENABLE_FEATURE_VI_DOT_CMD
	char last_modifying_cmd[MAX_INPUT_LEN];	// last modifying cmd for "."
#endif
	char get_input_line__buf[MAX_INPUT_LEN]; // former static

	char scr_out_buf[MAX_SCR_COLS + MAX_TABSTOP * 2];

#if ENABLE_FEATURE_VI_UNDO
// undo_push() operations
#define UNDO_INS         0
#define UNDO_DEL         1
#define UNDO_INS_CHAIN   2
#define UNDO_DEL_CHAIN   3
# if ENABLE_FEATURE_VI_UNDO_QUEUE
#define UNDO_INS_QUEUED  4
#define UNDO_DEL_QUEUED  5
# endif

// Pass-through flags for functions that can be undone
#define NO_UNDO          0
#define ALLOW_UNDO       1
#define ALLOW_UNDO_CHAIN 2
# if ENABLE_FEATURE_VI_UNDO_QUEUE
#define ALLOW_UNDO_QUEUED 3
# else
// If undo queuing disabled, don't invoke the missing queue logic
#define ALLOW_UNDO_QUEUED ALLOW_UNDO
# endif

	struct undo_object {
		struct undo_object *prev;	// Linking back avoids list traversal (LIFO)
		int start;		// Offset where the data should be restored/deleted
		int length;		// total data size
		uint8_t u_type;		// 0=deleted, 1=inserted, 2=swapped
		char undo_text[1];	// text that was deleted (if deletion)
	} *undo_stack_tail;
# if ENABLE_FEATURE_VI_UNDO_QUEUE
#define UNDO_USE_SPOS   32
#define UNDO_EMPTY      64
	char *undo_queue_spos;	// Start position of queued operation
	int undo_q;
	char undo_queue[CONFIG_FEATURE_VI_UNDO_QUEUE_MAX];
# endif
#endif /* ENABLE_FEATURE_VI_UNDO */
};
#define G (*ptr_to_globals)
#define text           (G.text          )
#define text_size      (G.text_size     )
#define end            (G.end           )
#define dot            (G.dot           )
#define reg            (G.reg           )

#define vi_setops               (G.vi_setops          )
#define editing                 (G.editing            )
#define cmd_mode                (G.cmd_mode           )
#define modified_count          (G.modified_count     )
#define last_modified_count     (G.last_modified_count)
#define cmdline_filecnt         (G.cmdline_filecnt    )
#define cmdcnt                  (G.cmdcnt             )
#define rstart                  (G.rstart             )
#define rows                    (G.rows               )
#define columns                 (G.columns            )
#define crow                    (G.crow               )
#define ccol                    (G.ccol               )
#define offset                  (G.offset             )
#define status_buffer           (G.status_buffer      )
#define have_status_msg         (G.have_status_msg    )
#define last_status_cksum       (G.last_status_cksum  )
#define current_filename        (G.current_filename   )
#define alt_filename            (G.alt_filename       )
#define screen                  (G.screen             )
#define screensize              (G.screensize         )
#define screenbegin             (G.screenbegin        )
#define tabstop                 (G.tabstop            )
#define last_search_char        (G.last_search_char   )
#define last_search_cmd         (G.last_search_cmd    )
#if ENABLE_FEATURE_VI_CRASHME
#define last_input_char         (G.last_input_char    )
#endif
#if ENABLE_FEATURE_VI_READONLY
#define readonly_mode           (G.readonly_mode      )
#else
#define readonly_mode           0
#endif
#define adding2q                (G.adding2q           )
#define lmc_len                 (G.lmc_len            )
#define ioq                     (G.ioq                )
#define ioq_start               (G.ioq_start          )
#define dotcnt                  (G.dotcnt             )
#define last_search_pattern     (G.last_search_pattern)
#define char_insert__indentcol  (G.char_insert__indentcol)
#define newindent               (G.newindent          )
#define cmd_error               (G.cmd_error          )

#define edit_file__cur_line     (G.edit_file__cur_line)
#define refresh__old_offset     (G.refresh__old_offset)
#define format_edit_status__tot (G.format_edit_status__tot)

#define YDreg          (G.YDreg         )
//#define Ureg           (G.Ureg          )
#define regtype        (G.regtype       )
#define mark           (G.mark          )
#define restart        (G.restart       )
#define term_orig      (G.term_orig     )
#define cindex         (G.cindex        )
#define keep_index     (G.keep_index    )
#define initial_cmds   (G.initial_cmds  )
#define readbuffer     (G.readbuffer    )
#define scr_out_buf    (G.scr_out_buf   )
#define last_modifying_cmd  (G.last_modifying_cmd )
#define get_input_line__buf (G.get_input_line__buf)

#if ENABLE_FEATURE_VI_UNDO
#define undo_stack_tail  (G.undo_stack_tail )
# if ENABLE_FEATURE_VI_UNDO_QUEUE
#define undo_queue_state (G.undo_queue_state)
#define undo_q           (G.undo_q          )
#define undo_queue       (G.undo_queue      )
#define undo_queue_spos  (G.undo_queue_spos )
# endif
#endif

#define INIT_G() do { \
	SET_PTR_TO_GLOBALS(xzalloc(sizeof(G))); \
	last_modified_count--; \
	/* "" but has space for 2 chars: */ \
	IF_FEATURE_VI_SEARCH(last_search_pattern = xzalloc(2);) \
	tabstop = 8; \
	IF_FEATURE_VI_SETOPTS(newindent--;) \
} while (0)

#if ENABLE_FEATURE_VI_CRASHME
static int crashme = 0;
#endif

static void show_status_line(void);	// put a message on the bottom line
static void status_line_bold(const char *, ...);

static void show_help(void)
{
	puts("These features are available:"
#if ENABLE_FEATURE_VI_SEARCH
	"\n\tPattern searches with / and ?"
#endif
#if ENABLE_FEATURE_VI_DOT_CMD
	"\n\tLast command repeat with ."
#endif
#if ENABLE_FEATURE_VI_YANKMARK
	"\n\tLine marking with 'x"
	"\n\tNamed buffers with \"x"
#endif
#if ENABLE_FEATURE_VI_READONLY
	//not implemented: "\n\tReadonly if vi is called as \"view\""
	//redundant: usage text says this too: "\n\tReadonly with -R command line arg"
#endif
#if ENABLE_FEATURE_VI_SET
	"\n\tSome colon mode commands with :"
#endif
#if ENABLE_FEATURE_VI_SETOPTS
	"\n\tSettable options with \":set\""
#endif
#if ENABLE_FEATURE_VI_USE_SIGNALS
	"\n\tSignal catching- ^C"
	"\n\tJob suspend and resume with ^Z"
#endif
#if ENABLE_FEATURE_VI_WIN_RESIZE
	"\n\tAdapt to window re-sizes"
#endif
	);
}

static void write1(const char *out)
{
	fputs_stdout(out);
}

#if ENABLE_FEATURE_VI_WIN_RESIZE
static int query_screen_dimensions(void)
{
	int err = get_terminal_width_height(STDIN_FILENO, &amp;columns, &amp;rows);
	if (rows &gt; MAX_SCR_ROWS)
		rows = MAX_SCR_ROWS;
	if (columns &gt; MAX_SCR_COLS)
		columns = MAX_SCR_COLS;
	return err;
}
#else
static ALWAYS_INLINE int query_screen_dimensions(void)
{
	return 0;
}
#endif

// sleep for 'h' 1/100 seconds, return 1/0 if stdin is (ready for read)/(not ready)
static int mysleep(int hund)
{
	struct pollfd pfd[1];

	if (hund != 0)
		fflush_all();

	pfd[0].fd = STDIN_FILENO;
	pfd[0].events = POLLIN;
	return safe_poll(pfd, 1, hund*10) &gt; 0;
}

//----- Set terminal attributes --------------------------------
static void rawmode(void)
{
	// no TERMIOS_CLEAR_ISIG: leave ISIG on - allow signals
	set_termios_to_raw(STDIN_FILENO, &amp;term_orig, TERMIOS_RAW_CRNL);
}

static void cookmode(void)
{
	fflush_all();
	tcsetattr_stdin_TCSANOW(&amp;term_orig);
}

//----- Terminal Drawing ---------------------------------------
// The terminal is made up of 'rows' line of 'columns' columns.
// classically this would be 24 x 80.
//  screen coordinates
//  0,0     ...     0,79
//  1,0     ...     1,79
//  .       ...     .
//  .       ...     .
//  22,0    ...     22,79
//  23,0    ...     23,79   &lt;- status line

//----- Move the cursor to row x col (count from 0, not 1) -------
static void place_cursor(int row, int col)
{
	char cm1[sizeof(ESC_SET_CURSOR_POS) + sizeof(int)*3 * 2];

	if (row &lt; 0) row = 0;
	if (row &gt;= rows) row = rows - 1;
	if (col &lt; 0) col = 0;
	if (col &gt;= columns) col = columns - 1;

	sprintf(cm1, ESC_SET_CURSOR_POS, row + 1, col + 1);
	write1(cm1);
}

//----- Erase from cursor to end of line -----------------------
static void clear_to_eol(void)
{
	write1(ESC_CLEAR2EOL);
}

static void go_bottom_and_clear_to_eol(void)
{
	place_cursor(rows - 1, 0);
	clear_to_eol();
}

//----- Start standout mode ------------------------------------
static void standout_start(void)
{
	write1(ESC_BOLD_TEXT);
}

//----- End standout mode --------------------------------------
static void standout_end(void)
{
	write1(ESC_NORM_TEXT);
}

//----- Text Movement Routines ---------------------------------
static char *begin_line(char *p) // return pointer to first char cur line
{
	if (p &gt; text) {
		p = memrchr(text, '\n', p - text);
		if (!p)
			return text;
		return p + 1;
	}
	return p;
}

static char *end_line(char *p) // return pointer to NL of cur line
{
	if (p &lt; end - 1) {
		p = memchr(p, '\n', end - p - 1);
		if (!p)
			return end - 1;
	}
	return p;
}

static char *dollar_line(char *p) // return pointer to just before NL line
{
	p = end_line(p);
	// Try to stay off of the Newline
	if (*p == '\n' &amp;&amp; (p - begin_line(p)) &gt; 0)
		p--;
	return p;
}

static char *prev_line(char *p) // return pointer first char prev line
{
	p = begin_line(p);	// goto beginning of cur line
	if (p &gt; text &amp;&amp; p[-1] == '\n')
		p--;			// step to prev line
	p = begin_line(p);	// goto beginning of prev line
	return p;
}

static char *next_line(char *p) // return pointer first char next line
{
	p = end_line(p);
	if (p &lt; end - 1 &amp;&amp; *p == '\n')
		p++;			// step to next line
	return p;
}

//----- Text Information Routines ------------------------------
static char *end_screen(void)
{
	char *q;
	int cnt;

	// find new bottom line
	q = screenbegin;
	for (cnt = 0; cnt &lt; rows - 2; cnt++)
		q = next_line(q);
	q = end_line(q);
	return q;
}

// count line from start to stop
static int count_lines(char *start, char *stop)
{
	char *q;
	int cnt;

	if (stop &lt; start) { // start and stop are backwards- reverse them
		q = start;
		start = stop;
		stop = q;
	}
	cnt = 0;
	stop = end_line(stop);
	while (start &lt;= stop &amp;&amp; start &lt;= end - 1) {
		start = end_line(start);
		if (*start == '\n')
			cnt++;
		start++;
	}
	return cnt;
}

static char *find_line(int li)	// find beginning of line #li
{
	char *q;

	for (q = text; li &gt; 1; li--) {
		q = next_line(q);
	}
	return q;
}

static int next_tabstop(int col)
{
	return col + ((tabstop - 1) - (col % tabstop));
}

static int prev_tabstop(int col)
{
	return col - ((col % tabstop) ?: tabstop);
}

static int next_column(char c, int co)
{
	if (c == '\t')
		co = next_tabstop(co);
	else if ((unsigned char)c &lt; ' ' || c == 0x7f)
		co++; // display as ^X, use 2 columns
	return co + 1;
}

static int get_column(char *p)
{
	const char *r;
	int co = 0;

	for (r = begin_line(p); r &lt; p; r++)
		co = next_column(*r, co);
	return co;
}

//----- Erase the Screen[] memory ------------------------------
static void screen_erase(void)
{
	memset(screen, ' ', screensize);	// clear new screen
}

static void new_screen(int ro, int co)
{
	char *s;

	free(screen);
	screensize = ro * co + 8;
	s = screen = xmalloc(screensize);
	// initialize the new screen. assume this will be a empty file.
	screen_erase();
	// non-existent text[] lines start with a tilde (~).
	//screen[(1 * co) + 0] = '~';
	//screen[(2 * co) + 0] = '~';
	//..
	//screen[((ro-2) * co) + 0] = '~';
	ro -= 2;
	while (--ro &gt;= 0) {
		s += co;
		*s = '~';
	}
}

//----- Synchronize the cursor to Dot --------------------------
static void sync_cursor(char *d, int *row, int *col)
{
	char *beg_cur;	// begin and end of "d" line
	char *tp;
	int cnt, ro, co;

	beg_cur = begin_line(d);	// first char of cur line

	if (beg_cur &lt; screenbegin) {
		// "d" is before top line on screen
		// how many lines do we have to move
		cnt = count_lines(beg_cur, screenbegin);
 sc1:
		screenbegin = beg_cur;
		if (cnt &gt; (rows - 1) / 2) {
			// we moved too many lines. put "dot" in middle of screen
			for (cnt = 0; cnt &lt; (rows - 1) / 2; cnt++) {
				screenbegin = prev_line(screenbegin);
			}
		}
	} else {
		char *end_scr;	// begin and end of screen
		end_scr = end_screen();	// last char of screen
		if (beg_cur &gt; end_scr) {
			// "d" is after bottom line on screen
			// how many lines do we have to move
			cnt = count_lines(end_scr, beg_cur);
			if (cnt &gt; (rows - 1) / 2)
				goto sc1;	// too many lines
			for (ro = 0; ro &lt; cnt - 1; ro++) {
				// move screen begin the same amount
				screenbegin = next_line(screenbegin);
				// now, move the end of screen
				end_scr = next_line(end_scr);
				end_scr = end_line(end_scr);
			}
		}
	}
	// "d" is on screen- find out which row
	tp = screenbegin;
	for (ro = 0; ro &lt; rows - 1; ro++) {	// drive "ro" to correct row
		if (tp == beg_cur)
			break;
		tp = next_line(tp);
	}

	// find out what col "d" is on
	co = 0;
	do { // drive "co" to correct column
		if (*tp == '\n') //vda || *tp == '\0')
			break;
		co = next_column(*tp, co) - 1;
		// inserting text before a tab, don't include its position
		if (cmd_mode &amp;&amp; tp == d - 1 &amp;&amp; *d == '\t') {
			co++;
			break;
		}
	} while (tp++ &lt; d &amp;&amp; ++co);

	// "co" is the column where "dot" is.
	// The screen has "columns" columns.
	// The currently displayed columns are  0+offset -- columns+ofset
	// |-------------------------------------------------------------|
	//               ^ ^                                ^
	//        offset | |------- columns ----------------|
	//
	// If "co" is already in this range then we do not have to adjust offset
	//      but, we do have to subtract the "offset" bias from "co".
	// If "co" is outside this range then we have to change "offset".
	// If the first char of a line is a tab the cursor will try to stay
	//  in column 7, but we have to set offset to 0.

	if (co &lt; 0 + offset) {
		offset = co;
	}
	if (co &gt;= columns + offset) {
		offset = co - columns + 1;
	}
	// if the first char of the line is a tab, and "dot" is sitting on it
	//  force offset to 0.
	if (d == beg_cur &amp;&amp; *d == '\t') {
		offset = 0;
	}
	co -= offset;

	*row = ro;
	*col = co;
}

//----- Format a text[] line into a buffer ---------------------
static char* format_line(char *src /*, int li*/)
{
	unsigned char c;
	int co;
	int ofs = offset;
	char *dest = scr_out_buf; // [MAX_SCR_COLS + MAX_TABSTOP * 2]

	c = '~'; // char in col 0 in non-existent lines is '~'
	co = 0;
	while (co &lt; columns + tabstop) {
		// have we gone past the end?
		if (src &lt; end) {
			c = *src++;
			if (c == '\n')
				break;
			if ((c &amp; 0x80) &amp;&amp; !Isprint(c)) {
				c = '.';
			}
			if (c &lt; ' ' || c == 0x7f) {
				if (c == '\t') {
					c = ' ';
					//      co %    8     !=     7
					while ((co % tabstop) != (tabstop - 1)) {
						dest[co++] = c;
					}
				} else {
					dest[co++] = '^';
					if (c == 0x7f)
						c = '?';
					else
						c += '@'; // Ctrl-X -&gt; 'X'
				}
			}
		}
		dest[co++] = c;
		// discard scrolled-off-to-the-left portion,
		// in tabstop-sized pieces
		if (ofs &gt;= tabstop &amp;&amp; co &gt;= tabstop) {
			memmove(dest, dest + tabstop, co);
			co -= tabstop;
			ofs -= tabstop;
		}
		if (src &gt;= end)
			break;
	}
	// check "short line, gigantic offset" case
	if (co &lt; ofs)
		ofs = co;
	// discard last scrolled off part
	co -= ofs;
	dest += ofs;
	// fill the rest with spaces
	if (co &lt; columns)
		memset(&amp;dest[co], ' ', columns - co);
	return dest;
}

//----- Refresh the changed screen lines -----------------------
// Copy the source line from text[] into the buffer and note
// if the current screenline is different from the new buffer.
// If they differ then that line needs redrawing on the terminal.
//
static void refresh(int full_screen)
{
#define old_offset refresh__old_offset

	int li, changed;
	char *tp, *sp;		// pointer into text[] and screen[]

	if (ENABLE_FEATURE_VI_WIN_RESIZE IF_FEATURE_VI_ASK_TERMINAL(&amp;&amp; !G.get_rowcol_error) ) {
		unsigned c = columns, r = rows;
		query_screen_dimensions();
#if ENABLE_FEATURE_VI_USE_SIGNALS
		full_screen |= (c - columns) | (r - rows);
#else
		if (c != columns || r != rows) {
			full_screen = TRUE;
			// update screen memory since SIGWINCH won't have done it
			new_screen(rows, columns);
		}
#endif
	}
	sync_cursor(dot, &amp;crow, &amp;ccol);	// where cursor will be (on "dot")
	tp = screenbegin;	// index into text[] of top line

	// compare text[] to screen[] and mark screen[] lines that need updating
	for (li = 0; li &lt; rows - 1; li++) {
		int cs, ce;				// column start &amp; end
		char *out_buf;
		// format current text line
		out_buf = format_line(tp /*, li*/);

		// skip to the end of the current text[] line
		if (tp &lt; end) {
			char *t = memchr(tp, '\n', end - tp);
			if (!t) t = end - 1;
			tp = t + 1;
		}

		// see if there are any changes between virtual screen and out_buf
		changed = FALSE;	// assume no change
		cs = 0;
		ce = columns - 1;
		sp = &amp;screen[li * columns];	// start of screen line
		if (full_screen) {
			// force re-draw of every single column from 0 - columns-1
			goto re0;
		}
		// compare newly formatted buffer with virtual screen
		// look forward for first difference between buf and screen
		for (; cs &lt;= ce; cs++) {
			if (out_buf[cs] != sp[cs]) {
				changed = TRUE;	// mark for redraw
				break;
			}
		}

		// look backward for last difference between out_buf and screen
		for (; ce &gt;= cs; ce--) {
			if (out_buf[ce] != sp[ce]) {
				changed = TRUE;	// mark for redraw
				break;
			}
		}
		// now, cs is index of first diff, and ce is index of last diff

		// if horz offset has changed, force a redraw
		if (offset != old_offset) {
 re0:
			changed = TRUE;
		}

		// make a sanity check of columns indexes
		if (cs &lt; 0) cs = 0;
		if (ce &gt; columns - 1) ce = columns - 1;
		if (cs &gt; ce) { cs = 0; ce = columns - 1; }
		// is there a change between virtual screen and out_buf
		if (changed) {
			// copy changed part of buffer to virtual screen
			memcpy(sp+cs, out_buf+cs, ce-cs+1);
			place_cursor(li, cs);
			// write line out to terminal
			fwrite(&amp;sp[cs], ce - cs + 1, 1, stdout);
		}
	}

	place_cursor(crow, ccol);

	if (!keep_index)
		cindex = ccol + offset;

	old_offset = offset;
#undef old_offset
}

//----- Force refresh of all Lines -----------------------------
static void redraw(int full_screen)
{
	// cursor to top,left; clear to the end of screen
	write1(ESC_SET_CURSOR_TOPLEFT ESC_CLEAR2EOS);
	screen_erase();		// erase the internal screen buffer
	last_status_cksum = 0;	// force status update
	refresh(full_screen);	// this will redraw the entire display
	show_status_line();
}

//----- Flash the screen  --------------------------------------
static void flash(int h)
{
	standout_start();
	redraw(TRUE);
	mysleep(h);
	standout_end();
	redraw(TRUE);
}

static void indicate_error(void)
{
#if ENABLE_FEATURE_VI_CRASHME
	if (crashme &gt; 0)
		return;
#endif
	cmd_error = TRUE;
	if (!err_method) {
		write1(ESC_BELL);
	} else {
		flash(10);
	}
}

//----- IO Routines --------------------------------------------
static int readit(void) // read (maybe cursor) key from stdin
{
	int c;

	fflush_all();

	// Wait for input. TIMEOUT = -1 makes read_key wait even
	// on nonblocking stdin.
	// Note: read_key sets errno to 0 on success.
 again:
	c = safe_read_key(STDIN_FILENO, readbuffer, /*timeout:*/ -1);
	if (c == -1) { // EOF/error
		if (errno == EAGAIN) // paranoia
			goto again;
		go_bottom_and_clear_to_eol();
		cookmode(); // terminal to "cooked"
		bb_simple_error_msg_and_die("can't read user input");
	}
	return c;
}

#if ENABLE_FEATURE_VI_DOT_CMD
static int get_one_char(void)
{
	int c;

	if (!adding2q) {
		// we are not adding to the q.
		// but, we may be reading from a saved q.
		// (checking "ioq" for NULL is wrong, it's not reset to NULL
		// when done - "ioq_start" is reset instead).
		if (ioq_start != NULL) {
			// there is a queue to get chars from.
			// careful with correct sign expansion!
			c = (unsigned char)*ioq++;
			if (c != '\0')
				return c;
			// the end of the q
			free(ioq_start);
			ioq_start = NULL;
			// read from STDIN:
		}
		return readit();
	}
	// we are adding STDIN chars to q.
	c = readit();
	if (lmc_len &gt;= ARRAY_SIZE(last_modifying_cmd) - 2) {
		// last_modifying_cmd[] is too small, can't remember the cmd
		// - drop it
		adding2q = 0;
		lmc_len = 0;
	} else {
		last_modifying_cmd[lmc_len++] = c;
	}
	return c;
}
#else
# define get_one_char() readit()
#endif

// Get type of thing to operate on and adjust count
static int get_motion_char(void)
{
	int c, cnt;

	c = get_one_char();
	if (isdigit(c)) {
		if (c != '0') {
			// get any non-zero motion count
			for (cnt = 0; isdigit(c); c = get_one_char())
				cnt = cnt * 10 + (c - '0');
			cmdcnt = (cmdcnt ?: 1) * cnt;
		} else {
			// ensure standalone '0' works
			cmdcnt = 0;
		}
	}

	return c;
}

// Get input line (uses "status line" area)
static char *get_input_line(const char *prompt)
{
	// char [MAX_INPUT_LEN]
#define buf get_input_line__buf

	int c;
	int i;

	strcpy(buf, prompt);
	last_status_cksum = 0;	// force status update
	go_bottom_and_clear_to_eol();
	write1(buf);      // write out the :, /, or ? prompt

	i = strlen(buf);
	while (i &lt; MAX_INPUT_LEN - 1) {
		c = get_one_char();
		if (c == '\n' || c == '\r' || c == 27)
			break;		// this is end of input
		if (isbackspace(c)) {
			// user wants to erase prev char
			buf[--i] = '\0';
			go_bottom_and_clear_to_eol();
			if (i &lt;= 0) // user backs up before b-o-l, exit
				break;
			write1(buf);
		} else if (c &gt; 0 &amp;&amp; c &lt; 256) { // exclude Unicode
			// (TODO: need to handle Unicode)
			buf[i] = c;
			buf[++i] = '\0';
			bb_putchar(c);
		}
	}
	refresh(FALSE);
	return buf;
#undef buf
}

static void Hit_Return(void)
{
	int c;

	standout_start();
	write1("[Hit return to continue]");
	standout_end();
	while ((c = get_one_char()) != '\n' &amp;&amp; c != '\r')
		continue;
	redraw(TRUE);		// force redraw all
}

//----- Draw the status line at bottom of the screen -------------
// show file status on status line
static int format_edit_status(void)
{
	static const char cmd_mode_indicator[] ALIGN1 = "-IR-";

#define tot format_edit_status__tot

	int cur, percent, ret, trunc_at;

	// modified_count is now a counter rather than a flag.  this
	// helps reduce the amount of line counting we need to do.
	// (this will cause a mis-reporting of modified status
	// once every MAXINT editing operations.)

	// it would be nice to do a similar optimization here -- if
	// we haven't done a motion that could have changed which line
	// we're on, then we shouldn't have to do this count_lines()
	cur = count_lines(text, dot);

	// count_lines() is expensive.
	// Call it only if something was changed since last time
	// we were here:
	if (modified_count != last_modified_count) {
		tot = cur + count_lines(dot, end - 1) - 1;
		last_modified_count = modified_count;
	}

	//    current line         percent
	//   -------------    ~~ ----------
	//    total lines            100
	if (tot &gt; 0) {
		percent = (100 * cur) / tot;
	} else {
		cur = tot = 0;
		percent = 100;
	}

	trunc_at = columns &lt; STATUS_BUFFER_LEN-1 ?
		columns : STATUS_BUFFER_LEN-1;

	ret = snprintf(status_buffer, trunc_at+1,
#if ENABLE_FEATURE_VI_READONLY
		"%c %s%s%s %d/%d %d%%",
#else
		"%c %s%s %d/%d %d%%",
#endif
		cmd_mode_indicator[cmd_mode &amp; 3],
		(current_filename != NULL ? current_filename : "No file"),
#if ENABLE_FEATURE_VI_READONLY
		(readonly_mode ? " [Readonly]" : ""),
#endif
		(modified_count ? " [Modified]" : ""),
		cur, tot, percent);

	if (ret &gt;= 0 &amp;&amp; ret &lt; trunc_at)
		return ret;  // it all fit

	return trunc_at;  // had to truncate
#undef tot
}

static int bufsum(char *buf, int count)
{
	int sum = 0;
	char *e = buf + count;
	while (buf &lt; e)
		sum += (unsigned char) *buf++;
	return sum;
}

static void show_status_line(void)
{
	int cnt = 0, cksum = 0;

	// either we already have an error or status message, or we
	// create one.
	if (!have_status_msg) {
		cnt = format_edit_status();
		cksum = bufsum(status_buffer, cnt);
	}
	if (have_status_msg || ((cnt &gt; 0 &amp;&amp; last_status_cksum != cksum))) {
		last_status_cksum = cksum;		// remember if we have seen this line
		go_bottom_and_clear_to_eol();
		write1(status_buffer);
		if (have_status_msg) {
			if (((int)strlen(status_buffer) - (have_status_msg - 1)) &gt;
					(columns - 1) ) {
				have_status_msg = 0;
				Hit_Return();
			}
			have_status_msg = 0;
		}
		place_cursor(crow, ccol);  // put cursor back in correct place
	}
	fflush_all();
}

//----- format the status buffer, the bottom line of screen ------
static void status_line(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vsnprintf(status_buffer, STATUS_BUFFER_LEN, format, args);
	va_end(args);

	have_status_msg = 1;
}
static void status_line_bold(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	strcpy(status_buffer, ESC_BOLD_TEXT);
	vsnprintf(status_buffer + (sizeof(ESC_BOLD_TEXT)-1),
		STATUS_BUFFER_LEN - sizeof(ESC_BOLD_TEXT) - sizeof(ESC_NORM_TEXT),
		format, args
	);
	strcat(status_buffer, ESC_NORM_TEXT);
	va_end(args);

	have_status_msg = 1 + (sizeof(ESC_BOLD_TEXT)-1) + (sizeof(ESC_NORM_TEXT)-1);
}
static void status_line_bold_errno(const char *fn)
{
	status_line_bold("'%s' "STRERROR_FMT, fn STRERROR_ERRNO);
}

// copy s to buf, convert unprintable
static void print_literal(char *buf, const char *s)
{
	char *d;
	unsigned char c;

	if (!s[0])
		s = "(NULL)";

	d = buf;
	for (; *s; s++) {
		c = *s;
		if ((c &amp; 0x80) &amp;&amp; !Isprint(c))
			c = '?';
		if (c &lt; ' ' || c == 0x7f) {
			*d++ = '^';
			c |= '@'; // 0x40
			if (c == 0x7f)
				c = '?';
		}
		*d++ = c;
		*d = '\0';
		if (d - buf &gt; MAX_INPUT_LEN - 10) // paranoia
			break;
	}
}
static void not_implemented(const char *s)
{
	char buf[MAX_INPUT_LEN];
	print_literal(buf, s);
	status_line_bold("'%s' is not implemented", buf);
}

//----- Block insert/delete, undo ops --------------------------
#if ENABLE_FEATURE_VI_YANKMARK
// copy text into a register
static char *text_yank(char *p, char *q, int dest, int buftype)
{
	char *oldreg = reg[dest];
	int cnt = q - p;
	if (cnt &lt; 0) {		// they are backwards- reverse them
		p = q;
		cnt = -cnt;
	}
	// Don't free register yet.  This prevents the memory allocator
	// from reusing the free block so we can detect if it's changed.
	reg[dest] = xstrndup(p, cnt + 1);
	regtype[dest] = buftype;
	free(oldreg);
	return p;
}

static char what_reg(void)
{
	char c;

	c = 'D';			// default to D-reg
	if (YDreg &lt;= 25)
		c = 'a' + (char) YDreg;
	if (YDreg == 26)
		c = 'D';
	if (YDreg == 27)
		c = 'U';
	return c;
}

static void check_context(char cmd)
{
	// Certain movement commands update the context.
	if (strchr(":%{}'GHLMz/?Nn", cmd) != NULL) {
		mark[27] = mark[26];	// move cur to prev
		mark[26] = dot;	// move local to cur
	}
}

static char *swap_context(char *p) // goto new context for '' command make this the current context
{
	char *tmp;

	// the current context is in mark[26]
	// the previous context is in mark[27]
	// only swap context if other context is valid
	if (text &lt;= mark[27] &amp;&amp; mark[27] &lt;= end - 1) {
		tmp = mark[27];
		mark[27] = p;
		mark[26] = p = tmp;
	}
	return p;
}

# if ENABLE_FEATURE_VI_VERBOSE_STATUS
static void yank_status(const char *op, const char *p, int cnt)
{
	int lines, chars;

	lines = chars = 0;
	while (*p) {
		++chars;
		if (*p++ == '\n')
			++lines;
	}
	status_line("%s %d lines (%d chars) from [%c]",
				op, lines * cnt, chars * cnt, what_reg());
}
# endif
#endif /* FEATURE_VI_YANKMARK */

#if ENABLE_FEATURE_VI_UNDO
static void undo_push(char *, unsigned, int);
#endif

// open a hole in text[]
// might reallocate text[]! use p += text_hole_make(p, ...),
// and be careful to not use pointers into potentially freed text[]!
static uintptr_t text_hole_make(char *p, int size)	// at "p", make a 'size' byte hole
{
	uintptr_t bias = 0;

	if (size &lt;= 0)
		return bias;
	end += size;		// adjust the new END
	if (end &gt;= (text + text_size)) {
		char *new_text;
		text_size += end - (text + text_size) + 10240;
		new_text = xrealloc(text, text_size);
		bias = (new_text - text);
		screenbegin += bias;
		dot         += bias;
		end         += bias;
		p           += bias;
#if ENABLE_FEATURE_VI_YANKMARK
		{
			int i;
			for (i = 0; i &lt; ARRAY_SIZE(mark); i++)
				if (mark[i])
					mark[i] += bias;
		}
#endif
		text = new_text;
	}
	memmove(p + size, p, end - size - p);
	memset(p, ' ', size);	// clear new hole
	return bias;
}

// close a hole in text[] - delete "p" through "q", inclusive
// "undo" value indicates if this operation should be undo-able
#if !ENABLE_FEATURE_VI_UNDO
#define text_hole_delete(a,b,c) text_hole_delete(a,b)
#endif
static char *text_hole_delete(char *p, char *q, int undo)
{
	char *src, *dest;
	int cnt, hole_size;

	// move forwards, from beginning
	// assume p &lt;= q
	src = q + 1;
	dest = p;
	if (q &lt; p) {		// they are backward- swap them
		src = p + 1;
		dest = q;
	}
	hole_size = q - p + 1;
	cnt = end - src;
#if ENABLE_FEATURE_VI_UNDO
	switch (undo) {
		case NO_UNDO:
			break;
		case ALLOW_UNDO:
			undo_push(p, hole_size, UNDO_DEL);
			break;
		case ALLOW_UNDO_CHAIN:
			undo_push(p, hole_size, UNDO_DEL_CHAIN);
			break;
# if ENABLE_FEATURE_VI_UNDO_QUEUE
		case ALLOW_UNDO_QUEUED:
			undo_push(p, hole_size, UNDO_DEL_QUEUED);
			break;
# endif
	}
	modified_count--;
#endif
	if (src &lt; text || src &gt; end)
		goto thd0;
	if (dest &lt; text || dest &gt;= end)
		goto thd0;
	modified_count++;
	if (src &gt;= end)
		goto thd_atend;	// just delete the end of the buffer
	memmove(dest, src, cnt);
 thd_atend:
	end = end - hole_size;	// adjust the new END
	if (dest &gt;= end)
		dest = end - 1;	// make sure dest in below end-1
	if (end &lt;= text)
		dest = end = text;	// keep pointers valid
 thd0:
	return dest;
}

#if ENABLE_FEATURE_VI_UNDO

# if ENABLE_FEATURE_VI_UNDO_QUEUE
// Flush any queued objects to the undo stack
static void undo_queue_commit(void)
{
	// Pushes the queue object onto the undo stack
	if (undo_q &gt; 0) {
		// Deleted character undo events grow from the end
		undo_push(undo_queue + CONFIG_FEATURE_VI_UNDO_QUEUE_MAX - undo_q,
			undo_q,
			(undo_queue_state | UNDO_USE_SPOS)
		);
		undo_queue_state = UNDO_EMPTY;
		undo_q = 0;
	}
}
# else
#  define undo_queue_commit() ((void)0)
# endif

static void flush_undo_data(void)
{
	struct undo_object *undo_entry;

	while (undo_stack_tail) {
		undo_entry = undo_stack_tail;
		undo_stack_tail = undo_entry-&gt;prev;
		free(undo_entry);
	}
}

// Undo functions and hooks added by Jody Bruchon (jody@jodybruchon.com)
// Add to the undo stack
static void undo_push(char *src, unsigned length, int u_type)
{
	struct undo_object *undo_entry;
# if ENABLE_FEATURE_VI_UNDO_QUEUE
	int use_spos = u_type &amp; UNDO_USE_SPOS;
# endif

	// "u_type" values
	// UNDO_INS: insertion, undo will remove from buffer
	// UNDO_DEL: deleted text, undo will restore to buffer
	// UNDO_{INS,DEL}_CHAIN: Same as above but also calls undo_pop() when complete
	// The CHAIN operations are for handling multiple operations that the user
	// performs with a single action, i.e. REPLACE mode or find-and-replace commands
	// UNDO_{INS,DEL}_QUEUED: If queuing feature is enabled, allow use of the queue
	// for the INS/DEL operation.
	// UNDO_{INS,DEL} ORed with UNDO_USE_SPOS: commit the undo queue

# if ENABLE_FEATURE_VI_UNDO_QUEUE
	// This undo queuing functionality groups multiple character typing or backspaces
	// into a single large undo object. This greatly reduces calls to malloc() for
	// single-character operations while typing and has the side benefit of letting
	// an undo operation remove chunks of text rather than a single character.
	switch (u_type) {
	case UNDO_EMPTY:	// Just in case this ever happens...
		return;
	case UNDO_DEL_QUEUED:
		if (length != 1)
			return;	// Only queue single characters
		switch (undo_queue_state) {
		case UNDO_EMPTY:
			undo_queue_state = UNDO_DEL;
		case UNDO_DEL:
			undo_queue_spos = src;
			undo_q++;
			undo_queue[CONFIG_FEATURE_VI_UNDO_QUEUE_MAX - undo_q] = *src;
			// If queue is full, dump it into an object
			if (undo_q == CONFIG_FEATURE_VI_UNDO_QUEUE_MAX)
				undo_queue_commit();
			return;
		case UNDO_INS:
			// Switch from storing inserted text to deleted text
			undo_queue_commit();
			undo_push(src, length, UNDO_DEL_QUEUED);
			return;
		}
		break;
	case UNDO_INS_QUEUED:
		if (length &lt; 1)
			return;
		switch (undo_queue_state) {
		case UNDO_EMPTY:
			undo_queue_state = UNDO_INS;
			undo_queue_spos = src;
		case UNDO_INS:
			while (length--) {
				undo_q++;	// Don't need to save any data for insertions
				if (undo_q == CONFIG_FEATURE_VI_UNDO_QUEUE_MAX)
					undo_queue_commit();
			}
			return;
		case UNDO_DEL:
			// Switch from storing deleted text to inserted text
			undo_queue_commit();
			undo_push(src, length, UNDO_INS_QUEUED);
			return;
		}
		break;
	}
	u_type &amp;= ~UNDO_USE_SPOS;
# endif

	// Allocate a new undo object
	if (u_type == UNDO_DEL || u_type == UNDO_DEL_CHAIN) {
		// For UNDO_DEL objects, save deleted text
		if ((text + length) == end)
			length--;
		// If this deletion empties text[], strip the newline. When the buffer becomes
		// zero-length, a newline is added back, which requires this to compensate.
		undo_entry = xzalloc(offsetof(struct undo_object, undo_text) + length);
		memcpy(undo_entry-&gt;undo_text, src, length);
	} else {
		undo_entry = xzalloc(sizeof(*undo_entry));
	}
	undo_entry-&gt;length = length;
# if ENABLE_FEATURE_VI_UNDO_QUEUE
	if (use_spos) {
		undo_entry-&gt;start = undo_queue_spos - text;	// use start position from queue
	} else {
		undo_entry-&gt;start = src - text;	// use offset from start of text buffer
	}
# else
	undo_entry-&gt;start = src - text;
# endif
	undo_entry-&gt;u_type = u_type;

	// Push it on undo stack
	undo_entry-&gt;prev = undo_stack_tail;
	undo_stack_tail = undo_entry;
	modified_count++;
}

static void undo_push_insert(char *p, int len, int undo)
{
	switch (undo) {
	case ALLOW_UNDO:
		undo_push(p, len, UNDO_INS);
		break;
	case ALLOW_UNDO_CHAIN:
		undo_push(p, len, UNDO_INS_CHAIN);
		break;
# if ENABLE_FEATURE_VI_UNDO_QUEUE
	case ALLOW_UNDO_QUEUED:
		undo_push(p, len, UNDO_INS_QUEUED);
		break;
# endif
	}
}

// Undo the last operation
static void undo_pop(void)
{
	int repeat;
	char *u_start, *u_end;
	struct undo_object *undo_entry;

	// Commit pending undo queue before popping (should be unnecessary)
	undo_queue_commit();

	undo_entry = undo_stack_tail;
	// Check for an empty undo stack
	if (!undo_entry) {
		status_line("Already at oldest change");
		return;
	}

	switch (undo_entry-&gt;u_type) {
	case UNDO_DEL:
	case UNDO_DEL_CHAIN:
		// make hole and put in text that was deleted; deallocate text
		u_start = text + undo_entry-&gt;start;
		text_hole_make(u_start, undo_entry-&gt;length);
		memcpy(u_start, undo_entry-&gt;undo_text, undo_entry-&gt;length);
# if ENABLE_FEATURE_VI_VERBOSE_STATUS
		status_line("Undo [%d] %s %d chars at position %d",
			modified_count, "restored",
			undo_entry-&gt;length, undo_entry-&gt;start
		);
# endif
		break;
	case UNDO_INS:
	case UNDO_INS_CHAIN:
		// delete what was inserted
		u_start = undo_entry-&gt;start + text;
		u_end = u_start - 1 + undo_entry-&gt;length;
		text_hole_delete(u_start, u_end, NO_UNDO);
# if ENABLE_FEATURE_VI_VERBOSE_STATUS
		status_line("Undo [%d] %s %d chars at position %d",
			modified_count, "deleted",
			undo_entry-&gt;length, undo_entry-&gt;start
		);
# endif
		break;
	}
	repeat = 0;
	switch (undo_entry-&gt;u_type) {
	// If this is the end of a chain, lower modification count and refresh display
	case UNDO_DEL:
	case UNDO_INS:
		dot = (text + undo_entry-&gt;start);
		refresh(FALSE);
		break;
	case UNDO_DEL_CHAIN:
	case UNDO_INS_CHAIN:
		repeat = 1;
		break;
	}
	// Deallocate the undo object we just processed
	undo_stack_tail = undo_entry-&gt;prev;
	free(undo_entry);
	modified_count--;
	// For chained operations, continue popping all the way down the chain.
	if (repeat) {
		undo_pop();	// Follow the undo chain if one exists
	}
}

#else
# define flush_undo_data()   ((void)0)
# define undo_queue_commit() ((void)0)
#endif /* ENABLE_FEATURE_VI_UNDO */

//----- Dot Movement Routines ----------------------------------
static void dot_left(void)
{
	undo_queue_commit();
	if (dot &gt; text &amp;&amp; dot[-1] != '\n')
		dot--;
}

static void dot_right(void)
{
	undo_queue_commit();
	if (dot &lt; end - 1 &amp;&amp; *dot != '\n')
		dot++;
}

static void dot_begin(void)
{
	undo_queue_commit();
	dot = begin_line(dot);	// return pointer to first char cur line
}

static void dot_end(void)
{
	undo_queue_commit();
	dot = end_line(dot);	// return pointer to last char cur line
}

static char *move_to_col(char *p, int l)
{
	int co;

	p = begin_line(p);
	co = 0;
	do {
		if (*p == '\n') //vda || *p == '\0')
			break;
		co = next_column(*p, co);
	} while (co &lt;= l &amp;&amp; p++ &lt; end);
	return p;
}

static void dot_next(void)
{
	undo_queue_commit();
	dot = next_line(dot);
}

static void dot_prev(void)
{
	undo_queue_commit();
	dot = prev_line(dot);
}

static void dot_skip_over_ws(void)
{
	// skip WS
	while (isspace(*dot) &amp;&amp; *dot != '\n' &amp;&amp; dot &lt; end - 1)
		dot++;
}

static void dot_to_char(int cmd)
{
	char *q = dot;
	int dir = islower(cmd) ? FORWARD : BACK;

	if (last_search_char == 0)
		return;

	do {
		do {
			q += dir;
			if ((dir == FORWARD ? q &gt; end - 1 : q &lt; text) || *q == '\n') {
				indicate_error();
				return;
			}
		} while (*q != last_search_char);
	} while (--cmdcnt &gt; 0);

	dot = q;

	// place cursor before/after char as required
	if (cmd == 't')
		dot_left();
	else if (cmd == 'T')
		dot_right();
}

static void dot_scroll(int cnt, int dir)
{
	char *q;

	undo_queue_commit();
	for (; cnt &gt; 0; cnt--) {
		if (dir &lt; 0) {
			// scroll Backwards
			// ctrl-Y scroll up one line
			screenbegin = prev_line(screenbegin);
		} else {
			// scroll Forwards
			// ctrl-E scroll down one line
			screenbegin = next_line(screenbegin);
		}
	}
	// make sure "dot" stays on the screen so we dont scroll off
	if (dot &lt; screenbegin)
		dot = screenbegin;
	q = end_screen();	// find new bottom line
	if (dot &gt; q)
		dot = begin_line(q);	// is dot is below bottom line?
	dot_skip_over_ws();
}

static char *bound_dot(char *p) // make sure  text[0] &lt;= P &lt; "end"
{
	if (p &gt;= end &amp;&amp; end &gt; text) {
		p = end - 1;
		indicate_error();
	}
	if (p &lt; text) {
		p = text;
		indicate_error();
	}
	return p;
}

#if ENABLE_FEATURE_VI_DOT_CMD
static void start_new_cmd_q(char c)
{
	// get buffer for new cmd
	dotcnt = cmdcnt ?: 1;
	last_modifying_cmd[0] = c;
	lmc_len = 1;
	adding2q = 1;
}
static void end_cmd_q(void)
{
# if ENABLE_FEATURE_VI_YANKMARK
	YDreg = 26;			// go back to default Yank/Delete reg
# endif
	adding2q = 0;
}
#else
# define end_cmd_q() ((void)0)
#endif /* FEATURE_VI_DOT_CMD */

// copy text into register, then delete text.
//
#if !ENABLE_FEATURE_VI_UNDO
#define yank_delete(a,b,c,d,e) yank_delete(a,b,c,d)
#endif
static char *yank_delete(char *start, char *stop, int buftype, int yf, int undo)
{
	char *p;

	// make sure start &lt;= stop
	if (start &gt; stop) {
		// they are backwards, reverse them
		p = start;
		start = stop;
		stop = p;
	}
	if (buftype == PARTIAL &amp;&amp; *start == '\n')
		return start;
	p = start;
#if ENABLE_FEATURE_VI_YANKMARK
	text_yank(start, stop, YDreg, buftype);
#endif
	if (yf == YANKDEL) {
		p = text_hole_delete(start, stop, undo);
	}					// delete lines
	return p;
}

// might reallocate text[]!
static int file_insert(const char *fn, char *p, int initial)
{
	int cnt = -1;
	int fd, size;
	struct stat statbuf;

	if (p &lt; text)
		p = text;
	if (p &gt; end)
		p = end;

	fd = open(fn, O_RDONLY);
	if (fd &lt; 0) {
		if (!initial)
			status_line_bold_errno(fn);
		return cnt;
	}

	// Validate file
	if (fstat(fd, &amp;statbuf) &lt; 0) {
		status_line_bold_errno(fn);
		goto fi;
	}
	if (!S_ISREG(statbuf.st_mode)) {
		status_line_bold("'%s' is not a regular file", fn);
		goto fi;
	}
	size = (statbuf.st_size &lt; INT_MAX ? (int)statbuf.st_size : INT_MAX);
	p += text_hole_make(p, size);
	cnt = full_read(fd, p, size);
	if (cnt &lt; 0) {
		status_line_bold_errno(fn);
		p = text_hole_delete(p, p + size - 1, NO_UNDO);	// un-do buffer insert
	} else if (cnt &lt; size) {
		// There was a partial read, shrink unused space
		p = text_hole_delete(p + cnt, p + size - 1, NO_UNDO);
		status_line_bold("can't read '%s'", fn);
	}
# if ENABLE_FEATURE_VI_UNDO
	else {
		undo_push_insert(p, size, ALLOW_UNDO);
	}
# endif
 fi:
	close(fd);

#if ENABLE_FEATURE_VI_READONLY
	if (initial
	 &amp;&amp; ((access(fn, W_OK) &lt; 0) ||
		// root will always have access()
		// so we check fileperms too
		!(statbuf.st_mode &amp; (S_IWUSR | S_IWGRP | S_IWOTH))
	    )
	) {
		SET_READONLY_FILE(readonly_mode);
	}
#endif
	return cnt;
}

// find matching char of pair  ()  []  {}
// will crash if c is not one of these
static char *find_pair(char *p, const char c)
{
	const char *braces = "()[]{}";
	char match;
	int dir, level;

	dir = strchr(braces, c) - braces;
	dir ^= 1;
	match = braces[dir];
	dir = ((dir &amp; 1) &lt;&lt; 1) - 1; // 1 for ([{, -1 for )\}

	// look for match, count levels of pairs  (( ))
	level = 1;
	for (;;) {
		p += dir;
		if (p &lt; text || p &gt;= end)
			return NULL;
		if (*p == c)
			level++;	// increase pair levels
		if (*p == match) {
			level--;	// reduce pair level
			if (level == 0)
				return p; // found matching pair
		}
	}
}

#if ENABLE_FEATURE_VI_SETOPTS
// show the matching char of a pair,  ()  []  {}
static void showmatching(char *p)
{
	char *q, *save_dot;

	// we found half of a pair
	q = find_pair(p, *p);	// get loc of matching char
	if (q == NULL) {
		indicate_error();	// no matching char
	} else {
		// "q" now points to matching pair
		save_dot = dot;	// remember where we are
		dot = q;		// go to new loc
		refresh(FALSE);	// let the user see it
		mysleep(40);	// give user some time
		dot = save_dot;	// go back to old loc
		refresh(FALSE);
	}
}
#endif /* FEATURE_VI_SETOPTS */

// might reallocate text[]! use p += stupid_insert(p, ...),
// and be careful to not use pointers into potentially freed text[]!
static uintptr_t stupid_insert(char *p, char c) // stupidly insert the char c at 'p'
{
	uintptr_t bias;
	bias = text_hole_make(p, 1);
	p += bias;
	*p = c;
	return bias;
}

// find number of characters in indent, p must be at beginning of line
static size_t indent_len(char *p)
{
	char *r = p;

	while (r &lt; (end - 1) &amp;&amp; isblank(*r))
		r++;
	return r - p;
}

#if !ENABLE_FEATURE_VI_UNDO
#define char_insert(a,b,c) char_insert(a,b)
#endif
static char *char_insert(char *p, char c, int undo) // insert the char c at 'p'
{
#if ENABLE_FEATURE_VI_SETOPTS
# define indentcol char_insert__indentcol
	size_t len;
	int col, ntab, nspc;
#endif
	char *bol = begin_line(p);

	if (c == 22) {		// Is this an ctrl-V?
		p += stupid_insert(p, '^');	// use ^ to indicate literal next
		refresh(FALSE);	// show the ^
		c = get_one_char();
		*p = c;
#if ENABLE_FEATURE_VI_UNDO
		undo_push_insert(p, 1, undo);
#else
		modified_count++;
#endif
		p++;
	} else if (c == 27) {	// Is this an ESC?
		cmd_mode = 0;
		undo_queue_commit();
		cmdcnt = 0;
		end_cmd_q();	// stop adding to q
		last_status_cksum = 0;	// force status update
		if ((dot &gt; text) &amp;&amp; (p[-1] != '\n')) {
			p--;
		}
#if ENABLE_FEATURE_VI_SETOPTS
		if (autoindent) {
			len = indent_len(bol);
			col = get_column(bol + len);
			if (len &amp;&amp; col == indentcol &amp;&amp; bol[len] == '\n') {
				// remove autoindent from otherwise empty line
				text_hole_delete(bol, bol + len - 1, undo);
				p = bol;
			}
		}
#endif
	} else if (c == 4) {	// ctrl-D reduces indentation
		char *r = bol + indent_len(bol);
		int prev = prev_tabstop(get_column(r));
		while (r &gt; bol &amp;&amp; get_column(r) &gt; prev) {
			if (p &gt; bol)
				p--;
			r--;
			r = text_hole_delete(r, r, ALLOW_UNDO_QUEUED);
		}

#if ENABLE_FEATURE_VI_SETOPTS
		if (autoindent &amp;&amp; indentcol &amp;&amp; r == end_line(p)) {
			// record changed size of autoindent
			indentcol = get_column(p);
			return p;
		}
#endif
#if ENABLE_FEATURE_VI_SETOPTS
	} else if (c == '\t' &amp;&amp; expandtab) {	// expand tab
		col = get_column(p);
		col = next_tabstop(col) - col + 1;
		while (col--) {
# if ENABLE_FEATURE_VI_UNDO
			undo_push_insert(p, 1, undo);
# else
			modified_count++;
# endif
			p += 1 + stupid_insert(p, ' ');
		}
#endif
	} else if (isbackspace(c)) {
		if (cmd_mode == 2) {
			// special treatment for backspace in Replace mode
			if (p &gt; rstart) {
				p--;
#if ENABLE_FEATURE_VI_UNDO
				undo_pop();
#endif
			}
		} else if (p &gt; text) {
			p--;
			p = text_hole_delete(p, p, ALLOW_UNDO_QUEUED);	// shrink buffer 1 char
		}
	} else {
		// insert a char into text[]
		if (c == 13)
			c = '\n';	// translate \r to \n
#if ENABLE_FEATURE_VI_UNDO
# if ENABLE_FEATURE_VI_UNDO_QUEUE
		if (c == '\n')
			undo_queue_commit();
# endif
		undo_push_insert(p, 1, undo);
#else
		modified_count++;
#endif
		p += 1 + stupid_insert(p, c);	// insert the char
#if ENABLE_FEATURE_VI_SETOPTS
		if (showmatch &amp;&amp; strchr(")]}", c) != NULL) {
			showmatching(p - 1);
		}
		if (autoindent &amp;&amp; c == '\n') {	// auto indent the new line
			if (newindent &lt; 0) {
				// use indent of previous line
				bol = prev_line(p);
				len = indent_len(bol);
				col = get_column(bol + len);

				if (len &amp;&amp; col == indentcol) {
					// previous line was empty except for autoindent
					// move the indent to the current line
					memmove(bol + 1, bol, len);
					*bol = '\n';
					return p;
				}
			} else {
				// for 'O'/'cc' commands add indent before newly inserted NL
				if (p != end - 1)	// but not for 'cc' at EOF
					p--;
				col = newindent;
			}

			if (col) {
				// only record indent if in insert/replace mode or for
				// the 'o'/'O'/'cc' commands, which are switched to
				// insert mode early.
				indentcol = cmd_mode != 0 ? col : 0;
				if (expandtab) {
					ntab = 0;
					nspc = col;
				} else {
					ntab = col / tabstop;
					nspc = col % tabstop;
				}
				p += text_hole_make(p, ntab + nspc);
# if ENABLE_FEATURE_VI_UNDO
				undo_push_insert(p, ntab + nspc, undo);
# endif
				memset(p, '\t', ntab);
				p += ntab;
				memset(p, ' ', nspc);
				return p + nspc;
			}
		}
#endif
	}
#if ENABLE_FEATURE_VI_SETOPTS
	indentcol = 0;
# undef indentcol
#endif
	return p;
}

#if ENABLE_FEATURE_VI_COLON_EXPAND
static void init_filename(char *fn)
{
	char *copy = xstrdup(fn);

	if (current_filename == NULL) {
		current_filename = copy;
	} else {
		free(alt_filename);
		alt_filename = copy;
	}
}
#else
# define init_filename(f) ((void)(0))
#endif

static void update_filename(char *fn)
{
#if ENABLE_FEATURE_VI_COLON_EXPAND
	if (fn == NULL)
		return;

	if (current_filename == NULL || strcmp(fn, current_filename) != 0) {
		free(alt_filename);
		alt_filename = current_filename;
		current_filename = xstrdup(fn);
	}
#else
	if (fn != current_filename) {
		free(current_filename);
		current_filename = xstrdup(fn);
	}
#endif
}

// read text from file or create an empty buf
// will also update current_filename
static int init_text_buffer(char *fn)
{
	int rc;

	// allocate/reallocate text buffer
	free(text);
	text_size = 10240;
	screenbegin = dot = end = text = xzalloc(text_size);

	update_filename(fn);
	rc = file_insert(fn, text, 1);
	if (rc &lt; 0) {
		// file doesnt exist. Start empty buf with dummy line
		char_insert(text, '\n', NO_UNDO);
	}

	flush_undo_data();
	modified_count = 0;
	last_modified_count = -1;
#if ENABLE_FEATURE_VI_YANKMARK
	// init the marks
	memset(mark, 0, sizeof(mark));
#endif
	return rc;
}

#if ENABLE_FEATURE_VI_YANKMARK \
 || (ENABLE_FEATURE_VI_COLON &amp;&amp; ENABLE_FEATURE_VI_SEARCH) \
 || ENABLE_FEATURE_VI_CRASHME
// might reallocate text[]! use p += string_insert(p, ...),
// and be careful to not use pointers into potentially freed text[]!
# if !ENABLE_FEATURE_VI_UNDO
#  define string_insert(a,b,c) string_insert(a,b)
# endif
static uintptr_t string_insert(char *p, const char *s, int undo) // insert the string at 'p'
{
	uintptr_t bias;
	int i;

	i = strlen(s);
#if ENABLE_FEATURE_VI_UNDO
	undo_push_insert(p, i, undo);
#endif
	bias = text_hole_make(p, i);
	p += bias;
	memcpy(p, s, i);
	return bias;
}
#endif

static int file_write(char *fn, char *first, char *last)
{
	int fd, cnt, charcnt;

	if (fn == 0) {
		status_line_bold("No current filename");
		return -2;
	}
	// By popular request we do not open file with O_TRUNC,
	// but instead ftruncate() it _after_ successful write.
	// Might reduce amount of data lost on power fail etc.
	fd = open(fn, (O_WRONLY | O_CREAT), 0666);
	if (fd &lt; 0)
		return -1;
	cnt = last - first + 1;
	charcnt = full_write(fd, first, cnt);
	ftruncate(fd, charcnt);
	if (charcnt == cnt) {
		// good write
		//modified_count = FALSE;
	} else {
		charcnt = 0;
	}
	close(fd);
	return charcnt;
}

#if ENABLE_FEATURE_VI_SEARCH
# if ENABLE_FEATURE_VI_REGEX_SEARCH
// search for pattern starting at p
static char *char_search(char *p, const char *pat, int dir_and_range)
{
	struct re_pattern_buffer preg;
	const char *err;
	char *q;
	int i, size, range, start;

	re_syntax_options = RE_SYNTAX_POSIX_BASIC &amp; (~RE_DOT_NEWLINE);
	if (ignorecase)
		re_syntax_options |= RE_ICASE;

	memset(&amp;preg, 0, sizeof(preg));
	err = re_compile_pattern(pat, strlen(pat), &amp;preg);
	preg.not_bol = p != text;
	preg.not_eol = p != end - 1;
	if (err != NULL) {
		status_line_bold("bad search pattern '%s': %s", pat, err);
		return p;
	}

	range = (dir_and_range &amp; 1);
	q = end - 1; // if FULL
	if (range == LIMITED)
		q = next_line(p);
	if (dir_and_range &lt; 0) { // BACK?
		q = text;
		if (range == LIMITED)
			q = prev_line(p);
	}

	// RANGE could be negative if we are searching backwards
	range = q - p;
	if (range &lt; 0) {
		size = -range;
		start = size;
	} else {
		size = range;
		start = 0;
	}
	q = p - start;
	if (q &lt; text)
		q = text;
	// search for the compiled pattern, preg, in p[]
	// range &lt; 0, start == size: search backward
	// range &gt; 0, start == 0: search forward
	// re_search() &lt; 0: not found or error
	// re_search() &gt;= 0: index of found pattern
	//           struct pattern   char     int   int    int    struct reg
	// re_search(*pattern_buffer, *string, size, start, range, *regs)
	i = re_search(&amp;preg, q, size, start, range, /*struct re_registers*:*/ NULL);
	regfree(&amp;preg);
	return i &lt; 0 ? NULL : q + i;
}
# else
#  if ENABLE_FEATURE_VI_SETOPTS
static int mycmp(const char *s1, const char *s2, int len)
{
	if (ignorecase) {
		return strncasecmp(s1, s2, len);
	}
	return strncmp(s1, s2, len);
}
#  else
#   define mycmp strncmp
#  endif
static char *char_search(char *p, const char *pat, int dir_and_range)
{
	char *start, *stop;
	int len;
	int range;

	len = strlen(pat);
	range = (dir_and_range &amp; 1);
	if (dir_and_range &gt; 0) { //FORWARD?
		stop = end - 1;	// assume range is p..end-1
		if (range == LIMITED)
			stop = next_line(p);	// range is to next line
		for (start = p; start &lt; stop; start++) {
			if (mycmp(start, pat, len) == 0) {
				return start;
			}
		}
	} else { //BACK
		stop = text;	// assume range is text..p
		if (range == LIMITED)
			stop = prev_line(p);	// range is to prev line
		for (start = p - len; start &gt;= stop; start--) {
			if (mycmp(start, pat, len) == 0) {
				return start;
			}
		}
	}
	// pattern not found
	return NULL;
}
# endif
#endif /* FEATURE_VI_SEARCH */

//----- The Colon commands -------------------------------------
#if ENABLE_FEATURE_VI_COLON
// Evaluate colon address expression.  Returns a pointer to the
// next character or NULL on error.  If 'result' contains a valid
// address 'valid' is TRUE.
static char *get_one_address(char *p, int *result, int *valid)
{
	int num, sign, addr, got_addr;
# if ENABLE_FEATURE_VI_YANKMARK || ENABLE_FEATURE_VI_SEARCH
	char *q, c;
# endif
	IF_FEATURE_VI_SEARCH(int dir;)

	got_addr = FALSE;
	addr = count_lines(text, dot);	// default to current line
	sign = 0;
	for (;;) {
		if (isblank(*p)) {
			if (got_addr) {
				addr += sign;
				sign = 0;
			}
			p++;
		} else if (!got_addr &amp;&amp; *p == '.') {	// the current line
			p++;
			//addr = count_lines(text, dot);
			got_addr = TRUE;
		} else if (!got_addr &amp;&amp; *p == '$') {	// the last line in file
			p++;
			addr = count_lines(text, end - 1);
			got_addr = TRUE;
		}
# if ENABLE_FEATURE_VI_YANKMARK
		else if (!got_addr &amp;&amp; *p == '\'') {	// is this a mark addr
			p++;
			c = tolower(*p);
			p++;
			q = NULL;
			if (c &gt;= 'a' &amp;&amp; c &lt;= 'z') {
				// we have a mark
				c = c - 'a';
				q = mark[(unsigned char) c];
			}
			if (q == NULL) {	// is mark valid
				status_line_bold("Mark not set");
				return NULL;
			}
			addr = count_lines(text, q);
			got_addr = TRUE;
		}
# endif
# if ENABLE_FEATURE_VI_SEARCH
		else if (!got_addr &amp;&amp; (*p == '/' || *p == '?')) {	// a search pattern
			c = *p;
			q = strchrnul(p + 1, c);
			if (p + 1 != q) {
				// save copy of new pattern
				free(last_search_pattern);
				last_search_pattern = xstrndup(p, q - p);
			}
			p = q;
			if (*p == c)
				p++;
			if (c == '/') {
				q = next_line(dot);
				dir = (FORWARD &lt;&lt; 1) | FULL;
			} else {
				q = begin_line(dot);
				dir = ((unsigned)BACK &lt;&lt; 1) | FULL;
			}
			q = char_search(q, last_search_pattern + 1, dir);
			if (q == NULL) {
				// no match, continue from other end of file
				q = char_search(dir &gt; 0 ? text : end - 1,
								last_search_pattern + 1, dir);
				if (q == NULL) {
					status_line_bold("Pattern not found");
					return NULL;
				}
			}
			addr = count_lines(text, q);
			got_addr = TRUE;
		}
# endif
		else if (isdigit(*p)) {
			num = 0;
			while (isdigit(*p))
				num = num * 10 + *p++ -'0';
			if (!got_addr) {	// specific line number
				addr = num;
				got_addr = TRUE;
			} else {	// offset from current addr
				addr += sign &gt;= 0 ? num : -num;
			}
			sign = 0;
		} else if (*p == '-' || *p == '+') {
			if (!got_addr) {	// default address is dot
				//addr = count_lines(text, dot);
				got_addr = TRUE;
			} else {
				addr += sign;
			}
			sign = *p++ == '-' ? -1 : 1;
		} else {
			addr += sign;	// consume unused trailing sign
			break;
		}
	}
	*result = addr;
	*valid = got_addr;
	return p;
}

# define GET_ADDRESS   0
# define GET_SEPARATOR 1

// Read line addresses for a colon command.  The user can enter as
// many as they like but only the last two will be used.
static char *get_address(char *p, int *b, int *e, unsigned int *got)
{
	int state = GET_ADDRESS;
	int valid;
	int addr;
	char *save_dot = dot;

	//----- get the address' i.e., 1,3   'a,'b  -----
	for (;;) {
		if (isblank(*p)) {
			p++;
		} else if (state == GET_ADDRESS &amp;&amp; *p == '%') {	// alias for 1,$
			p++;
			*b = 1;
			*e = count_lines(text, end-1);
			*got = 3;
			state = GET_SEPARATOR;
		} else if (state == GET_ADDRESS) {
			valid = FALSE;
			p = get_one_address(p, &amp;addr, &amp;valid);
			// Quit on error or if the address is invalid and isn't of
			// the form ',$' or '1,' (in which case it defaults to dot).
			if (p == NULL || !(valid || *p == ',' || *p == ';' || *got &amp; 1))
				break;
			*b = *e;
			*e = addr;
			*got = (*got &lt;&lt; 1) | 1;
			state = GET_SEPARATOR;
		} else if (state == GET_SEPARATOR &amp;&amp; (*p == ',' || *p == ';')) {
			if (*p == ';')
				dot = find_line(*e);
			p++;
			state = GET_ADDRESS;
		} else {
			break;
		}
	}
	dot = save_dot;
	return p;
}

# if ENABLE_FEATURE_VI_SET &amp;&amp; ENABLE_FEATURE_VI_SETOPTS
static void setops(char *args, int flg_no)
{
	char *eq;
	int index;

	eq = strchr(args, '=');
	if (eq) *eq = '\0';
	index = index_in_strings(OPTS_STR, args + flg_no);
	if (eq) *eq = '=';
	if (index &lt; 0) {
 bad:
		status_line_bold("bad option: %s", args);
		return;
	}

	index = 1 &lt;&lt; (index &gt;&gt; 1); // convert to VI_bit

	if (index &amp; VI_TABSTOP) {
		int t;
		if (!eq || flg_no) // no "=NNN" or it is "notabstop"?
			goto bad;
		t = bb_strtou(eq + 1, NULL, 10);
		if (t &lt;= 0 || t &gt; MAX_TABSTOP)
			goto bad;
		tabstop = t;
		return;
	}
	if (eq)	goto bad; // boolean option has "="?
	if (flg_no) {
		vi_setops &amp;= ~index;
	} else {
		vi_setops |= index;
	}
}
# endif

# if ENABLE_FEATURE_VI_COLON_EXPAND
static char *expand_args(char *args)
{
	char *s, *t;
	const char *replace;

	args = xstrdup(args);
	for (s = args; *s; s++) {
		if (*s == '%') {
			replace = current_filename;
		} else if (*s == '#') {
			replace = alt_filename;
		} else {
			if (*s == '\\' &amp;&amp; s[1] != '\0') {
				for (t = s++; *t; t++)
					*t = t[1];
			}
			continue;
		}

		if (replace == NULL) {
			free(args);
			status_line_bold("No previous filename");
			return NULL;
		}

		*s = '\0';
		t = xasprintf("%s%s%s", args, replace, s+1);
		s = t + (s - args) + strlen(replace);
		free(args);
		args = t;
	}
	return args;
}
# else
#  define expand_args(a) (a)
# endif
#endif /* FEATURE_VI_COLON */

#if ENABLE_FEATURE_VI_REGEX_SEARCH
# define MAX_SUBPATTERN 10	// subpatterns \0 .. \9

// Like strchr() but skipping backslash-escaped characters
static char *strchr_backslash(const char *s, int c)
{
	while (*s) {
		if (*s == c)
			return (char *)s;
		if (*s == '\\')
			if (*++s == '\0')
				break;
		s++;
	}
	return NULL;
}

// If the return value is not NULL the caller should free R
static char *regex_search(char *q, regex_t *preg, const char *Rorig,
				size_t *len_F, size_t *len_R, char **R)
{
	regmatch_t regmatch[MAX_SUBPATTERN], *cur_match;
	char *found = NULL;
	const char *t;
	char *r;

	regmatch[0].rm_so = 0;
	regmatch[0].rm_eo = end_line(q) - q;
	if (regexec(preg, q, MAX_SUBPATTERN, regmatch, REG_STARTEND) != 0)
		return found;

	found = q + regmatch[0].rm_so;
	*len_F = regmatch[0].rm_eo - regmatch[0].rm_so;
	*R = NULL;

 fill_result:
	// first pass calculates len_R, second fills R
	*len_R = 0;
	for (t = Rorig, r = *R; *t; t++) {
		size_t len = 1;	// default is to copy one char from replace pattern
		const char *from = t;
		if (*t == '\\') {
			from = ++t;	// skip backslash
			if (*t &gt;= '0' &amp;&amp; *t &lt; '0' + MAX_SUBPATTERN) {
				cur_match = regmatch + (*t - '0');
				if (cur_match-&gt;rm_so &gt;= 0) {
					len = cur_match-&gt;rm_eo - cur_match-&gt;rm_so;
					from = q + cur_match-&gt;rm_so;
				}
			}
		}
		*len_R += len;
		if (*R) {
			memcpy(r, from, len);
			r += len;
			/* *r = '\0'; - xzalloc did it */
		}
	}
	if (*R == NULL) {
		*R = xzalloc(*len_R + 1);
		goto fill_result;
	}

	return found;
}
#else /* !ENABLE_FEATURE_VI_REGEX_SEARCH */
# define strchr_backslash(s, c) strchr(s, c)
#endif /* ENABLE_FEATURE_VI_REGEX_SEARCH */

// buf must be no longer than MAX_INPUT_LEN!
static void colon(char *buf)
{
#if !ENABLE_FEATURE_VI_COLON
	// Simple ":cmd" handler with minimal set of commands
	char *p = buf;
	int cnt;

	if (*p == ':')
		p++;
	cnt = strlen(p);
	if (cnt == 0)
		return;
	if (strncmp(p, "quit", cnt) == 0
	 || strcmp(p, "q!") == 0
	) {
		if (modified_count &amp;&amp; p[1] != '!') {
			status_line_bold("No write since last change (:%s! overrides)", p);
		} else {
			editing = 0;
		}
		return;
	}
	if (strncmp(p, "write", cnt) == 0
	 || strcmp(p, "wq") == 0
	 || strcmp(p, "wn") == 0
	 || (p[0] == 'x' &amp;&amp; !p[1])
	) {
		if (modified_count != 0 || p[0] != 'x') {
			cnt = file_write(current_filename, text, end - 1);
		}
		if (cnt &lt; 0) {
			if (cnt == -1)
				status_line_bold("Write error: "STRERROR_FMT STRERROR_ERRNO);
		} else {
			modified_count = 0;
			last_modified_count = -1;
			status_line("'%s' %uL, %uC",
				current_filename,
				count_lines(text, end - 1), cnt
			);
			if (p[0] == 'x'
			 || p[1] == 'q' || p[1] == 'n'
			) {
				editing = 0;
			}
		}
		return;
	}
	if (strncmp(p, "file", cnt) == 0) {
		last_status_cksum = 0;	// force status update
		return;
	}
	if (sscanf(p, "%d", &amp;cnt) &gt; 0) {
		dot = find_line(cnt);
		dot_skip_over_ws();
		return;
	}
	not_implemented(p);
#else

// check how many addresses we got
# define GOT_ADDRESS (got &amp; 1)
# define GOT_RANGE ((got &amp; 3) == 3)

	char c, *buf1, *q, *r;
	char *fn, cmd[MAX_INPUT_LEN], *cmdend, *args, *exp = NULL;
	int i, l, li, b, e;
	unsigned int got;
	int useforce;

	// :3154	// if (-e line 3154) goto it  else stay put
	// :4,33w! foo	// write a portion of buffer to file "foo"
	// :w		// write all of buffer to current file
	// :q		// quit
	// :q!		// quit- dont care about modified file
	// :'a,'z!sort -u   // filter block through sort
	// :'f		// goto mark "f"
	// :'fl		// list literal the mark "f" line
	// :.r bar	// read file "bar" into buffer before dot
	// :/123/,/abc/d    // delete lines from "123" line to "abc" line
	// :/xyz/	// goto the "xyz" line
	// :s/find/replace/ // substitute pattern "find" with "replace"
	// :!&lt;cmd&gt;	// run &lt;cmd&gt; then return
	//

	while (*buf == ':')
		buf++;			// move past leading colons
	while (isblank(*buf))
		buf++;			// move past leading blanks
	if (!buf[0] || buf[0] == '"')
		goto ret;		// ignore empty lines or those starting with '"'

	li = i = 0;
	b = e = -1;
	got = 0;
	li = count_lines(text, end - 1);
	fn = current_filename;

	// look for optional address(es)  :.  :1  :1,9   :'q,'a   :%
	buf = get_address(buf, &amp;b, &amp;e, &amp;got);
	if (buf == NULL) {
		goto ret;
	}

	// get the COMMAND into cmd[]
	strcpy(cmd, buf);
	buf1 = cmd;
	while (!isspace(*buf1) &amp;&amp; *buf1 != '\0') {
		buf1++;
	}
	cmdend = buf1;
	// get any ARGuments
	while (isblank(*buf1))
		buf1++;
	args = buf1;
	*cmdend = '\0';
	useforce = FALSE;
	if (cmdend &gt; cmd &amp;&amp; cmdend[-1] == '!') {
		useforce = TRUE;
		cmdend[-1] = '\0';   // get rid of !
	}
	// assume the command will want a range, certain commands
	// (read, substitute) need to adjust these assumptions
	if (!GOT_ADDRESS) {
		q = text;			// no addr, use 1,$ for the range
		r = end - 1;
	} else {
		// at least one addr was given, get its details
		if (e &lt; 0 || e &gt; li) {
			status_line_bold("Invalid range");
			goto ret;
		}
		q = r = find_line(e);
		if (!GOT_RANGE) {
			// if there is only one addr, then it's the line
			// number of the single line the user wants.
			// Reset the end pointer to the end of that line.
			r = end_line(q);
			li = 1;
		} else {
			// we were given two addrs.  change the
			// start pointer to the addr given by user.
			if (b &lt; 0 || b &gt; li || b &gt; e) {
				status_line_bold("Invalid range");
				goto ret;
			}
			q = find_line(b);	// what line is #b
			r = end_line(r);
			li = e - b + 1;
		}
	}
	// ------------ now look for the command ------------
	i = strlen(cmd);
	if (i == 0) {		// :123CR goto line #123
		if (e &gt;= 0) {
			dot = find_line(e);	// what line is #e
			dot_skip_over_ws();
		}
	}
# if ENABLE_FEATURE_ALLOW_EXEC
	else if (cmd[0] == '!') {	// run a cmd
		int retcode;
		// :!ls   run the &lt;cmd&gt;
		exp = expand_args(buf + 1);
		if (exp == NULL)
			goto ret;
		go_bottom_and_clear_to_eol();
		cookmode();
		retcode = system(exp);	// run the cmd
		if (retcode)
			printf("\nshell returned %i\n\n", retcode);
		rawmode();
		Hit_Return();			// let user see results
	}
# endif
	else if (cmd[0] == '=' &amp;&amp; !cmd[1]) {	// where is the address
		if (!GOT_ADDRESS) {	// no addr given- use defaults
			e = count_lines(text, dot);
		}
		status_line("%d", e);
	} else if (strncmp(cmd, "delete", i) == 0) {	// delete lines
		if (!GOT_ADDRESS) {	// no addr given- use defaults
			q = begin_line(dot);	// assume .,. for the range
			r = end_line(dot);
		}
		dot = yank_delete(q, r, WHOLE, YANKDEL, ALLOW_UNDO);	// save, then delete lines
		dot_skip_over_ws();
	} else if (strncmp(cmd, "edit", i) == 0) {	// Edit a file
		int size;

		// don't edit, if the current file has been modified
		if (modified_count &amp;&amp; !useforce) {
			status_line_bold("No write since last change (:%s! overrides)", cmd);
			goto ret;
		}
		if (args[0]) {
			// the user supplied a file name
			fn = exp = expand_args(args);
			if (exp == NULL)
				goto ret;
		} else if (current_filename == NULL) {
			// no user file name, no current name- punt
			status_line_bold("No current filename");
			goto ret;
		}

		size = init_text_buffer(fn);

# if ENABLE_FEATURE_VI_YANKMARK
		if (Ureg &gt;= 0 &amp;&amp; Ureg &lt; 28) {
			free(reg[Ureg]);	//   free orig line reg- for 'U'
			reg[Ureg] = NULL;
		}
		/*if (YDreg &lt; 28) - always true*/ {
			free(reg[YDreg]);	//   free default yank/delete register
			reg[YDreg] = NULL;
		}
# endif
		// how many lines in text[]?
		li = count_lines(text, end - 1);
		status_line("'%s'%s"
			IF_FEATURE_VI_READONLY("%s")
			" %uL, %uC",
			fn,
			(size &lt; 0 ? " [New file]" : ""),
			IF_FEATURE_VI_READONLY(
				((readonly_mode) ? " [Readonly]" : ""),
			)
			li, (int)(end - text)
		);
	} else if (strncmp(cmd, "file", i) == 0) {	// what File is this
		if (e &gt;= 0) {
			status_line_bold("No address allowed on this command");
			goto ret;
		}
		if (args[0]) {
			// user wants a new filename
			exp = expand_args(args);
			if (exp == NULL)
				goto ret;
			update_filename(exp);
		} else {
			// user wants file status info
			last_status_cksum = 0;	// force status update
		}
	} else if (strncmp(cmd, "features", i) == 0) {	// what features are available
		// print out values of all features
		go_bottom_and_clear_to_eol();
		cookmode();
		show_help();
		rawmode();
		Hit_Return();
	} else if (strncmp(cmd, "list", i) == 0) {	// literal print line
		if (!GOT_ADDRESS) {	// no addr given- use defaults
			q = begin_line(dot);	// assume .,. for the range
			r = end_line(dot);
		}
		go_bottom_and_clear_to_eol();
		puts("\r");
		for (; q &lt;= r; q++) {
			int c_is_no_print;

			c = *q;
			c_is_no_print = (c &amp; 0x80) &amp;&amp; !Isprint(c);
			if (c_is_no_print) {
				c = '.';
				standout_start();
			}
			if (c == '\n') {
				write1("$\r");
			} else if (c &lt; ' ' || c == 127) {
				bb_putchar('^');
				if (c == 127)
					c = '?';
				else
					c += '@';
			}
			bb_putchar(c);
			if (c_is_no_print)
				standout_end();
		}
		Hit_Return();
	} else if (strncmp(cmd, "quit", i) == 0 // quit
	        || strncmp(cmd, "next", i) == 0 // edit next file
	        || strncmp(cmd, "prev", i) == 0 // edit previous file
	) {
		int n;
		if (useforce) {
			if (*cmd == 'q') {
				// force end of argv list
				optind = cmdline_filecnt;
			}
			editing = 0;
			goto ret;
		}
		// don't exit if the file been modified
		if (modified_count) {
			status_line_bold("No write since last change (:%s! overrides)", cmd);
			goto ret;
		}
		// are there other file to edit
		n = cmdline_filecnt - optind - 1;
		if (*cmd == 'q' &amp;&amp; n &gt; 0) {
			status_line_bold("%u more file(s) to edit", n);
			goto ret;
		}
		if (*cmd == 'n' &amp;&amp; n &lt;= 0) {
			status_line_bold("No more files to edit");
			goto ret;
		}
		if (*cmd == 'p') {
			// are there previous files to edit
			if (optind &lt; 1) {
				status_line_bold("No previous files to edit");
				goto ret;
			}
			optind -= 2;
		}
		editing = 0;
	} else if (strncmp(cmd, "read", i) == 0) {	// read file into text[]
		int size, num;

		if (args[0]) {
			// the user supplied a file name
			fn = exp = expand_args(args);
			if (exp == NULL)
				goto ret;
			init_filename(fn);
		} else if (current_filename == NULL) {
			// no user file name, no current name- punt
			status_line_bold("No current filename");
			goto ret;
		}
		if (e == 0) {	// user said ":0r foo"
			q = text;
		} else {	// read after given line or current line if none given
			q = next_line(GOT_ADDRESS ? find_line(e) : dot);
			// read after last line
			if (q == end-1)
				++q;
		}
		num = count_lines(text, q);
		if (q == end)
			num++;
		{ // dance around potentially-reallocated text[]
			uintptr_t ofs = q - text;
			size = file_insert(fn, q, 0);
			q = text + ofs;
		}
		if (size &lt; 0)
			goto ret;	// nothing was inserted
		// how many lines in text[]?
		li = count_lines(q, q + size - 1);
		status_line("'%s'"
			IF_FEATURE_VI_READONLY("%s")
			" %uL, %uC",
			fn,
			IF_FEATURE_VI_READONLY((readonly_mode ? " [Readonly]" : ""),)
			li, size
		);
		dot = find_line(num);
	} else if (strncmp(cmd, "rewind", i) == 0) {	// rewind cmd line args
		if (modified_count &amp;&amp; !useforce) {
			status_line_bold("No write since last change (:%s! overrides)", cmd);
		} else {
			// reset the filenames to edit
			optind = -1; // start from 0th file
			editing = 0;
		}
# if ENABLE_FEATURE_VI_SET
	} else if (strncmp(cmd, "set", i) == 0) {	// set or clear features
#  if ENABLE_FEATURE_VI_SETOPTS
		char *argp, *argn, oldch;
#  endif
		// only blank is regarded as args delimiter. What about tab '\t'?
		if (!args[0] || strcmp(args, "all") == 0) {
			// print out values of all options
#  if ENABLE_FEATURE_VI_SETOPTS
			status_line_bold(
				"%sautoindent "
				"%sexpandtab "
				"%sflash "
				"%signorecase "
				"%sshowmatch "
				"tabstop=%u",
				autoindent ? "" : "no",
				expandtab ? "" : "no",
				err_method ? "" : "no",
				ignorecase ? "" : "no",
				showmatch ? "" : "no",
				tabstop
			);
#  endif
			goto ret;
		}
#  if ENABLE_FEATURE_VI_SETOPTS
		argp = args;
		while (*argp) {
			i = 0;
			if (argp[0] == 'n' &amp;&amp; argp[1] == 'o') // "noXXX"
				i = 2;
			argn = skip_non_whitespace(argp);
			oldch = *argn;
			*argn = '\0';
			setops(argp, i);
			*argn = oldch;
			argp = skip_whitespace(argn);
		}
#  endif /* FEATURE_VI_SETOPTS */
# endif /* FEATURE_VI_SET */

# if ENABLE_FEATURE_VI_SEARCH
	} else if (cmd[0] == 's') {	// substitute a pattern with a replacement pattern
		char *F, *R, *flags;
		size_t len_F, len_R;
		int gflag = 0;		// global replace flag
		int subs = 0;	// number of substitutions
#  if ENABLE_FEATURE_VI_VERBOSE_STATUS
		int last_line = 0, lines = 0;
#  endif
#  if ENABLE_FEATURE_VI_REGEX_SEARCH
		regex_t preg;
		int cflags;
		char *Rorig;
#   if ENABLE_FEATURE_VI_UNDO
		int undo = 0;
#   endif
#  endif

		// F points to the "find" pattern
		// R points to the "replace" pattern
		// replace the cmd line delimiters "/" with NULs
		c = buf[1];	// what is the delimiter
		F = buf + 2;	// start of "find"
		R = strchr_backslash(F, c);	// middle delimiter
		if (!R)
			goto colon_s_fail;
		len_F = R - F;
		*R++ = '\0';	// terminate "find"
		flags = strchr_backslash(R, c);
		if (flags) {
			*flags++ = '\0';	// terminate "replace"
			gflag = *flags;
		}

		if (len_F) {	// save "find" as last search pattern
			free(last_search_pattern);
			last_search_pattern = xstrdup(F - 1);
			last_search_pattern[0] = '/';
		} else if (last_search_pattern[1] == '\0') {
			status_line_bold("No previous search");
			goto ret;
		} else {
			F = last_search_pattern + 1;
			len_F = strlen(F);
		}

		if (!GOT_ADDRESS) {	// no addr given
			q = begin_line(dot);      // start with cur line
			r = end_line(dot);
			b = e = count_lines(text, q); // cur line number
		} else if (!GOT_RANGE) {	// one addr given
			b = e;
		}

#  if ENABLE_FEATURE_VI_REGEX_SEARCH
		Rorig = R;
		cflags = 0;
		if (ignorecase)
			cflags = REG_ICASE;
		memset(&amp;preg, 0, sizeof(preg));
		if (regcomp(&amp;preg, F, cflags) != 0) {
			status_line(":s bad search pattern");
			goto regex_search_end;
		}
#  else
		len_R = strlen(R);
#  endif

		for (i = b; i &lt;= e; i++) {	// so, :20,23 s \0 find \0 replace \0
			char *ls = q;		// orig line start
			char *found;
 vc4:
#  if ENABLE_FEATURE_VI_REGEX_SEARCH
			found = regex_search(q, &amp;preg, Rorig, &amp;len_F, &amp;len_R, &amp;R);
#  else
			found = char_search(q, F, (FORWARD &lt;&lt; 1) | LIMITED);	// search cur line only for "find"
#  endif
			if (found) {
				uintptr_t bias;
				// we found the "find" pattern - delete it
				// For undo support, the first item should not be chained
				// This needs to be handled differently depending on
				// whether or not regex support is enabled.
#  if ENABLE_FEATURE_VI_REGEX_SEARCH
#   define TEST_LEN_F len_F	// len_F may be zero
#   define TEST_UNDO1 undo++
#   define TEST_UNDO2 undo++
#  else
#   define TEST_LEN_F 1		// len_F is never zero
#   define TEST_UNDO1 subs
#   define TEST_UNDO2 1
#  endif
				if (TEST_LEN_F)	// match can be empty, no delete needed
					text_hole_delete(found, found + len_F - 1,
								TEST_UNDO1 ? ALLOW_UNDO_CHAIN : ALLOW_UNDO);
				if (len_R != 0) {	// insert the "replace" pattern, if required
					bias = string_insert(found, R,
								TEST_UNDO2 ? ALLOW_UNDO_CHAIN : ALLOW_UNDO);
					found += bias;
					ls += bias;
					//q += bias; - recalculated anyway
				}
#  if ENABLE_FEATURE_VI_REGEX_SEARCH
				free(R);
#  endif
				if (TEST_LEN_F || len_R != 0) {
					dot = ls;
					subs++;
#  if ENABLE_FEATURE_VI_VERBOSE_STATUS
					if (last_line != i) {
						last_line = i;
						++lines;
					}
#  endif
				}
				// check for "global"  :s/foo/bar/g
				if (gflag == 'g') {
					if ((found + len_R) &lt; end_line(ls)) {
						q = found + len_R;
						goto vc4;	// don't let q move past cur line
					}
				}
			}
			q = next_line(ls);
		}
		if (subs == 0) {
			status_line_bold("No match");
		} else {
			dot_skip_over_ws();
#  if ENABLE_FEATURE_VI_VERBOSE_STATUS
			if (subs &gt; 1)
				status_line("%d substitutions on %d lines", subs, lines);
#  endif
		}
#  if ENABLE_FEATURE_VI_REGEX_SEARCH
 regex_search_end:
		regfree(&amp;preg);
#  endif
# endif /* FEATURE_VI_SEARCH */
	} else if (strncmp(cmd, "version", i) == 0) {  // show software version
		status_line(BB_VER);
	} else if (strncmp(cmd, "write", i) == 0  // write text to file
	        || strcmp(cmd, "wq") == 0
	        || strcmp(cmd, "wn") == 0
	        || (cmd[0] == 'x' &amp;&amp; !cmd[1])
	) {
		int size;
		//int forced = FALSE;

		// is there a file name to write to?
		if (args[0]) {
			struct stat statbuf;

			exp = expand_args(args);
			if (exp == NULL)
				goto ret;
			if (!useforce &amp;&amp; (fn == NULL || strcmp(fn, exp) != 0) &amp;&amp;
					stat(exp, &amp;statbuf) == 0) {
				status_line_bold("File exists (:w! overrides)");
				goto ret;
			}
			fn = exp;
			init_filename(fn);
		}
# if ENABLE_FEATURE_VI_READONLY
		else if (readonly_mode &amp;&amp; !useforce &amp;&amp; fn) {
			status_line_bold("'%s' is read only", fn);
			goto ret;
		}
# endif
		//if (useforce) {
			// if "fn" is not write-able, chmod u+w
			// sprintf(syscmd, "chmod u+w %s", fn);
			// system(syscmd);
			// forced = TRUE;
		//}
		if (modified_count != 0 || cmd[0] != 'x') {
			size = r - q + 1;
			l = file_write(fn, q, r);
		} else {
			size = 0;
			l = 0;
		}
		//if (useforce &amp;&amp; forced) {
			// chmod u-w
			// sprintf(syscmd, "chmod u-w %s", fn);
			// system(syscmd);
			// forced = FALSE;
		//}
		if (l &lt; 0) {
			if (l == -1)
				status_line_bold_errno(fn);
		} else {
			// how many lines written
			li = count_lines(q, q + l - 1);
			status_line("'%s' %uL, %uC", fn, li, l);
			if (l == size) {
				if (q == text &amp;&amp; q + l == end) {
					modified_count = 0;
					last_modified_count = -1;
				}
				if (cmd[1] == 'n') {
					editing = 0;
				} else if (cmd[0] == 'x' || cmd[1] == 'q') {
					// are there other files to edit?
					int n = cmdline_filecnt - optind - 1;
					if (n &gt; 0) {
						if (useforce) {
							// force end of argv list
							optind = cmdline_filecnt;
						} else {
							status_line_bold("%u more file(s) to edit", n);
							goto ret;
						}
					}
					editing = 0;
				}
			}
		}
# if ENABLE_FEATURE_VI_YANKMARK
	} else if (strncmp(cmd, "yank", i) == 0) {	// yank lines
		if (!GOT_ADDRESS) {	// no addr given- use defaults
			q = begin_line(dot);	// assume .,. for the range
			r = end_line(dot);
		}
		text_yank(q, r, YDreg, WHOLE);
		li = count_lines(q, r);
		status_line("Yank %d lines (%d chars) into [%c]",
				li, strlen(reg[YDreg]), what_reg());
# endif
	} else {
		// cmd unknown
		not_implemented(cmd);
	}
 ret:
# if ENABLE_FEATURE_VI_COLON_EXPAND
	free(exp);
# endif
	dot = bound_dot(dot);	// make sure "dot" is valid
	return;
# if ENABLE_FEATURE_VI_SEARCH
 colon_s_fail:
	status_line(":s expression missing delimiters");
# endif
#endif /* FEATURE_VI_COLON */
}

//----- Char Routines --------------------------------------------
// Chars that are part of a word-
//    0123456789_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
// Chars that are Not part of a word (stoppers)
//    !"#$%&amp;'()*+,-./:;&lt;=&gt;?@[\]^`{|}~
// Chars that are WhiteSpace
//    TAB NEWLINE VT FF RETURN SPACE
// DO NOT COUNT NEWLINE AS WHITESPACE

static int st_test(char *p, int type, int dir, char *tested)
{
	char c, c0, ci;
	int test, inc;

	inc = dir;
	c = c0 = p[0];
	ci = p[inc];
	test = 0;

	if (type == S_BEFORE_WS) {
		c = ci;
		test = (!isspace(c) || c == '\n');
	}
	if (type == S_TO_WS) {
		c = c0;
		test = (!isspace(c) || c == '\n');
	}
	if (type == S_OVER_WS) {
		c = c0;
		test = isspace(c);
	}
	if (type == S_END_PUNCT) {
		c = ci;
		test = ispunct(c);
	}
	if (type == S_END_ALNUM) {
		c = ci;
		test = (isalnum(c) || c == '_');
	}
	*tested = c;
	return test;
}

static char *skip_thing(char *p, int linecnt, int dir, int type)
{
	char c;

	while (st_test(p, type, dir, &amp;c)) {
		// make sure we limit search to correct number of lines
		if (c == '\n' &amp;&amp; --linecnt &lt; 1)
			break;
		if (dir &gt;= 0 &amp;&amp; p &gt;= end - 1)
			break;
		if (dir &lt; 0 &amp;&amp; p &lt;= text)
			break;
		p += dir;		// move to next char
	}
	return p;
}

#if ENABLE_FEATURE_VI_USE_SIGNALS
static void winch_handler(int sig UNUSED_PARAM)
{
	int save_errno = errno;
	// FIXME: do it in main loop!!!
	signal(SIGWINCH, winch_handler);
	query_screen_dimensions();
	new_screen(rows, columns);	// get memory for virtual screen
	redraw(TRUE);		// re-draw the screen
	errno = save_errno;
}
static void tstp_handler(int sig UNUSED_PARAM)
{
	int save_errno = errno;

	// ioctl inside cookmode() was seen to generate SIGTTOU,
	// stopping us too early. Prevent that:
	signal(SIGTTOU, SIG_IGN);

	go_bottom_and_clear_to_eol();
	cookmode(); // terminal to "cooked"

	// stop now
	//signal(SIGTSTP, SIG_DFL);
	//raise(SIGTSTP);
	raise(SIGSTOP); // avoid "dance" with TSTP handler - use SIGSTOP instead
	//signal(SIGTSTP, tstp_handler);

	// we have been "continued" with SIGCONT, restore screen and termios
	rawmode(); // terminal to "raw"
	last_status_cksum = 0; // force status update
	redraw(TRUE); // re-draw the screen

	errno = save_errno;
}
static void int_handler(int sig)
{
	signal(SIGINT, int_handler);
	siglongjmp(restart, sig);
}
#endif /* FEATURE_VI_USE_SIGNALS */

static void do_cmd(int c);

static int at_eof(const char *s)
{
	// does 's' point to end of file, even with no terminating newline?
	return ((s == end - 2 &amp;&amp; s[1] == '\n') || s == end - 1);
}

static int find_range(char **start, char **stop, int cmd)
{
	char *p, *q, *t;
	int buftype = -1;
	int c;

	p = q = dot;

#if ENABLE_FEATURE_VI_YANKMARK
	if (cmd == 'Y') {
		c = 'y';
	} else
#endif
	{
		c = get_motion_char();
	}

#if ENABLE_FEATURE_VI_YANKMARK
	if ((cmd == 'Y' || cmd == c) &amp;&amp; strchr("cdy&gt;&lt;", c)) {
#else
	if (cmd == c &amp;&amp; strchr("cd&gt;&lt;", c)) {
#endif
		// these cmds operate on whole lines
		buftype = WHOLE;
		if (--cmdcnt &gt; 0) {
			do_cmd('j');
			if (cmd_error)
				buftype = -1;
		}
	} else if (strchr("^%$0bBeEfFtThnN/?|{}\b\177", c)) {
		// Most operate on char positions within a line.  Of those that
		// don't '%' needs no special treatment, search commands are
		// marked as MULTI and  "{}" are handled below.
		buftype = strchr("nN/?", c) ? MULTI : PARTIAL;
		do_cmd(c);		// execute movement cmd
		if (p == dot)	// no movement is an error
			buftype = -1;
	} else if (strchr("wW", c)) {
		buftype = MULTI;
		do_cmd(c);		// execute movement cmd
		// step back one char, but not if we're at end of file,
		// or if we are at EOF and search was for 'w' and we're at
		// the start of a 'W' word.
		if (dot &gt; p &amp;&amp; (!at_eof(dot) || (c == 'w' &amp;&amp; ispunct(*dot))))
			dot--;
		t = dot;
		// don't include trailing WS as part of word
		while (dot &gt; p &amp;&amp; isspace(*dot)) {
			if (*dot-- == '\n')
				t = dot;
		}
		// for non-change operations WS after NL is not part of word
		if (cmd != 'c' &amp;&amp; dot != t &amp;&amp; *dot != '\n')
			dot = t;
	} else if (strchr("GHL+-gjk'\r\n", c)) {
		// these operate on whole lines
		buftype = WHOLE;
		do_cmd(c);		// execute movement cmd
		if (cmd_error)
			buftype = -1;
	} else if (c == ' ' || c == 'l') {
		// forward motion by character
		int tmpcnt = (cmdcnt ?: 1);
		buftype = PARTIAL;
		do_cmd(c);		// execute movement cmd
		// exclude last char unless range isn't what we expected
		// this indicates we've hit EOL
		if (tmpcnt == dot - p)
			dot--;
	}

	if (buftype == -1) {
		if (c != 27)
			indicate_error();
		return buftype;
	}

	q = dot;
	if (q &lt; p) {
		t = q;
		q = p;
		p = t;
	}

	// movements which don't include end of range
	if (q &gt; p) {
		if (strchr("^0bBFThnN/?|\b\177", c)) {
			q--;
		} else if (strchr("{}", c)) {
			buftype = (p == begin_line(p) &amp;&amp; (*q == '\n' || at_eof(q))) ?
							WHOLE : MULTI;
			if (!at_eof(q)) {
				q--;
				if (q &gt; p &amp;&amp; p != begin_line(p))
					q--;
			}
		}
	}

	*start = p;
	*stop = q;
	return buftype;
}

//---------------------------------------------------------------------
//----- the Ascii Chart -----------------------------------------------
//  00 nul   01 soh   02 stx   03 etx   04 eot   05 enq   06 ack   07 bel
//  08 bs    09 ht    0a nl    0b vt    0c np    0d cr    0e so    0f si
//  10 dle   11 dc1   12 dc2   13 dc3   14 dc4   15 nak   16 syn   17 etb
//  18 can   19 em    1a sub   1b esc   1c fs    1d gs    1e rs    1f us
//  20 sp    21 !     22 "     23 #     24 $     25 %     26 &amp;     27 '
//  28 (     29 )     2a *     2b +     2c ,     2d -     2e .     2f /
//  30 0     31 1     32 2     33 3     34 4     35 5     36 6     37 7
//  38 8     39 9     3a :     3b ;     3c &lt;     3d =     3e &gt;     3f ?
//  40 @     41 A     42 B     43 C     44 D     45 E     46 F     47 G
//  48 H     49 I     4a J     4b K     4c L     4d M     4e N     4f O
//  50 P     51 Q     52 R     53 S     54 T     55 U     56 V     57 W
//  58 X     59 Y     5a Z     5b [     5c \     5d ]     5e ^     5f _
//  60 `     61 a     62 b     63 c     64 d     65 e     66 f     67 g
//  68 h     69 i     6a j     6b k     6c l     6d m     6e n     6f o
//  70 p     71 q     72 r     73 s     74 t     75 u     76 v     77 w
//  78 x     79 y     7a z     7b {     7c |     7d }     7e ~     7f del
//---------------------------------------------------------------------

//----- Execute a Vi Command -----------------------------------
static void do_cmd(int c)
{
	char *p, *q, *save_dot;
	char buf[12];
	int dir;
	int cnt, i, j;
	int c1;
#if ENABLE_FEATURE_VI_YANKMARK
	char *orig_dot = dot;
#endif
#if ENABLE_FEATURE_VI_UNDO
	int allow_undo = ALLOW_UNDO;
	int undo_del = UNDO_DEL;
#endif

//	c1 = c; // quiet the compiler
//	cnt = yf = 0; // quiet the compiler
//	p = q = save_dot = buf; // quiet the compiler
	memset(buf, '\0', sizeof(buf));
	keep_index = FALSE;
	cmd_error = FALSE;

	show_status_line();

	// if this is a cursor key, skip these checks
	switch (c) {
		case KEYCODE_UP:
		case KEYCODE_DOWN:
		case KEYCODE_LEFT:
		case KEYCODE_RIGHT:
		case KEYCODE_HOME:
		case KEYCODE_END:
		case KEYCODE_PAGEUP:
		case KEYCODE_PAGEDOWN:
		case KEYCODE_DELETE:
			goto key_cmd_mode;
	}

	if (cmd_mode == 2) {
		//  flip-flop Insert/Replace mode
		if (c == KEYCODE_INSERT)
			goto dc_i;
		// we are 'R'eplacing the current *dot with new char
		if (*dot == '\n') {
			// don't Replace past E-o-l
			cmd_mode = 1;	// convert to insert
			undo_queue_commit();
		} else {
			if (1 &lt;= c || Isprint(c)) {
				if (c != 27 &amp;&amp; !isbackspace(c))
					dot = yank_delete(dot, dot, PARTIAL, YANKDEL, ALLOW_UNDO);
				dot = char_insert(dot, c, ALLOW_UNDO_CHAIN);
			}
			goto dc1;
		}
	}
	if (cmd_mode == 1) {
		// hitting "Insert" twice means "R" replace mode
		if (c == KEYCODE_INSERT) goto dc5;
		// insert the char c at "dot"
		if (1 &lt;= c || Isprint(c)) {
			dot = char_insert(dot, c, ALLOW_UNDO_QUEUED);
		}
		goto dc1;
	}

 key_cmd_mode:
	switch (c) {
		//case 0x01:	// soh
		//case 0x09:	// ht
		//case 0x0b:	// vt
		//case 0x0e:	// so
		//case 0x0f:	// si
		//case 0x10:	// dle
		//case 0x11:	// dc1
		//case 0x13:	// dc3
#if ENABLE_FEATURE_VI_CRASHME
	case 0x14:			// dc4  ctrl-T
		crashme = (crashme == 0) ? 1 : 0;
		break;
#endif
		//case 0x16:	// syn
		//case 0x17:	// etb
		//case 0x18:	// can
		//case 0x1c:	// fs
		//case 0x1d:	// gs
		//case 0x1e:	// rs
		//case 0x1f:	// us
		//case '!':	// !-
		//case '#':	// #-
		//case '&amp;':	// &amp;-
		//case '(':	// (-
		//case ')':	// )-
		//case '*':	// *-
		//case '=':	// =-
		//case '@':	// @-
		//case 'K':	// K-
		//case 'Q':	// Q-
		//case 'S':	// S-
		//case 'V':	// V-
		//case '[':	// [-
		//case '\\':	// \-
		//case ']':	// ]-
		//case '_':	// _-
		//case '`':	// `-
		//case 'v':	// v-
	default:			// unrecognized command
		buf[0] = c;
		buf[1] = '\0';
		not_implemented(buf);
		end_cmd_q();	// stop adding to q
	case 0x00:			// nul- ignore
		break;
	case 2:			// ctrl-B  scroll up   full screen
	case KEYCODE_PAGEUP:	// Cursor Key Page Up
		dot_scroll(rows - 2, -1);
		break;
	case 4:			// ctrl-D  scroll down half screen
		dot_scroll((rows - 2) / 2, 1);
		break;
	case 5:			// ctrl-E  scroll down one line
		dot_scroll(1, 1);
		break;
	case 6:			// ctrl-F  scroll down full screen
	case KEYCODE_PAGEDOWN:	// Cursor Key Page Down
		dot_scroll(rows - 2, 1);
		break;
	case 7:			// ctrl-G  show current status
		last_status_cksum = 0;	// force status update
		break;
	case 'h':			// h- move left
	case KEYCODE_LEFT:	// cursor key Left
	case 8:		// ctrl-H- move left    (This may be ERASE char)
	case 0x7f:	// DEL- move left   (This may be ERASE char)
		do {
			dot_left();
		} while (--cmdcnt &gt; 0);
		break;
	case 10:			// Newline ^J
	case 'j':			// j- goto next line, same col
	case KEYCODE_DOWN:	// cursor key Down
	case 13:			// Carriage Return ^M
	case '+':			// +- goto next line
		q = dot;
		do {
			p = next_line(q);
			if (p == end_line(q)) {
				indicate_error();
				goto dc1;
			}
			q = p;
		} while (--cmdcnt &gt; 0);
		dot = q;
		if (c == 13 || c == '+') {
			dot_skip_over_ws();
		} else {
			// try to stay in saved column
			dot = cindex == C_END ? end_line(dot) : move_to_col(dot, cindex);
			keep_index = TRUE;
		}
		break;
	case 12:			// ctrl-L  force redraw whole screen
	case 18:			// ctrl-R  force redraw
		redraw(TRUE);	// this will redraw the entire display
		break;
	case 21:			// ctrl-U  scroll up half screen
		dot_scroll((rows - 2) / 2, -1);
		break;
	case 25:			// ctrl-Y  scroll up one line
		dot_scroll(1, -1);
		break;
	case 27:			// esc
		if (cmd_mode == 0)
			indicate_error();
		cmd_mode = 0;	// stop inserting
		undo_queue_commit();
		end_cmd_q();
		last_status_cksum = 0;	// force status update
		break;
	case ' ':			// move right
	case 'l':			// move right
	case KEYCODE_RIGHT:	// Cursor Key Right
		do {
			dot_right();
		} while (--cmdcnt &gt; 0);
		break;
#if ENABLE_FEATURE_VI_YANKMARK
	case '"':			// "- name a register to use for Delete/Yank
		c1 = (get_one_char() | 0x20) - 'a'; // | 0x20 is tolower()
		if ((unsigned)c1 &lt;= 25) { // a-z?
			YDreg = c1;
		} else {
			indicate_error();
		}
		break;
	case '\'':			// '- goto a specific mark
		c1 = (get_one_char() | 0x20);
		if ((unsigned)(c1 - 'a') &lt;= 25) { // a-z?
			c1 = (c1 - 'a');
			// get the b-o-l
			q = mark[c1];
			if (text &lt;= q &amp;&amp; q &lt; end) {
				dot = q;
				dot_begin();	// go to B-o-l
				dot_skip_over_ws();
			} else {
				indicate_error();
			}
		} else if (c1 == '\'') {	// goto previous context
			dot = swap_context(dot);	// swap current and previous context
			dot_begin();	// go to B-o-l
			dot_skip_over_ws();
#if ENABLE_FEATURE_VI_YANKMARK
			orig_dot = dot;	// this doesn't update stored contexts
#endif
		} else {
			indicate_error();
		}
		break;
	case 'm':			// m- Mark a line
		// this is really stupid.  If there are any inserts or deletes
		// between text[0] and dot then this mark will not point to the
		// correct location! It could be off by many lines!
		// Well..., at least its quick and dirty.
		c1 = (get_one_char() | 0x20) - 'a';
		if ((unsigned)c1 &lt;= 25) { // a-z?
			// remember the line
			mark[c1] = dot;
		} else {
			indicate_error();
		}
		break;
	case 'P':			// P- Put register before
	case 'p':			// p- put register after
		p = reg[YDreg];
		if (p == NULL) {
			status_line_bold("Nothing in register %c", what_reg());
			break;
		}
		cnt = 0;
		i = cmdcnt ?: 1;
		// are we putting whole lines or strings
		if (regtype[YDreg] == WHOLE) {
			if (c == 'P') {
				dot_begin();	// putting lines- Put above
			}
			else /* if ( c == 'p') */ {
				// are we putting after very last line?
				if (end_line(dot) == (end - 1)) {
					dot = end;	// force dot to end of text[]
				} else {
					dot_next();	// next line, then put before
				}
			}
		} else {
			if (c == 'p')
				dot_right();	// move to right, can move to NL
			// how far to move cursor if register doesn't have a NL
			if (strchr(p, '\n') == NULL)
				cnt = i * strlen(p) - 1;
		}
		do {
			// dot is adjusted if text[] is reallocated so we don't have to
			string_insert(dot, p, allow_undo);	// insert the string
# if ENABLE_FEATURE_VI_UNDO
			allow_undo = ALLOW_UNDO_CHAIN;
# endif
		} while (--cmdcnt &gt; 0);
		dot += cnt;
		dot_skip_over_ws();
# if ENABLE_FEATURE_VI_YANKMARK &amp;&amp; ENABLE_FEATURE_VI_VERBOSE_STATUS
		yank_status("Put", p, i);
# endif
		end_cmd_q();	// stop adding to q
		break;
	case 'U':			// U- Undo; replace current line with original version
		if (reg[Ureg] != NULL) {
			p = begin_line(dot);
			q = end_line(dot);
			p = text_hole_delete(p, q, ALLOW_UNDO);	// delete cur line
			p += string_insert(p, reg[Ureg], ALLOW_UNDO_CHAIN);	// insert orig line
			dot = p;
			dot_skip_over_ws();
# if ENABLE_FEATURE_VI_YANKMARK &amp;&amp; ENABLE_FEATURE_VI_VERBOSE_STATUS
			yank_status("Undo", reg[Ureg], 1);
# endif
		}
		break;
#endif /* FEATURE_VI_YANKMARK */
#if ENABLE_FEATURE_VI_UNDO
	case 'u':	// u- undo last operation
		undo_pop();
		break;
#endif
	case '$':			// $- goto end of line
	case KEYCODE_END:		// Cursor Key End
		for (;;) {
			dot = end_line(dot);
			if (--cmdcnt &lt;= 0)
				break;
			dot_next();
		}
		cindex = C_END;
		keep_index = TRUE;
		break;
	case '%':			// %- find matching char of pair () [] {}
		for (q = dot; q &lt; end &amp;&amp; *q != '\n'; q++) {
			if (strchr("()[]{}", *q) != NULL) {
				// we found half of a pair
				p = find_pair(q, *q);
				if (p == NULL) {
					indicate_error();
				} else {
					dot = p;
				}
				break;
			}
		}
		if (*q == '\n')
			indicate_error();
		break;
	case 'f':			// f- forward to a user specified char
	case 'F':			// F- backward to a user specified char
	case 't':			// t- move to char prior to next x
	case 'T':			// T- move to char after previous x
		last_search_char = get_one_char();	// get the search char
		last_search_cmd = c;
		// fall through
	case ';':			// ;- look at rest of line for last search char
	case ',':           // ,- repeat latest search in opposite direction
		dot_to_char(c != ',' ? last_search_cmd : last_search_cmd ^ 0x20);
		break;
#if ENABLE_FEATURE_VI_DOT_CMD
	case '.':			// .- repeat the last modifying command
		// Stuff the last_modifying_cmd back into stdin
		// and let it be re-executed.
		if (lmc_len != 0) {
			if (cmdcnt)	// update saved count if current count is non-zero
				dotcnt = cmdcnt;
			last_modifying_cmd[lmc_len] = '\0';
			ioq = ioq_start = xasprintf("%u%s", dotcnt, last_modifying_cmd);
		}
		break;
#endif
#if ENABLE_FEATURE_VI_SEARCH
	case 'N':			// N- backward search for last pattern
		dir = last_search_pattern[0] == '/' ? BACK : FORWARD;
		goto dc4;		// now search for pattern
		break;
	case '?':			// ?- backward search for a pattern
	case '/':			// /- forward search for a pattern
		buf[0] = c;
		buf[1] = '\0';
		q = get_input_line(buf);	// get input line- use "status line"
		if (!q[0])	// user changed mind and erased the "/"-  do nothing
			break;
		if (!q[1]) {	// if no pat re-use old pat
			if (last_search_pattern[0])
				last_search_pattern[0] = c;
		} else {	// strlen(q) &gt; 1: new pat- save it and find
			free(last_search_pattern);
			last_search_pattern = xstrdup(q);
		}
		// fall through
	case 'n':			// n- repeat search for last pattern
		// search rest of text[] starting at next char
		// if search fails "dot" is unchanged
		dir = last_search_pattern[0] == '/' ? FORWARD : BACK;
 dc4:
		if (last_search_pattern[1] == '\0') {
			status_line_bold("No previous search");
			break;
		}
		do {
			q = char_search(dot + dir, last_search_pattern + 1,
						(dir &lt;&lt; 1) | FULL);
			if (q != NULL) {
				dot = q;	// good search, update "dot"
			} else {
				// no pattern found between "dot" and top/bottom of file
				// continue from other end of file
				const char *msg;
				q = char_search(dir == FORWARD ? text : end - 1,
						last_search_pattern + 1, (dir &lt;&lt; 1) | FULL);
				if (q != NULL) {	// found something
					dot = q;	// found new pattern- goto it
					msg = "search hit %s, continuing at %s";
				} else {	// pattern is nowhere in file
					cmdcnt = 0;	// force exit from loop
					msg = "Pattern not found";
				}
				if (dir == FORWARD)
					status_line_bold(msg, "BOTTOM", "TOP");
				else
					status_line_bold(msg, "TOP", "BOTTOM");
			}
		} while (--cmdcnt &gt; 0);
		break;
	case '{':			// {- move backward paragraph
	case '}':			// }- move forward paragraph
		dir = c == '}' ? FORWARD : BACK;
		do {
			int skip = TRUE; // initially skip consecutive empty lines
			while (dir == FORWARD ? dot &lt; end - 1 : dot &gt; text) {
				if (*dot == '\n' &amp;&amp; dot[dir] == '\n') {
					if (!skip) {
						if (dir == FORWARD)
							++dot;	// move to next blank line
						goto dc2;
					}
				}
				else {
					skip = FALSE;
				}
				dot += dir;
			}
			goto dc6; // end of file
 dc2:		continue;
		} while (--cmdcnt &gt; 0);
		break;
#endif /* FEATURE_VI_SEARCH */
	case '0':			// 0- goto beginning of line
	case '1':			// 1-
	case '2':			// 2-
	case '3':			// 3-
	case '4':			// 4-
	case '5':			// 5-
	case '6':			// 6-
	case '7':			// 7-
	case '8':			// 8-
	case '9':			// 9-
		if (c == '0' &amp;&amp; cmdcnt &lt; 1) {
			dot_begin();	// this was a standalone zero
		} else {
			cmdcnt = cmdcnt * 10 + (c - '0');	// this 0 is part of a number
		}
		break;
	case ':':			// :- the colon mode commands
		p = get_input_line(":");	// get input line- use "status line"
		colon(p);		// execute the command
		break;
	case '&lt;':			// &lt;- Left  shift something
	case '&gt;':			// &gt;- Right shift something
		cnt = count_lines(text, dot);	// remember what line we are on
		if (find_range(&amp;p, &amp;q, c) == -1)
			goto dc6;
		i = count_lines(p, q);	// # of lines we are shifting
		for (p = begin_line(p); i &gt; 0; i--, p = next_line(p)) {
			if (c == '&lt;') {
				// shift left- remove tab or tabstop spaces
				if (*p == '\t') {
					// shrink buffer 1 char
					text_hole_delete(p, p, allow_undo);
				} else if (*p == ' ') {
					// we should be calculating columns, not just SPACE
					for (j = 0; *p == ' ' &amp;&amp; j &lt; tabstop; j++) {
						text_hole_delete(p, p, allow_undo);
#if ENABLE_FEATURE_VI_UNDO
						allow_undo = ALLOW_UNDO_CHAIN;
#endif
					}
				}
			} else if (/* c == '&gt;' &amp;&amp; */ p != end_line(p)) {
				// shift right -- add tab or tabstop spaces on non-empty lines
				char_insert(p, '\t', allow_undo);
			}
#if ENABLE_FEATURE_VI_UNDO
			allow_undo = ALLOW_UNDO_CHAIN;
#endif
		}
		dot = find_line(cnt);	// what line were we on
		dot_skip_over_ws();
		end_cmd_q();	// stop adding to q
		break;
	case 'A':			// A- append at e-o-l
		dot_end();		// go to e-o-l
		//**** fall through to ... 'a'
	case 'a':			// a- append after current char
		if (*dot != '\n')
			dot++;
		goto dc_i;
		break;
	case 'B':			// B- back a blank-delimited Word
	case 'E':			// E- end of a blank-delimited word
	case 'W':			// W- forward a blank-delimited word
		dir = FORWARD;
		if (c == 'B')
			dir = BACK;
		do {
			if (c == 'W' || isspace(dot[dir])) {
				dot = skip_thing(dot, 1, dir, S_TO_WS);
				dot = skip_thing(dot, 2, dir, S_OVER_WS);
			}
			if (c != 'W')
				dot = skip_thing(dot, 1, dir, S_BEFORE_WS);
		} while (--cmdcnt &gt; 0);
		break;
	case 'C':			// C- Change to e-o-l
	case 'D':			// D- delete to e-o-l
		save_dot = dot;
		dot = dollar_line(dot);	// move to before NL
		// copy text into a register and delete
		dot = yank_delete(save_dot, dot, PARTIAL, YANKDEL, ALLOW_UNDO);	// delete to e-o-l
		if (c == 'C')
			goto dc_i;	// start inserting
#if ENABLE_FEATURE_VI_DOT_CMD
		if (c == 'D')
			end_cmd_q();	// stop adding to q
#endif
		break;
	case 'g': // 'gg' goto a line number (vim) (default: very first line)
		c1 = get_one_char();
		if (c1 != 'g') {
			buf[0] = 'g';
			// c1 &lt; 0 if the key was special. Try "g&lt;up-arrow&gt;"
			// TODO: if Unicode?
			buf[1] = (c1 &gt;= 0 ? c1 : '*');
			buf[2] = '\0';
			not_implemented(buf);
			cmd_error = TRUE;
			break;
		}
		if (cmdcnt == 0)
			cmdcnt = 1;
		// fall through
	case 'G':		// G- goto to a line number (default= E-O-F)
		dot = end - 1;				// assume E-O-F
		if (cmdcnt &gt; 0) {
			dot = find_line(cmdcnt);	// what line is #cmdcnt
		}
		dot_begin();
		dot_skip_over_ws();
		break;
	case 'H':			// H- goto top line on screen
		dot = screenbegin;
		if (cmdcnt &gt; (rows - 1)) {
			cmdcnt = (rows - 1);
		}
		while (--cmdcnt &gt; 0) {
			dot_next();
		}
		dot_begin();
		dot_skip_over_ws();
		break;
	case 'I':			// I- insert before first non-blank
		dot_begin();	// 0
		dot_skip_over_ws();
		//**** fall through to ... 'i'
	case 'i':			// i- insert before current char
	case KEYCODE_INSERT:	// Cursor Key Insert
 dc_i:
#if ENABLE_FEATURE_VI_SETOPTS
		newindent = -1;
#endif
		cmd_mode = 1;	// start inserting
		undo_queue_commit();	// commit queue when cmd_mode changes
		break;
	case 'J':			// J- join current and next lines together
		do {
			dot_end();		// move to NL
			if (dot &lt; end - 1) {	// make sure not last char in text[]
#if ENABLE_FEATURE_VI_UNDO
				undo_push(dot, 1, UNDO_DEL);
				*dot++ = ' ';	// replace NL with space
				undo_push((dot - 1), 1, UNDO_INS_CHAIN);
#else
				*dot++ = ' ';
				modified_count++;
#endif
				while (isblank(*dot)) {	// delete leading WS
					text_hole_delete(dot, dot, ALLOW_UNDO_CHAIN);
				}
			}
		} while (--cmdcnt &gt; 0);
		end_cmd_q();	// stop adding to q
		break;
	case 'L':			// L- goto bottom line on screen
		dot = end_screen();
		if (cmdcnt &gt; (rows - 1)) {
			cmdcnt = (rows - 1);
		}
		while (--cmdcnt &gt; 0) {
			dot_prev();
		}
		dot_begin();
		dot_skip_over_ws();
		break;
	case 'M':			// M- goto middle line on screen
		dot = screenbegin;
		for (cnt = 0; cnt &lt; (rows-1) / 2; cnt++)
			dot = next_line(dot);
		dot_skip_over_ws();
		break;
	case 'O':			// O- open an empty line above
		dot_begin();
#if ENABLE_FEATURE_VI_SETOPTS
		// special case: use indent of current line
		newindent = get_column(dot + indent_len(dot));
#endif
		goto dc3;
	case 'o':			// o- open an empty line below
		dot_end();
 dc3:
#if ENABLE_FEATURE_VI_SETOPTS
		cmd_mode = 1;	// switch to insert mode early
#endif
		dot = char_insert(dot, '\n', ALLOW_UNDO);
		if (c == 'O' &amp;&amp; !autoindent) {
			// done in char_insert() for 'O'+autoindent
			dot_prev();
		}
		goto dc_i;
		break;
	case 'R':			// R- continuous Replace char
 dc5:
		cmd_mode = 2;
		undo_queue_commit();
		rstart = dot;
		break;
	case KEYCODE_DELETE:
		if (dot &lt; end - 1)
			dot = yank_delete(dot, dot, PARTIAL, YANKDEL, ALLOW_UNDO);
		break;
	case 'X':			// X- delete char before dot
	case 'x':			// x- delete the current char
	case 's':			// s- substitute the current char
		dir = 0;
		if (c == 'X')
			dir = -1;
		do {
			if (dot[dir] != '\n') {
				if (c == 'X')
					dot--;	// delete prev char
				dot = yank_delete(dot, dot, PARTIAL, YANKDEL, allow_undo);	// delete char
#if ENABLE_FEATURE_VI_UNDO
				allow_undo = ALLOW_UNDO_CHAIN;
#endif
			}
		} while (--cmdcnt &gt; 0);
		end_cmd_q();	// stop adding to q
		if (c == 's')
			goto dc_i;	// start inserting
		break;
	case 'Z':			// Z- if modified, {write}; exit
		// ZZ means to save file (if necessary), then exit
		c1 = get_one_char();
		if (c1 != 'Z') {
			indicate_error();
			break;
		}
		if (modified_count) {
			if (ENABLE_FEATURE_VI_READONLY &amp;&amp; readonly_mode &amp;&amp; current_filename) {
				status_line_bold("'%s' is read only", current_filename);
				break;
			}
			cnt = file_write(current_filename, text, end - 1);
			if (cnt &lt; 0) {
				if (cnt == -1)
					status_line_bold("Write error: "STRERROR_FMT STRERROR_ERRNO);
			} else if (cnt == (end - 1 - text + 1)) {
				editing = 0;
			}
		} else {
			editing = 0;
		}
		// are there other files to edit?
		j = cmdline_filecnt - optind - 1;
		if (editing == 0 &amp;&amp; j &gt; 0) {
			editing = 1;
			modified_count = 0;
			last_modified_count = -1;
			status_line_bold("%u more file(s) to edit", j);
		}
		break;
	case '^':			// ^- move to first non-blank on line
		dot_begin();
		dot_skip_over_ws();
		break;
	case 'b':			// b- back a word
	case 'e':			// e- end of word
		dir = FORWARD;
		if (c == 'b')
			dir = BACK;
		do {
			if ((dot + dir) &lt; text || (dot + dir) &gt; end - 1)
				break;
			dot += dir;
			if (isspace(*dot)) {
				dot = skip_thing(dot, (c == 'e') ? 2 : 1, dir, S_OVER_WS);
			}
			if (isalnum(*dot) || *dot == '_') {
				dot = skip_thing(dot, 1, dir, S_END_ALNUM);
			} else if (ispunct(*dot)) {
				dot = skip_thing(dot, 1, dir, S_END_PUNCT);
			}
		} while (--cmdcnt &gt; 0);
		break;
	case 'c':			// c- change something
	case 'd':			// d- delete something
#if ENABLE_FEATURE_VI_YANKMARK
	case 'y':			// y- yank   something
	case 'Y':			// Y- Yank a line
#endif
	{
		int yf = YANKDEL;	// assume either "c" or "d"
		int buftype;
#if ENABLE_FEATURE_VI_YANKMARK
# if ENABLE_FEATURE_VI_VERBOSE_STATUS
		char *savereg = reg[YDreg];
# endif
		if (c == 'y' || c == 'Y')
			yf = YANKONLY;
#endif
		// determine range, and whether it spans lines
		buftype = find_range(&amp;p, &amp;q, c);
		if (buftype == -1)	// invalid range
			goto dc6;
		if (buftype == WHOLE) {
			save_dot = p;	// final cursor position is start of range
			p = begin_line(p);
#if ENABLE_FEATURE_VI_SETOPTS
			if (c == 'c')	// special case: use indent of current line
				newindent = get_column(p + indent_len(p));
#endif
			q = end_line(q);
		}
		dot = yank_delete(p, q, buftype, yf, ALLOW_UNDO);	// delete word
		if (buftype == WHOLE) {
			if (c == 'c') {
#if ENABLE_FEATURE_VI_SETOPTS
				cmd_mode = 1;	// switch to insert mode early
#endif
				dot = char_insert(dot, '\n', ALLOW_UNDO_CHAIN);
				// on the last line of file don't move to prev line,
				// handled in char_insert() if autoindent is enabled
				if (dot != (end-1) &amp;&amp; !autoindent) {
					dot_prev();
				}
			} else if (c == 'd') {
				dot_begin();
				dot_skip_over_ws();
			} else {
				dot = save_dot;
			}
		}
		// if CHANGING, not deleting, start inserting after the delete
		if (c == 'c') {
			goto dc_i;	// start inserting
		}
#if ENABLE_FEATURE_VI_YANKMARK &amp;&amp; ENABLE_FEATURE_VI_VERBOSE_STATUS
		// only update status if a yank has actually happened
		if (reg[YDreg] != savereg)
			yank_status(c == 'd' ? "Delete" : "Yank", reg[YDreg], 1);
#endif
 dc6:
		end_cmd_q();	// stop adding to q
		break;
	}
	case 'k':			// k- goto prev line, same col
	case KEYCODE_UP:		// cursor key Up
	case '-':			// -- goto prev line
		q = dot;
		do {
			p = prev_line(q);
			if (p == begin_line(q)) {
				indicate_error();
				goto dc1;
			}
			q = p;
		} while (--cmdcnt &gt; 0);
		dot = q;
		if (c == '-') {
			dot_skip_over_ws();
		} else {
			// try to stay in saved column
			dot = cindex == C_END ? end_line(dot) : move_to_col(dot, cindex);
			keep_index = TRUE;
		}
		break;
	case 'r':			// r- replace the current char with user input
		c1 = get_one_char();	// get the replacement char
		if (c1 != 27) {
			if (end_line(dot) - dot &lt; (cmdcnt ?: 1)) {
				indicate_error();
				goto dc6;
			}
			do {
				dot = text_hole_delete(dot, dot, allow_undo);
#if ENABLE_FEATURE_VI_UNDO
				allow_undo = ALLOW_UNDO_CHAIN;
#endif
				dot = char_insert(dot, c1, allow_undo);
			} while (--cmdcnt &gt; 0);
			dot_left();
		}
		end_cmd_q();	// stop adding to q
		break;
	case 'w':			// w- forward a word
		do {
			if (isalnum(*dot) || *dot == '_') {	// we are on ALNUM
				dot = skip_thing(dot, 1, FORWARD, S_END_ALNUM);
			} else if (ispunct(*dot)) {	// we are on PUNCT
				dot = skip_thing(dot, 1, FORWARD, S_END_PUNCT);
			}
			if (dot &lt; end - 1)
				dot++;		// move over word
			if (isspace(*dot)) {
				dot = skip_thing(dot, 2, FORWARD, S_OVER_WS);
			}
		} while (--cmdcnt &gt; 0);
		break;
	case 'z':			// z-
		c1 = get_one_char();	// get the replacement char
		cnt = 0;
		if (c1 == '.')
			cnt = (rows - 2) / 2;	// put dot at center
		if (c1 == '-')
			cnt = rows - 2;	// put dot at bottom
		screenbegin = begin_line(dot);	// start dot at top
		dot_scroll(cnt, -1);
		break;
	case '|':			// |- move to column "cmdcnt"
		dot = move_to_col(dot, cmdcnt - 1);	// try to move to column
		break;
	case '~':			// ~- flip the case of letters   a-z -&gt; A-Z
		do {
#if ENABLE_FEATURE_VI_UNDO
			if (isalpha(*dot)) {
				undo_push(dot, 1, undo_del);
				*dot = islower(*dot) ? toupper(*dot) : tolower(*dot);
				undo_push(dot, 1, UNDO_INS_CHAIN);
				undo_del = UNDO_DEL_CHAIN;
			}
#else
			if (islower(*dot)) {
				*dot = toupper(*dot);
				modified_count++;
			} else if (isupper(*dot)) {
				*dot = tolower(*dot);
				modified_count++;
			}
#endif
			dot_right();
		} while (--cmdcnt &gt; 0);
		end_cmd_q();	// stop adding to q
		break;
		//----- The Cursor and Function Keys -----------------------------
	case KEYCODE_HOME:	// Cursor Key Home
		dot_begin();
		break;
		// The Fn keys could point to do_macro which could translate them
#if 0
	case KEYCODE_FUN1:	// Function Key F1
	case KEYCODE_FUN2:	// Function Key F2
	case KEYCODE_FUN3:	// Function Key F3
	case KEYCODE_FUN4:	// Function Key F4
	case KEYCODE_FUN5:	// Function Key F5
	case KEYCODE_FUN6:	// Function Key F6
	case KEYCODE_FUN7:	// Function Key F7
	case KEYCODE_FUN8:	// Function Key F8
	case KEYCODE_FUN9:	// Function Key F9
	case KEYCODE_FUN10:	// Function Key F10
	case KEYCODE_FUN11:	// Function Key F11
	case KEYCODE_FUN12:	// Function Key F12
		break;
#endif
	}

 dc1:
	// if text[] just became empty, add back an empty line
	if (end == text) {
		char_insert(text, '\n', NO_UNDO);	// start empty buf with dummy line
		dot = text;
	}
	// it is OK for dot to exactly equal to end, otherwise check dot validity
	if (dot != end) {
		dot = bound_dot(dot);	// make sure "dot" is valid
	}
#if ENABLE_FEATURE_VI_YANKMARK
	if (dot != orig_dot)
		check_context(c);	// update the current context
#endif

	if (!isdigit(c))
		cmdcnt = 0;		// cmd was not a number, reset cmdcnt
	cnt = dot - begin_line(dot);
	// Try to stay off of the Newline
	if (*dot == '\n' &amp;&amp; cnt &gt; 0 &amp;&amp; cmd_mode == 0)
		dot--;
}

// NB!  the CRASHME code is unmaintained, and doesn't currently build
#if ENABLE_FEATURE_VI_CRASHME
static int totalcmds = 0;
static int Mp = 85;             // Movement command Probability
static int Np = 90;             // Non-movement command Probability
static int Dp = 96;             // Delete command Probability
static int Ip = 97;             // Insert command Probability
static int Yp = 98;             // Yank command Probability
static int Pp = 99;             // Put command Probability
static int M = 0, N = 0, I = 0, D = 0, Y = 0, P = 0, U = 0;
static const char chars[20] = "\t012345 abcdABCD-=.$";
static const char *const words[20] = {
	"this", "is", "a", "test",
	"broadcast", "the", "emergency", "of",
	"system", "quick", "brown", "fox",
	"jumped", "over", "lazy", "dogs",
	"back", "January", "Febuary", "March"
};
static const char *const lines[20] = {
	"You should have received a copy of the GNU General Public License\n",
	"char c, cm, *cmd, *cmd1;\n",
	"generate a command by percentages\n",
	"Numbers may be typed as a prefix to some commands.\n",
	"Quit, discarding changes!\n",
	"Forced write, if permission originally not valid.\n",
	"In general, any ex or ed command (such as substitute or delete).\n",
	"I have tickets available for the Blazers vs LA Clippers for Monday, Janurary 1 at 1:00pm.\n",
	"Please get w/ me and I will go over it with you.\n",
	"The following is a list of scheduled, committed changes.\n",
	"1.   Launch Norton Antivirus (Start, Programs, Norton Antivirus)\n",
	"Reminder....Town Meeting in Central Perk cafe today at 3:00pm.\n",
	"Any question about transactions please contact Sterling Huxley.\n",
	"I will try to get back to you by Friday, December 31.\n",
	"This Change will be implemented on Friday.\n",
	"Let me know if you have problems accessing this;\n",
	"Sterling Huxley recently added you to the access list.\n",
	"Would you like to go to lunch?\n",
	"The last command will be automatically run.\n",
	"This is too much english for a computer geek.\n",
};
static char *multilines[20] = {
	"You should have received a copy of the GNU General Public License\n",
	"char c, cm, *cmd, *cmd1;\n",
	"generate a command by percentages\n",
	"Numbers may be typed as a prefix to some commands.\n",
	"Quit, discarding changes!\n",
	"Forced write, if permission originally not valid.\n",
	"In general, any ex or ed command (such as substitute or delete).\n",
	"I have tickets available for the Blazers vs LA Clippers for Monday, Janurary 1 at 1:00pm.\n",
	"Please get w/ me and I will go over it with you.\n",
	"The following is a list of scheduled, committed changes.\n",
	"1.   Launch Norton Antivirus (Start, Programs, Norton Antivirus)\n",
	"Reminder....Town Meeting in Central Perk cafe today at 3:00pm.\n",
	"Any question about transactions please contact Sterling Huxley.\n",
	"I will try to get back to you by Friday, December 31.\n",
	"This Change will be implemented on Friday.\n",
	"Let me know if you have problems accessing this;\n",
	"Sterling Huxley recently added you to the access list.\n",
	"Would you like to go to lunch?\n",
	"The last command will be automatically run.\n",
	"This is too much english for a computer geek.\n",
};

// create a random command to execute
static void crash_dummy()
{
	static int sleeptime;   // how long to pause between commands
	char c, cm, *cmd, *cmd1;
	int i, cnt, thing, rbi, startrbi, percent;

	// "dot" movement commands
	cmd1 = " \n\r\002\004\005\006\025\0310^$-+wWeEbBhjklHL";

	// is there already a command running?
	if (readbuffer[0] &gt; 0)
		goto cd1;
 cd0:
	readbuffer[0] = 'X';
	startrbi = rbi = 1;
	sleeptime = 0;          // how long to pause between commands
	memset(readbuffer, '\0', sizeof(readbuffer));
	// generate a command by percentages
	percent = (int) lrand48() % 100;        // get a number from 0-99
	if (percent &lt; Mp) {     //  Movement commands
		// available commands
		cmd = cmd1;
		M++;
	} else if (percent &lt; Np) {      //  non-movement commands
		cmd = "mz&lt;&gt;\'\"";       // available commands
		N++;
	} else if (percent &lt; Dp) {      //  Delete commands
		cmd = "dx";             // available commands
		D++;
	} else if (percent &lt; Ip) {      //  Inset commands
		cmd = "iIaAsrJ";        // available commands
		I++;
	} else if (percent &lt; Yp) {      //  Yank commands
		cmd = "yY";             // available commands
		Y++;
	} else if (percent &lt; Pp) {      //  Put commands
		cmd = "pP";             // available commands
		P++;
	} else {
		// We do not know how to handle this command, try again
		U++;
		goto cd0;
	}
	// randomly pick one of the available cmds from "cmd[]"
	i = (int) lrand48() % strlen(cmd);
	cm = cmd[i];
	if (strchr(":\024", cm))
		goto cd0;               // dont allow colon or ctrl-T commands
	readbuffer[rbi++] = cm; // put cmd into input buffer

	// now we have the command-
	// there are 1, 2, and multi char commands
	// find out which and generate the rest of command as necessary
	if (strchr("dmryz&lt;&gt;\'\"", cm)) {        // 2-char commands
		cmd1 = " \n\r0$^-+wWeEbBhjklHL";
		if (cm == 'm' || cm == '\'' || cm == '\"') {    // pick a reg[]
			cmd1 = "abcdefghijklmnopqrstuvwxyz";
		}
		thing = (int) lrand48() % strlen(cmd1); // pick a movement command
		c = cmd1[thing];
		readbuffer[rbi++] = c;  // add movement to input buffer
	}
	if (strchr("iIaAsc", cm)) {     // multi-char commands
		if (cm == 'c') {
			// change some thing
			thing = (int) lrand48() % strlen(cmd1); // pick a movement command
			c = cmd1[thing];
			readbuffer[rbi++] = c;  // add movement to input buffer
		}
		thing = (int) lrand48() % 4;    // what thing to insert
		cnt = (int) lrand48() % 10;     // how many to insert
		for (i = 0; i &lt; cnt; i++) {
			if (thing == 0) {       // insert chars
				readbuffer[rbi++] = chars[((int) lrand48() % strlen(chars))];
			} else if (thing == 1) {        // insert words
				strcat(readbuffer, words[(int) lrand48() % 20]);
				strcat(readbuffer, " ");
				sleeptime = 0;  // how fast to type
			} else if (thing == 2) {        // insert lines
				strcat(readbuffer, lines[(int) lrand48() % 20]);
				sleeptime = 0;  // how fast to type
			} else {        // insert multi-lines
				strcat(readbuffer, multilines[(int) lrand48() % 20]);
				sleeptime = 0;  // how fast to type
			}
		}
		strcat(readbuffer, ESC);
	}
	readbuffer[0] = strlen(readbuffer + 1);
 cd1:
	totalcmds++;
	if (sleeptime &gt; 0)
		mysleep(sleeptime);      // sleep 1/100 sec
}

// test to see if there are any errors
static void crash_test()
{
	static time_t oldtim;

	time_t tim;
	char d[2], msg[80];

	msg[0] = '\0';
	if (end &lt; text) {
		strcat(msg, "end&lt;text ");
	}
	if (end &gt; textend) {
		strcat(msg, "end&gt;textend ");
	}
	if (dot &lt; text) {
		strcat(msg, "dot&lt;text ");
	}
	if (dot &gt; end) {
		strcat(msg, "dot&gt;end ");
	}
	if (screenbegin &lt; text) {
		strcat(msg, "screenbegin&lt;text ");
	}
	if (screenbegin &gt; end - 1) {
		strcat(msg, "screenbegin&gt;end-1 ");
	}

	if (msg[0]) {
		printf("\n\n%d: \'%c\' %s\n\n\n%s[Hit return to continue]%s",
			totalcmds, last_input_char, msg, ESC_BOLD_TEXT, ESC_NORM_TEXT);
		fflush_all();
		while (safe_read(STDIN_FILENO, d, 1) &gt; 0) {
			if (d[0] == '\n' || d[0] == '\r')
				break;
		}
	}
	tim = time(NULL);
	if (tim &gt;= (oldtim + 3)) {
		sprintf(status_buffer,
				"Tot=%d: M=%d N=%d I=%d D=%d Y=%d P=%d U=%d size=%d",
				totalcmds, M, N, I, D, Y, P, U, end - text + 1);
		oldtim = tim;
	}
}
#endif

#if ENABLE_FEATURE_VI_COLON
static void run_cmds(char *p)
{
	while (p) {
		char *q = p;
		p = strchr(q, '\n');
		if (p)
			while (*p == '\n')
				*p++ = '\0';
		if (strlen(q) &lt; MAX_INPUT_LEN)
			colon(q);
	}
}
#endif

static void edit_file(char *fn)
{
#if ENABLE_FEATURE_VI_YANKMARK
#define cur_line edit_file__cur_line
#endif
	int c;
#if ENABLE_FEATURE_VI_USE_SIGNALS
	int sig;
#endif

	editing = 1;	// 0 = exit, 1 = one file, 2 = multiple files
	rawmode();
	rows = 24;
	columns = 80;
	IF_FEATURE_VI_ASK_TERMINAL(G.get_rowcol_error =) query_screen_dimensions();
#if ENABLE_FEATURE_VI_ASK_TERMINAL
	if (G.get_rowcol_error /* TODO? &amp;&amp; no input on stdin */) {
		uint64_t k;
		write1(ESC"[999;999H" ESC"[6n");
		fflush_all();
		k = safe_read_key(STDIN_FILENO, readbuffer, /*timeout_ms:*/ 100);
		if ((int32_t)k == KEYCODE_CURSOR_POS) {
			uint32_t rc = (k &gt;&gt; 32);
			columns = (rc &amp; 0x7fff);
			if (columns &gt; MAX_SCR_COLS)
				columns = MAX_SCR_COLS;
			rows = ((rc &gt;&gt; 16) &amp; 0x7fff);
			if (rows &gt; MAX_SCR_ROWS)
				rows = MAX_SCR_ROWS;
		}
	}
#endif
	new_screen(rows, columns);	// get memory for virtual screen
	init_text_buffer(fn);

#if ENABLE_FEATURE_VI_YANKMARK
	YDreg = 26;			// default Yank/Delete reg
//	Ureg = 27; - const		// hold orig line for "U" cmd
	mark[26] = mark[27] = text;	// init "previous context"
#endif

#if ENABLE_FEATURE_VI_CRASHME
	last_input_char = '\0';
#endif
	crow = 0;
	ccol = 0;

#if ENABLE_FEATURE_VI_USE_SIGNALS
	signal(SIGWINCH, winch_handler);
	signal(SIGTSTP, tstp_handler);
	sig = sigsetjmp(restart, 1);
	if (sig != 0) {
		screenbegin = dot = text;
	}
	// int_handler() can jump to "restart",
	// must install handler *after* initializing "restart"
	signal(SIGINT, int_handler);
#endif

	cmd_mode = 0;		// 0=command  1=insert  2='R'eplace
	cmdcnt = 0;
	offset = 0;			// no horizontal offset
	c = '\0';
#if ENABLE_FEATURE_VI_DOT_CMD
	free(ioq_start);
	ioq_start = NULL;
	adding2q = 0;
#endif

#if ENABLE_FEATURE_VI_COLON
	while (initial_cmds)
		run_cmds((char *)llist_pop(&amp;initial_cmds));
#endif
	redraw(FALSE);			// dont force every col re-draw
	//------This is the main Vi cmd handling loop -----------------------
	while (editing &gt; 0) {
#if ENABLE_FEATURE_VI_CRASHME
		if (crashme &gt; 0) {
			if ((end - text) &gt; 1) {
				crash_dummy();	// generate a random command
			} else {
				crashme = 0;
				string_insert(text, "\n\n#####  Ran out of text to work on.  #####\n\n", NO_UNDO);
				dot = text;
				refresh(FALSE);
			}
		}
#endif
		c = get_one_char();	// get a cmd from user
#if ENABLE_FEATURE_VI_CRASHME
		last_input_char = c;
#endif
#if ENABLE_FEATURE_VI_YANKMARK
		// save a copy of the current line- for the 'U" command
		if (begin_line(dot) != cur_line) {
			cur_line = begin_line(dot);
			text_yank(begin_line(dot), end_line(dot), Ureg, PARTIAL);
		}
#endif
#if ENABLE_FEATURE_VI_DOT_CMD
		// If c is a command that changes text[],
		// (re)start remembering the input for the "." command.
		if (!adding2q
		 &amp;&amp; ioq_start == NULL
		 &amp;&amp; cmd_mode == 0 // command mode
		 &amp;&amp; c &gt; '\0' // exclude NUL and non-ASCII chars
		 &amp;&amp; c &lt; 0x7f // (Unicode and such)
		 &amp;&amp; strchr(modifying_cmds, c)
		) {
			start_new_cmd_q(c);
		}
#endif
		do_cmd(c);		// execute the user command

		// poll to see if there is input already waiting. if we are
		// not able to display output fast enough to keep up, skip
		// the display update until we catch up with input.
		if (!readbuffer[0] &amp;&amp; mysleep(0) == 0) {
			// no input pending - so update output
			refresh(FALSE);
			show_status_line();
		}
#if ENABLE_FEATURE_VI_CRASHME
		if (crashme &gt; 0)
			crash_test();	// test editor variables
#endif
	}
	//-------------------------------------------------------------------

	go_bottom_and_clear_to_eol();
	cookmode();
#undef cur_line
}

#define VI_OPTSTR \
	IF_FEATURE_VI_CRASHME("C") \
	IF_FEATURE_VI_COLON("c:*") \
	"Hh" \
	IF_FEATURE_VI_READONLY("R")

enum {
	IF_FEATURE_VI_CRASHME(OPTBIT_C,)
	IF_FEATURE_VI_COLON(OPTBIT_c,)
	OPTBIT_H,
	OPTBIT_h,
	IF_FEATURE_VI_READONLY(OPTBIT_R,)
	OPT_C = IF_FEATURE_VI_CRASHME(	(1 &lt;&lt; OPTBIT_C)) + 0,
	OPT_c = IF_FEATURE_VI_COLON(	(1 &lt;&lt; OPTBIT_c)) + 0,
	OPT_H = 1 &lt;&lt; OPTBIT_H,
	OPT_h = 1 &lt;&lt; OPTBIT_h,
	OPT_R = IF_FEATURE_VI_READONLY(	(1 &lt;&lt; OPTBIT_R)) + 0,
};

int vi_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
int vi_main(int argc, char **argv)
{
	int opts;

	INIT_G();

#if ENABLE_FEATURE_VI_UNDO
	//undo_stack_tail = NULL; - already is
# if ENABLE_FEATURE_VI_UNDO_QUEUE
	undo_queue_state = UNDO_EMPTY;
	//undo_q = 0; - already is
# endif
#endif

#if ENABLE_FEATURE_VI_CRASHME
	srand((long) getpid());
#endif
#ifdef NO_SUCH_APPLET_YET
	// if we aren't "vi", we are "view"
	if (ENABLE_FEATURE_VI_READONLY &amp;&amp; applet_name[2]) {
		SET_READONLY_MODE(readonly_mode);
	}
#endif

	// 0: all of our options are disabled by default in vim
	//vi_setops = 0;
	opts = getopt32(argv, VI_OPTSTR IF_FEATURE_VI_COLON(, &amp;initial_cmds));

#if ENABLE_FEATURE_VI_CRASHME
	if (opts &amp; OPT_C)
		crashme = 1;
#endif
	if (opts &amp; OPT_R)
		SET_READONLY_MODE(readonly_mode);
	if (opts &amp; OPT_H)
		show_help();
	if (opts &amp; (OPT_H | OPT_h)) {
		bb_show_usage();
		return 1;
	}

	argv += optind;
	cmdline_filecnt = argc - optind;

	//  1-  process EXINIT variable from environment
	//  2-  if EXINIT is unset process $HOME/.exrc file
	//  3-  process command line args
#if ENABLE_FEATURE_VI_COLON
	{
		const char *exinit = getenv("EXINIT");
		char *cmds = NULL;

		if (exinit) {
			cmds = xstrdup(exinit);
		} else {
			const char *home = getenv("HOME");

			if (home &amp;&amp; *home) {
				char *exrc = concat_path_file(home, ".exrc");
				struct stat st;

				// .exrc must belong to and only be writable by user
				if (stat(exrc, &amp;st) == 0) {
					if ((st.st_mode &amp; (S_IWGRP|S_IWOTH)) == 0
					 &amp;&amp; st.st_uid == getuid()
					) {
						cmds = xmalloc_open_read_close(exrc, NULL);
					} else {
						status_line_bold(".exrc: permission denied");
					}
				}
				free(exrc);
			}
		}

		if (cmds) {
			init_text_buffer(NULL);
			run_cmds(cmds);
			free(cmds);
		}
	}
#endif
	// "Save cursor, use alternate screen buffer, clear screen"
	write1(ESC"[?1049h");
	// This is the main file handling loop
	optind = 0;
	while (1) {
		edit_file(argv[optind]); // might be NULL on 1st iteration
		// NB: optind can be changed by ":next" and ":rewind" commands
		optind++;
		if (optind &gt;= cmdline_filecnt)
			break;
	}
	// "Use normal screen buffer, restore cursor"
	write1(ESC"[?1049l");

	return 0;
}
</code></pre></td></tr></table>
</div> <!-- class=content -->
<div class='footer'>generated by <a href='https://git.zx2c4.com/cgit/about/'>cgit v1.2.3</a> (<a href='https://git-scm.com/'>git 2.25.1</a>) at 2022-07-24 01:40:26 +0000</div>
</div> <!-- id=cgit -->
</body>
</html>
