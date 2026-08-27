<h2><a href="https://codeforces.com/contest/1036/problem/C" target="_blank" rel="noopener noreferrer">1036C — Classy Numbers</a></h2>

| | |
|---|---|
| **Difficulty** | 1900 |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1036C](https://codeforces.com/contest/1036/problem/C) |

## Topics
`combinatorics` `dp`

---

## Problem Statement

<div class="header"><div class="title">C. Classy Numbers</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Let's call some positive integer <span class="tex-font-style-it">classy</span> if its decimal representation contains no more than $$$3$$$ non-zero digits. For example, numbers $$$4$$$, $$$200000$$$, $$$10203$$$ are <span class="tex-font-style-it">classy</span> and numbers $$$4231$$$, $$$102306$$$, $$$7277420000$$$ are not.</p><p>You are given a segment $$$[L; R]$$$. Count the number of <span class="tex-font-style-it">classy</span> integers $$$x$$$ such that $$$L \le x \le R$$$.</p><p>Each testcase contains several segments, for each of them you are required to solve the problem separately.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer $$$T$$$ ($$$1 \le T \le 10^4$$$) — the number of segments in a testcase.</p><p>Each of the next $$$T$$$ lines contains two integers $$$L_i$$$ and $$$R_i$$$ ($$$1 \le L_i \le R_i \le 10^{18}$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print $$$T$$$ lines — the $$$i$$$-th line should contain the number of <span class="tex-font-style-it">classy</span> integers on a segment $$$[L_i; R_i]$$$.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0021678326412704663" id="id006610184293537603" class="input-output-copier">Copy</div></div><pre id="id0021678326412704663">4<br>1 1000<br>1024 1024<br>65536 65536<br>999999 1000001<br></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id002591611399627075" id="id0014575446264355163" class="input-output-copier">Copy</div></div><pre id="id002591611399627075">1000<br>1<br>0<br>2<br></pre></div></div></div>