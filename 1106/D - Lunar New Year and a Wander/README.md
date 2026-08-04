<h2><a href="https://codeforces.com/contest/1106/problem/D" target="_blank" rel="noopener noreferrer">1106D — Lunar New Year and a Wander</a></h2>

| | |
|---|---|
| **Difficulty** | 1500 |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1106D](https://codeforces.com/contest/1106/problem/D) |

## Topics
`data structures` `dfs and similar` `graphs` `greedy` `shortest paths`

---

## Problem Statement

<div class="header"><div class="title">D. Lunar New Year and a Wander</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p><span class="tex-font-style-it">Lunar New Year is approaching, and Bob decides to take a wander in a nearby park.</span></p><p>The park can be represented as a connected graph with $$$n$$$ nodes and $$$m$$$ bidirectional edges. Initially Bob is at the node $$$1$$$ and he records $$$1$$$ on his notebook. He can wander from one node to another through those bidirectional edges. Whenever he visits a node not recorded on his notebook, he records it. After he visits all nodes at least once, he stops wandering, thus finally a permutation of nodes $$$a_1, a_2, \ldots, a_n$$$ is recorded.</p><p>Wandering is a boring thing, but solving problems is fascinating. Bob wants to know the lexicographically smallest sequence of nodes he can record while wandering. Bob thinks this problem is trivial, and he wants you to solve it.</p><p>A sequence $$$x$$$ is lexicographically smaller than a sequence $$$y$$$ if and only if one of the following holds: </p><ul> <li> $$$x$$$ is a prefix of $$$y$$$, but $$$x \ne y$$$ (this is impossible in this problem as all considered sequences have the same length); </li><li> in the first position where $$$x$$$ and $$$y$$$ differ, the sequence $$$x$$$ has a smaller element than the corresponding element in $$$y$$$. </li></ul></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two positive integers $$$n$$$ and $$$m$$$ ($$$1 \leq n, m \leq 10^5$$$), denoting the number of nodes and edges, respectively.</p><p>The following $$$m$$$ lines describe the bidirectional edges in the graph. The $$$i$$$-th of these lines contains two integers $$$u_i$$$ and $$$v_i$$$ ($$$1 \leq u_i, v_i \leq n$$$), representing the nodes the $$$i$$$-th edge connects.</p><p>Note that the graph can have multiple edges connecting the same two nodes and self-loops. It is guaranteed that the graph is connected.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Output a line containing the lexicographically smallest sequence $$$a_1, a_2, \ldots, a_n$$$ Bob can record.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id004647231684201949" id="id007902632849386014" class="input-output-copier">Copy</div></div><pre id="id004647231684201949">3 2
1 2
1 3
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008215050688761546" id="id005076601558271951" class="input-output-copier">Copy</div></div><pre id="id008215050688761546">1 2 3 
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006779616511091402" id="id007547866310280166" class="input-output-copier">Copy</div></div><pre id="id006779616511091402">5 5
1 4
3 4
5 4
3 2
1 5
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0004657598361602844" id="id0005684689771382234" class="input-output-copier">Copy</div></div><pre id="id0004657598361602844">1 4 3 2 5 
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id002516656514864801" id="id008572898021037326" class="input-output-copier">Copy</div></div><pre id="id002516656514864801">10 10
1 4
6 8
2 5
3 7
9 4
5 6
3 4
8 10
8 9
1 10
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0010386307981549348" id="id003407415995563158" class="input-output-copier">Copy</div></div><pre id="id0010386307981549348">1 4 3 7 9 8 6 5 2 10 
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first sample, Bob's optimal wandering path could be $$$1 \rightarrow 2 \rightarrow 1 \rightarrow 3$$$. Therefore, Bob will obtain the sequence $$$\{1, 2, 3\}$$$, which is the lexicographically smallest one.</p><p>In the second sample, Bob's optimal wandering path could be $$$1 \rightarrow 4 \rightarrow 3 \rightarrow 2 \rightarrow 3 \rightarrow 4 \rightarrow 1 \rightarrow 5$$$. Therefore, Bob will obtain the sequence $$$\{1, 4, 3, 2, 5\}$$$, which is the lexicographically smallest one.</p></div>