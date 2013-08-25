## Introduction

Crazy Language는 단순함이 아름답다는 철학을 가지고 만든 난해한 언어입니다.
다양한 방법을 동원하여 난해함을 추구하지만, 최소한의 요소만을 가지고 튜링완전성을 추구하고 여러 개의 프로그래밍 패러다임에 속할 수 있으며, 이를 통해 언어가 작동하는 방법을 이해할 수 있습니다.
컴퓨터 프로그래밍 언어의 한계를 테스트하기 위해서, 재미로 설계된 프로그래밍 언어이며, 실용적인 프로그래밍에 적용하기위한 의도로 만들어진 언어가 아닙니다.

[Introduction to 난해한 프로그래밍 언어](http://ko.wikipedia.org/wiki/%EB%82%9C%ED%95%B4%ED%95%9C_%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D_%EC%96%B8%EC%96%B4).

## Features

* Tapping 방식의 언어체계를 가지고 있습니다.
* 실용적인 프로그래밍언어는 아닙니다.
* 7개의 연산자만을 사용합니다.
* 디버깅 기능을 제공합니다.
* 연산자를 제외한 나머지 숫자는 모두 무시됩니다.
* Windows 기반입니다.

## Quick Start

### 문법

* `>` : 포인터의 위치 증가 (++*ptr);

* `<` : 포인터의 위치 감소(--*ptr);

* `.` : Function Tap에서 포인터가 가르킨 기능 실행;

* `/` : Tap간 이동;
 
Crazy Language는 2개의 Tap를 가지고 있습니다. 

Data Tap는 무한히 늘어나는 형태로 자료를 담습니다.
Function Tap는 

`+` `-` `loop Start` `loop End` `input` `print` `ASCII print` 

순서로 7개의 기능을 가지며, 시작시 포인터의 위치는 `+` 를 가리킵니다.

### Demo


* 숫자 1을 출력합니다.

```C
#include <stdio.h>

int main()
{
   printf("1");
}
```
```json
/.>>>>>.
```



* 문자 A를 출력합니다.

```C
#include <stdio.h>

int main()
{
   printf("a");
}
```
```json
/.................................................................>>>>>>.
```


* 1부터 10까지 숫자를 출력합니다.

```C
#include <stdio.h>

int main()
{
   for(int i=1; i>=10; i++)
	printf("%d\n",i);
}
```
```json
</............./>>/..........>>.<./</<.<<./</>./>>/<<<.
```


* 두 수를 입력 받아 C 로 짜여진 구구단을 Crazy Language로 표현합니다.

```C
#include <stdio.h>

int main(void)
{
    char st[] = "Multiplication Table";
    int val = 0;
    scanf("%d", &val);
    printf("%s %d\n", st, val);
    for(int i=1; i<=9; i++)
        printf("%d*%d=%d\n", val, i, val*i);
}
```
```json
<<<<<<<<<<<<<<<<<<<<</...............................................
............................../>/....................................
.....................................................................
............/>/......................................................
....................................................../>/............
.....................................................................
.................................../>/...............................
.....................................................................
...../>/.............................................................
.................................................../>/...............
.....................................................................
......................../>/..........................................
.............................................................../>/...
.....................................................................
.........................../>/.......................................
........................................................../>/........
.....................................................................
......................................./>/...........................
.....................................................................
........./>/.........................................................
....................................................../>/............
.....................................................................
............................./>/................................/>/..
.....................................................................
............./>/.....................................................
............................................/>/......................
.....................................................................
......./>/...........................................................
................................................./>/.................
.....................................................................
.............../>/................................/>/............./>/
............................................................./>/./>/.
........................................./>>>>>>>>>>>/<<<./<<<<<<<<<<
<<<<<<<<<<<<<<<<<<<<<<<<</>>./>/./>/./>/./>/./>/./>/./>/./>/./>/./>/.
/>/./>/./>/./>/./>/./>/./>/./>/./>/./>/./>>>>>>>>>>>>>>>/<./<<<<<<<<<
<<<<</>./>>>>>>>>>>>>>>/<<<<.<.</</./</./</./</./</./</./</./</./</./
</./>>>>>>>>>>/>>>.>>/<<<<<<<<<</./</>./</<./</>./>>>>>>>>>>>>/<./<<<
<<<<<<<<<</>./>>>>>>>>>>>>>/<<<<.<./</<./>/>>>./</>>/<<<<<<<</./</>./
</>.<<./</>./>>>>>>>>>>>/<./<<<<<<<<<<<</>./>>>>>>>>>>>>/<<<<.<./</<.
/>/>>>./</>>/<<<<<<</./</>./</>.<<./</>./>>>>>>>>>>/<./<<<<<<<<<<</>.
/>>>>>>>>>>>/<<<<.<./</<./>/>>>./</>>/<<<<<</./</>./</>.<<./</>./>>>>
>>>>>/<./<<<<<<<<<</>./>>>>>>>>>>/<<<<.<./</<./>/>>>./</>>/<<<<</./</
>./</>.<<./</>./>>>>>>>>/<./<<<<<<<<</>./>>>>>>>>>/<<<<.<./</<./>/>>>
./</>>/<<<</./</>./</>.<<./</>./>>>>>>>/<./<<<<<<<</>./>>>>>>>>/<<<<.
<./</<./>/>>>./</>>/<<</./</>./</>.<<./</>./>>>>>>/<./<<<<<<</>./>>>>
>>>/<<<<.<./</<./>/>>>./</>>/<</./</>./</>.<<./</>./>>>>>/<./<<<<<</>
./>>>>>>/<<<<.<./</<./>/>>>./</>>/</./</>./</>.<<./</>./>>>>/<./<<<<<
/>./>>>>>/
```

## License

`Crazy Language` 는 BSD license 입니다. 자세한 내용은 `LICENSE`를 확인하세요.
