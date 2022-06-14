# 2022graphics

# Week01
第01週的上課內容

## Week01-1 OpenGL專案
1. CodeBlocks, File-New-Project, 選 OpenGL專案
2. 要記得...對應的目錄
3. 取個專案名
4. Build & Run, 可以看到彩色三角形在轉動

## Week01-2 WebGL 試試看

## Week01-3 GLUT專案
1. moodle下載 freeglut
2. 解壓縮到 桌面 freeglut
3. 改檔名 lib\libglut32.a
4. File-New-Project, GLUT專案
5. 專案名
6. GLUT在桌面的freeglut

## Week01-4 利用 Git 指令, 備份今天上課的內容
```
Week01-4 建 GitHub 倉庫
1. 登入 GitHub
2. 建 2022graphics 的 repo倉庫
2.1. 要設定 Public
2.2. 要 README.md
2.3. Add .gitignore 設定 C++

3. 利用 Git指令下載
3.0. 安裝 Git for Windows
3.1. 開啟 Git Bash
3.2. cd desktop 進入桌面
3.2. git clone https://你的倉庫網址
3.3. 查看 桌面,多了 2022graphics 目錄

3.4. 把今天的程式 複製到 剛剛目錄

4. 把修改的資料, 推送到雲端
4.1. cd 2022graphics 進入你的倉庫
4.2. git status 看你的狀況(紅的,多了目錄)
4.3. git add . 把檔案加進帳冊
4.4. git status 再看一次(綠的)

這裡要加入
git config --global user.email "你的email"
git config --global user.name "你的名"
git commit -m "上傳第1週"

4.5. git push 推送到雲端, BUT要登入
4.6. 在 Chrome記得再登入哦
```


# Week03

1. 先把第01週的程式從 GitHub 下載
2. 跑今天的範例 Shape.exe
3. 今天的主題: 點、線、面、色彩
4. 複習上週的課堂作業 GLUT 要裝 freeglut
4.1. 把 freeglut.....zip 的freeglut拉到桌面
4.2. 再把 桌面\freeglut\lib\libglut32.a 複製好
4.3. 就可以跑上週的 week01_GLUT 範例了!!!

5. 今天的主角要出現了(把上週的2個程式會合併)
5.1. File-New-Project, GLUT專案, week03_color
小心, ...的目錄要在桌面
(freeglut目錄不要錯) (目前看起來和上週 week01_GLUT一樣)
5.2. 把程式全刪掉!!!!!!

回家作業: 小畫家,可幫忙 (1) 小滴管+編輯色彩, 得到色彩的值(0-255) => 0.0~1.0
(2) 座標,可得到座標 0...300 => -1...+1

## 下載 Win32 的Example範例
- https://jsyeh.org/3dcg10/
- windows.zip => 下載\windows\Shape.exe 執行它

3. 今天的主題:
glBegin( GL_畫法 )開始畫

glEnd()結束畫

step01-0_簡介今天的上課內容,同時把GitHub 的式利用 Git指令下載下來,待命使用。

step01-1_今天上課的範例,是要介紹「點、線、面、色彩」,所以從 jsyeh.org 的 3dccg10 裡下載今天的Windows範例, 今天要跑的是 Shape.exe

step01-2_在範例Shape.exe裡,除了左邊按mouse右鍵可以切換Big及Color外,右邊也可以用mouse去drag拖曳裡面的數值。

step01-3_介紹等一下要做的「彩色三角形」,會使用glBegin() glEnd() 並在裡面插入 glColor3f() 及 glVertex3f() 配合上週做的 GLUT專案,便可完成。

step02-1_為了跑上週的week01_GLUT範例,我們需要把 freeglut 裝好(Moodle裡有一份,桌面裡也有一份), 請把 freeglut 複製到桌面, 把 lib 的 libglut32.a 也複製好,便可以執行上週的範例了

step02-2_今天要親手打造出 GLUT 的程式,要在一個3D視窗裡,畫出一個黃色的茶壼。前面己把 freeglut裝好, 現在 File-New-Project, GLUT專案,叫作 week03_color, 把 點點點 及 freeglut 都設好, 做出上週的進度, 再刪光光。接下來利用模仿的方式, 寫出 10行程式碼, 便可以做出黃色的茶壼

step03-1_修改前一個程式, 模依 week03-1_color 黃色的茶壼,改成 week03-2_color_triangle 彩色三角形

(用英文輸入法,按下 12345 的左邊有個 反撇 

```C++
///把程式全刪掉!!!!!!
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1,1,0);///黃色
    glutSolidTeapot( 0.3 );/// 0.3 實心茶壼

    glutSwapBuffers();///交換2倍的buffer
}

int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week03的視窗");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式

    glutMainLoop();///主要的迴圈
    return 0;
}
```


```C++
///把程式全刪掉!!!!!!
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1,1,0);///黃色
//    glutSolidTeapot( 0.3 );/// 0.3 實心茶壼
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
    glEnd();
    glutSwapBuffers();///交換2倍的buffer
}

int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week03的彩色三角形視窗");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式

    glutMainLoop();///主要的迴圈
    return 0;
}
```

# Week04

1. 下載範例 jsyeh.org/3dcg10
windows.zip => 下載\windows\Transformation.exe
data.zip    => 下載\windows\data\很多模型檔
執行 下載\windows\Transformation.exe

## 關於作業的問題
Q:對了還有一個很重要的問題！
請問上課的blogger 筆記，老師是期末才會全部一起看一起打分數，還是當週結束就會打分數了？

A:期末一起評分。 原因是因為，有些同學需要一點時間醞釀，才會寫得好&事後會想要做修改，所以最後再評分。
我要示範blog如何改時間。

## 關於偽造時間
## step02-0
上課前, 老師講解怎麼偽造時間。blogger可以設定時間, 這樣事後補交作業也不會被發現。github也可以在專案commit時設定時間,這樣就有一種「我還保持完美、不想放棄」的錯覺,讓你能監持下去。

- Blogger 可以在事後設定(發布的)時間。
- GitHub 也可以設定你 commit 的時間。
```
git commit -m "add week02" --date="2022-03-02 12:00:00"
                                   偽造時間
```

## 主題: 作業加分
有辦法畫圓嗎?

```C++
#include <GL/glut.h>
#include <math.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///yellow
    ///畫圓: cos() sin()
    glBegin(GL_POLYGON);
    for(float angle=0; angle<3.14159*2; angle+=0.1){
        glVertex2f( cos(angle), sin(angle) );
    }
    glEnd();

    glutSwapBuffers();
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("HW2 bonus");

    glutDisplayFunc(display);
    glutMainLoop();
}
```
## step01-0
在正式上課前,先把上週出的回家作業HW2示範一下,把班上同學做的比較好的2個作業匿名秀出來,鼓勵大家可以超越100分。另外,老師也教了如何使用 cos()及sin()畫出圓形,也能乘上半徑,變成比較小的圓, 也能把角度限制,變成半圓等

## step01-1
下載今天的範例,在jsyeh.org的3dcg10裡, 下載 data.zip 及 windows.zip 並正確解壓縮,便能執行今天的主角 Transformation.exe 跑跑看,右上角改模型,下方可改glTranslatef(x,y,z)的參數

## step01-2
看完課本3dcg10的範例Transformation.exe 我們在我們的 week04_translate 專案中, 試著用程式將紅色的茶壼移到右上方。可是好像一二三木頭人,在亂動,原因是因為移動會累積,所以要加上glPushMatrix()及glPopMatrix()做備份。

```C++
#include <GL/glut.h>
#include <math.h>
void myCircle(float r)
{
    ///畫圓: cos() sin()
    glBegin(GL_POLYGON);
    for(float angle=0; angle<3.14159*2; angle+=0.1){
        glVertex2f( cos(angle), sin(angle) );
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(1,1,0);///yellow
    myCircle(0.3);
    
    glutSwapBuffers();
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("HW2 bonus");

    glutDisplayFunc(display);
    glutMainLoop();
}
```

```C++
#include <GL/glut.h>
#include <math.h>
void myCircle(float r)
{   ///畫圓: cos() sin()
    glBegin(GL_POLYGON);
    for(float angle=0; angle<=3.14159; angle+=0.1){
        glVertex2f( r*cos(angle), r*sin(angle) );
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,0,0);///red
    myCircle(0.8);

    glColor3f(1,1,0);///yellow
    myCircle(0.6);

    glColor3f(0,1,0);///green
    myCircle(0.5);

    glutSwapBuffers();
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("HW2 bonus");

    glutDisplayFunc(display);
    glutMainLoop();
}
```

## 主題: Translate 移動
要配合矩陣 `glPushMatrix()` 備份矩陣, `glPopMatrix()` 還原矩陣

```C++
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,0);///red
	//錯誤的程式
    glTranslatef( 0.3, 0.2, 0);///右上角
    ///糟了,會一直偷偷動,因為移動會累積
	glutSolidTeapot(0.3);

    glutSwapBuffers();
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 translate");

    glutDisplayFunc(display);
    glutMainLoop();
}
```


```C++
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///push備份矩陣
        glTranslatef( 0.3, 0.2, 0);///右上角
        ///就不會一直偷偷動,因為移動會累積
        glColor3f(1,0,0);///red
        glutSolidTeapot(0.3);
    glPopMatrix();///pop還原矩陣

    glutSwapBuffers();
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 translate");

    glutDisplayFunc(display);
    glutMainLoop();
}
```

```C++
#include <GL/glut.h>
void myTeapot(float x, float y)///自訂的函式
{
    glPushMatrix();///push備份矩陣
        glTranslatef( x, y, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();///pop還原矩陣
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,0);///red
    myTeapot(+0.5, +0.5);
    myTeapot(+0.5, -0.5);
    myTeapot(-0.5, -0.5);
    myTeapot(-0.5, +0.5);

    glutSwapBuffers();
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 translate");

    glutDisplayFunc(display);
    glutMainLoop();
}
```


## step02-1
今天教完glTranslatef()後,我們可以配合glPushMatrix()及glPopMatrix()來做,但有時候很麻煩。這時候可以利用自訂函式,來讓程式碼變得比較清楚漂亮。

## 主題: mouse滑鼠事件

## step02-2
今天的第2個主題,是mouse滑鼠事件,我們使用glutMouseFunc(mouse)來註冊 void mouse(int button, int state, int x, int y) 的這個函式,使用printf()把值印出來,加深大家的印象,了解左鍵0,中鍵1,右鍵2,了解 按下去0,放開1, 了解座標0...300 的值

```C++
#include <GL/glut.h>
#include <stdio.h>///printf()
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    printf("%d %d %d %d\n", button, state, x, y);
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 mouse");

    glutDisplayFunc(display);///Display顯示
    glutMouseFunc(mouse);///Mouse滑鼠
    glutMainLoop();
}
```

接下來便可以用滑鼠事件,來進行座標換算

## 主題: 座標換算

## step03-1
今天最後一節的主題,是座標換算。原本mouse是使用windows的座標系統,和小畫家一樣,左上角是0,0, 右下角是300,300, 但是OpenGL是用「正中間0,0; 左邊-1,右邊+1,下面-1,上面+1」所以要進行座標換算。老師的口訣是「減一半、除一半、y變負的」.zip

```C++
#include <GL/glut.h>
#include <stdio.h>
int mouseX=0, mouseY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///黃色的
    glPushMatrix(); ///口訣:減一半、除一半, y還倒過來
        glTranslatef( (mouseX-150)/150.0 , -(mouseY-150)/150.0 , 0);
        glutSolidTeapot(0.3);///茶壼
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{   //printf("%d %d %d %d\n", button, state, x, y);
    mouseX=x; mouseY=y;
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 mouse");

    glutDisplayFunc(display);///Display顯示
    glutMouseFunc(mouse);///Mouse滑鼠
    glutMainLoop();
}
```
## step03-2
今天程式碼的收尾,我們發明一個程式, 可以利用滑鼠來寫程式。它會用printf()印出程式碼,讓你在小黑裡複制。它也會把座標備份在mx[i]及my[i]裡面,方便在display()裡面,利用for(迴圈)印出來,了解我們備份了哪些座標、畫出來的樣子長成什麼樣子,方便大家建出HW2的程式
```C++
#include <GL/glut.h>
#include <stdio.h>
int mouseX=0, mouseY=0, N=0;///N個點!!!
int mx[100], my[100];///用來記錄,等一下要畫出來哦!!!
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///黃色的
    glBegin(GL_LINE_LOOP);
        for(int i=0; i<N; i++){
            glVertex2f( (mx[i]-150)/150.0, -(my[i]-150)/150.0 );
        }
    glEnd();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    mouseX=x; mouseY=y;
    if(state==GLUT_DOWN){///按下去的 (放開的那個不算數)
        printf("    glVertex2f( (%d-150)/150.0, -(%d-150)/150.0 );\n", x,y);
        N++;
        mx[N-1]=x; my[N-1]=y;
    }
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 mouse");

    glutDisplayFunc(display);///Display顯示
    glutMouseFunc(mouse);///Mouse滑鼠
    glutMainLoop();
}

```

# Week05
## step01-1
先到jsyeh.org的3dcg10目錄中, 下載 windows.zip 及 data.zip, 並把它們放在對應的目錄。接下來執行transform.exe這個課本範例, 試著跑一下程式。.zip

https://jsyeh.org/3dcg10
 windows.zip => 下載\windows\Transformation.exe
 data.zip    => 下載\windows\data\一堆模式

右上角換模式
下方可以 drag glRotatef(角度, x,y,z);

## step01-2 
老師介紹blog裡有些同學有問題。另外挑了一位同學做範例,講解可以怎麼讓你們blog寫得更精彩,像是用 gist.github.com 來放程式碼,再進行分享等。

## step01-3
關於旋轉軸 就像買鹹蘇雞的竹籤,我們研究了 0,1,0 的轉動, 研究了 0,-1,0 的轉動,研究了 1,0,0的轉動,也研究了0,0,1的轉動,總之,利用神奇的安培右手,就可以知道東西是怎麼繞軸轉動

## step01-4
接下來是奇怪的旋轉軸1,1,0,,是有點斜的軸,那它會怎麼轉呢 就像當兵背值星帶斜斜的, 我們用課本的軟體跑了一下,加深大家的印象。

## step02-1
在實作的部分,我們利用上週的程式最簡單的10行程式碼,裡面有 glPushMatrix()備份矩陣, glPopMatrix()還原矩陣, 裡面再插入glRotatef(180,0,0,1)轉了180度的黃色茶壼

```C++
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(180, 0,0,1);///轉180度
        glColor3f( 1, 1, 0 );
        glutSolidTeapot( 0.3 );
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 Rotate");

    glutDisplayFunc(display);
    glutMainLoop();
}
```

## step02-2 
接續前一個程式,我們想要有mouse互動,怎麼互動呢 我們利用 glutMotionFunc()把mouse motion對應的函式準備好void motion(int x, int y) 會有mouse在動的時候的座標。修改好angle後,便再呼叫一次display()去照著angle來轉動

```C++
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle, 0,0,1);///轉180度
        glColor3f( 1, 1, 0 );
        glutSolidTeapot( 0.3 );
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void motion(int x, int y)
{
    angle = x;
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 Rotate");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
}
```

## step02-3
剛剛的motion()在轉動時,有點不連續,因為它只是讓angle=x做瞬間動作。想要做出比較好的連續動作,需要用到一個冷笑話「把大象放到冰箱裡去」把冰箱門打開、大象放進去、把冰箱門關起來。利用mouse()及motion()函式,配合 angle += x-oldX知道mouse多移動多少

```C++
#include <GL/glut.h>
float angle=0, oldX=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle, 0,0,1);///轉180度
        glColor3f( 1, 1, 0 );
        glutSolidTeapot( 0.3 );
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{///按下mouse、放開mouse
    oldX = x;
}
void motion(int x, int y)
{///拖著它動
    angle += (x-oldX);
    oldX = x;
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 Rotate");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
```

# step03-1
複習上週的 mouse 配合 GL_LINE_LOOP來寫程式,你畫點, N++, 同時更新座標,之後便可以把座標用for迴圈畫出來

```C++
#include <stdio.h>
#include <GL/glut.h>
int N=0;///一開始沒有任何頂點
int x[1000], y[1000];///最多可以有1000個頂點哦!!
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++){///用迴圈,畫N個頂點
        glVertex2f(  (x[i]-150)/150.0, -(y[i]-150)/150.0 );
    }              ///減一半、除一半, y要加上負號
    glEnd();
    glutSwapBuffers();
}
void mouse(int button, int state, int mouseX, int mouseY)
{
    if(state==GLUT_DOWN){///如果按下mouse
        N++;///就多一個頂點
        x[N-1]=mouseX;///最後一個新增的頂點的x座標
        y[N-1]=mouseY;///最後一個新增的頂點的y座標
        printf("現在按下滑鼠,得到新座標 %d %d\n", x[N-1], y[N-1] );
    }
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 複習 mouse");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
```

# step03-2
剛剛複習完上週匆匆教的「用滑鼠寫程式」,我們現在可以用mouse motion來畫圖,只要把mouse()改成motion()並做對應的修改,可以瞬間變得更細緻

```C++
#include <stdio.h>
#include <GL/glut.h>
int N=0;///一開始沒有任何頂點
int x[1000], y[1000];///最多可以有1000個頂點哦!!
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++){///用迴圈,畫N個頂點
        glVertex2f(  (x[i]-150)/150.0, -(y[i]-150)/150.0 );
    }              ///減一半、除一半, y要加上負號
    glEnd();
    glutSwapBuffers();
}
///void mouse(int button, int state, int mouseX, int mouseY)
void motion(int mouseX, int mouseY)
{
//    if(state==GLUT_DOWN){///如果按下mouse
        N++;///就多一個頂點
        x[N-1]=mouseX;///最後一個新增的頂點的x座標
        y[N-1]=mouseY;///最後一個新增的頂點的y座標
        printf("現在按下滑鼠,得到新座標 %d %d\n", x[N-1], y[N-1] );
//    }
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 複習 mouse");

    glutDisplayFunc(display);
    glutMotionFunc(motion);///glutMouseFunc(mouse);
    glutMainLoop();
}
```

# Week06

電腦圖學之父 Ivan Sutherland (Sketchpad)

看課本範例

jsyeh.org/3dcg10 下載 windows.zip data.zip
windows.zip => 下載\windows\Transformation.exe
data.zip    => 下載\windows\data\3D模型
執行 Transformation.exe

下方可以右鍵 Swap Translate/Rotate

自轉 vs. 公轉



# step01-3

接下來, 今天的主題是keyboard, 我們利用 GLUT 來寫今天的程式, 能 有keyboard互動, 重點是 glutKeyboardFunc(keyboard) 可以註冊 void keyboard(unsigned char key, int x, int y) 這個函式,再配合 stdio.h 的 printf()印出鍵盤的值.zip

實作時間
Maya: qwer  
w:移動 e:轉動 r:縮放  
0. 安裝 freeglut, lib改一下  
1. File-New-Project, GLUT  
   week06_keyboard  
2. 接下來, 從上週 blog 複製我們的程式來用。  

多了3行程式, 分別是

int main() 裡 glutCreateWindow()之後
`glutKeyboardFunc(keyboard);`

前面要宣告 `int keyboard(unsigned char key, int x, int y)` 的鍵盤函式

## step01-3
接下來, 今天的主題是keyboard, 我們利用 GLUT 來寫今天的程式, 能 有keyboard互動, 重點是 glutKeyboardFunc(keyboard) 可以註冊 void keyboard(unsigned char key, int x, int y) 這個函式,再配合 stdio.h 的 printf()印出鍵盤的值

```C++
///從上週 blog 貼我們的程式
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard( unsigned char key, int x, int y )
{
    printf("現在按下:%c 座標在:%d %d\n", key, x, y);
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
```

# step02-1
接下來我們稍做修改,除了剛剛的keyboard()函式, 我們再加上 mouse() 及 motion()函式, 希望能完整互動

```C++
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard( unsigned char key, int x, int y )
{
    printf("現在按下:%c 座標在:%d %d\n", key, x, y);
}
void mouse( int button, int state, int x, int y )
{
}
void motion( int x, int y )
{
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 keyboard mouse motion");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
```

## step02-2
上上週有教glTranslatef()移動, 我們把它做出來

```C++
#include <GL/glut.h>
#include <stdio.h>
float x=0, y=0, z=0, oldX, oldY;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(  (x-150)/150.0  , -(y-150)/150.0  ,  z  ); ///Maya: w
        ///glRotatef( angle,  0, 0, 1);
        ///glScalef( scale, scale, scale );
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{
    printf("現在按下:%c 座標在:%d %d\n", key, mouseX, mouseY);
}
void mouse( int button, int state, int mouseX, int mouseY )
{
    oldX = mouseX; oldY = mouseY;
}
void motion( int mouseX, int mouseY )
{
    x += (mouseX-oldX);
    y += (mouseY-oldY);
    oldX = mouseX; oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 keyboard mouse motion");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
```


## step02-3
接下來我們實作出「縮放」的程式,利用 float scale=1.0 這個變數,如果 if(mousX大於oldX)就讓 scale 放大 1%, 反過來就讓 scale 變小 1%, 我們就可以完成這個縮放的版本

```C++
#include <GL/glut.h>
#include <stdio.h>
float x=0, y=0, z=0, scale=1.0, oldX, oldY;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        //glTranslatef(  (x-150)/150.0  , -(y-150)/150.0  ,  z  ); ///Maya: w
        ///glRotatef( angle,  0, 0, 1);
        glScalef( scale, scale, scale ); ///Maya: r
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{
    printf("現在按下:%c 座標在:%d %d\n", key, mouseX, mouseY);
}
void mouse( int button, int state, int mouseX, int mouseY )
{
    oldX = mouseX; oldY = mouseY;
}
void motion( int mouseX, int mouseY )
{
    if( mouseX>oldX ) scale = scale * 1.01;
    if( mouseX<oldX ) scale = scale * 0.99;
    //x += (mouseX-oldX);
    //y += (mouseY-oldY);
    oldX = mouseX; oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 keyboard mouse motion");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
```

## step03-1

今天的主角是keyboard鍵盤函式, 我們 if(key=='w' 或 key=='W') now=1做移動, if(key=='r' 或 key=='R')now=3 做縮放。接下來在 motion()裡, if(now==1)做移動的計算, if(now==3)做縮放的計算, 這樣就可以又移動、又縮放了 

```C++
#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0, scale=1.0, angle=0.0, oldX, oldY;
int now=1;///1:移動, 2:旋轉, 3:縮放
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 , z ); ///Maya: w
        //glRotatef( angle,  0, 0, 1); ///Maya: e
        glScalef( scale, scale, scale ); ///Maya: r
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{   //printf("現在按下:%c 座標在:%d %d\n", key, mouseX, mouseY);
    if(key=='w' || key=='W') now=1;///移動 (小心不要中文)
    //if(key=='e' || key=='E') now=2;///旋轉
    if(key=='r' || key=='R') now=3;///縮放
}
void mouse( int button, int state, int mouseX, int mouseY )
{
    oldX = mouseX; oldY = mouseY;
}
void motion( int mouseX, int mouseY )
{
    if(now==1){///移動
        x += (mouseX-oldX);
        y += (mouseY-oldY);
    }else if(now==3){///縮放
        if( mouseX>oldX ) scale = scale * 1.01;
        if( mouseX<oldX ) scale = scale * 0.99;
    }
    oldX = mouseX; oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 keyboard mouse motion");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
```

## step03-2

今天最後的任務,是加上旋轉。所以用keyboard的 w,e,r 來切換移動、旋轉、縮放。motion()裡面也有對應的程式, display()也會照著進行 glTranslatef() glRotatef() glScalef() 的程式。我們還多學了 glutInitWindowSize(500,500)放大, 導致 glTranslatef()裡面減一半、除一半的地方有修改。.zip

```C++
#include <GL/glut.h>
#include <stdio.h>
float x=250, y=250, z=0, scale=1.0, angle=0.0, oldX, oldY;
int now=1;///1:移動, 2:旋轉, 3:縮放
void display()
{
    glClearColor(0.5, 0.5, 0.5, 1);///用來 Clear的色彩 R,G,B,A Alpha沒用到
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef( (x-250)/250.0 , -(y-250)/250.0 , z ); ///Maya: w
        glRotatef( angle,  0, 0, 1); ///Maya: e
        glScalef( scale, scale, scale ); ///Maya: r
        glColor3f( 1, 1, 0 );
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard( unsigned char key, int mouseX, int mouseY )
{   //printf("現在按下:%c 座標在:%d %d\n", key, mouseX, mouseY);
    if(key=='w' || key=='W') now=1;///移動 (小心不要中文)
    if(key=='e' || key=='E') now=2;///旋轉
    if(key=='r' || key=='R') now=3;///縮放
}
void mouse( int button, int state, int mouseX, int mouseY )
{
    oldX = mouseX; oldY = mouseY;
}
void motion( int mouseX, int mouseY )
{
    if(now==1){///移動
        x += (mouseX-oldX);
        y += (mouseY-oldY);
    }else if(now==2){///旋轉
        angle += (mouseX-oldX);
    }else if(now==3){///縮放
        if( mouseX>oldX ) scale = scale * 1.01;
        if( mouseX<oldX ) scale = scale * 0.99;
    }
    oldX = mouseX; oldY = mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("week06 keyboard mouse motion");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
```

# week08

Week08 Light



## step01-1
今天主題是 Lighting 打光, 在 jsyeh.org的 3dcg10 下載 data.zip 及 windows.zip 然後跑我們的 Light & Material.exe 範例 ,
1. jsyeh.org/3dcg10 下載
2. windows.zip => 下載\windows\Light & Material.exe
3. data.zip    => 下載\windows\data\ 一堆3D模型
4. (左下角可切換 material)
5. (左上角可切換 3D Model)

## step01-2
改變光的位置 (光的陣列)

## step01-3
接下來我們想在程式中,把打光的效果做出來。將 freeglut裝好、libglut32.a準備好, File-New-Project選GLUT專案, week08_light 專案, 把程式碼先用 Notepad++備份起來, 裡面與 light相關的程式有(1)打光的陣列、(2)打光的函式

寫寫看程式
1. 先把 freeglut 裝好,  lib\libglut32.a 準備好
2. File-New-Project, GLUT專案
3. 偷程式碼!!!!

```c++
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
```

```c++
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
```

## step01-4
接下來我們要把(0) 先放好10行GLUT程式, (1) 打光的陣列 放前面, (2) 打光的函式 放在 glutMainLoop()之前

```c++
///(1) 先貼上我們上週的簡單的10行程式 GLUT
///(2) 在前面宣告打光的陣列
///(3) 在 glutMainLoop() 之前,貼上打光的函式
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}

int main( int argc, char**argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week08 light");

    glutDisplayFunc(display);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
```



## step02-1
前一節課的光線好像不是太正確,我們調整一下光的位置,把z的值加個負號,便可以看到茶壼好像打光打得漂亮了。也再加上黃色,變成黃色茶壼

```c++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };//加個負號

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glColor3f( 1, 1, 0 ); //黃色的茶壼
        glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
```

## step02-2
介紹 glutCreateWindow()之前, 進行 Init ... 初始化, glutCreateWindow()之後, 就能執行OpenGL指令, 最後就用 glutMainLoop()來卡住, 讓程式持續進行,不會結束。

```c++
int main( int argc, char**argv )
{
    // Init ... 初始化

    glutCreateWindow("week08 light");

    // 可以執行 OpenGL 指令

    glutMainLoop();
}
```

## step02-3
介紹打光與Normal法向量的關係,接下來簡單介紹3D模型檔裡面的幾個重點, 以 obj 檔為例, 裡面有 v 代表頂點Vertex, vn 代表法向量Norma, vt代表 TexCoord貼圖座標l

## step03-1
老師介紹3D模型檔裡面的 v, vt, vn 及 f 各別代表的意思。我們的期中考題就出來了, 可以在 jsyeh.org 的 gl 目錄裡, 試試看你可以考幾分

## step03-2
今天臨時多了一個主題, 是如何畫出3D模型, 我們參考課本範例 jsyeh.org 的 3dcg10 裡面的 source.zip 裡面的 glm.h 與 glm.c 改檔名成 glm.cpp 加到專案中, 再加入 include glm.h 及對應的宣告函式等,最後便可以畫圖。請小心 working 工作目錄

```c++
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel=NULL;
void drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("al.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH);
}
//...
```

```c++
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glColor3f( 1, 1, 0 );
        //glutSolidTeapot( 0.3 );
        drawmodel();
    glutSwapBuffers();
}
```


# Week09
貼圖

1. 期中考
2. 主題: 貼圖
3. 實作: OpenCV
4. 實作: OpenGL貼圖設定
5. 實作: 貼圖座標

## step01-0
期中考試,考 OpenGL必背的10個函式11行, 老師利用模擬考軟體 jsyeh.org 的 gl 目錄, 示範給大家看。接著用 Moodle考試。

```c++
glPushMatrix();//備份矩陣
    glTranslatef(x,y,z);//移動
    glRotatef(angle,x,y,z);//轉動
    glScalef(x,y,z);//縮放
    glBegin(GL_POLYGON);//開始畫
        glColor3f(r,g,b);//色彩
        glTexCoord2f(tx,ty);//貼圖座標
        glNormal3f(nx,ny,nz);//打光的法向量
        glVertex2f(x,y);//頂點
    glEnd();//結束畫
glPopMatrix();//還原矩陣
```


## step01-1 跑課本範例
今天的上課主題是貼圖, 老師請大家到 jsyeh.org 的 3dcg10 目錄中, 下載windows.zip, data.zip, source.zip 檔, 解壓縮好、將 data 資料夾放對後, 便可以執行 Texture.exe 範例, 重點在大家看到了期中考的貼圖那題, 對應的程式碼是 glTexCoord2f(tx,ty); 對應貼圖座標的意思

1. 請到 jsyeh.org/3dcg10 下載今天的範例 
2. windows.zip -> 下載\windows\Texture.exe
3. data.zip    -> 下載\windows\data\很多圖檔

請執行 Texture.exe 了解貼圖的關鍵函式
glTexCoord2f(tx,ty) 的使用方式, 在 Blog寫下來

## step01-2 OpenCV
1. Moodle上課用軟體/Teams第09週 下載 OpenCV 2.1.0 (舊版,又小、最簡單好用、互通)
2. 安裝要小心!!! 有一步 PATH 要設定 (Add PATH
3. 用預設安裝 C:\OpenCV2.1 一定要在這裡


## step01-2 OpenCV
1. Moodle上課用軟體/Teams第09週 下載 OpenCV 2.1.0 (舊版,又小、最簡單好用、互通)
2. 安裝要小心!!! 有一步 PATH 要設定 (Add PATH) 代表你之後的程式執行時,可成功使用 OpenCV C:\OpenCV2.1\bin 裡面的 dll 檔
3. 用預設安裝 C:\OpenCV2.1 一定要在這裡
4. 小秘密 PATH 會設好!!!

## step02-1 第一個 OpenCV程式!!!
今天的挑戰,是安裝好 OpenCV 2.1 時設好 PATH後, 重開 CodeBlocks, 再寫程式。程式很簡單, 設定很複雜。程式碼裡面 include opencv的highgui.h , 對應的設定是 Setting-Compiler Setting 的 Search directories 的 compiler 要有 c的opencv2.1的include, 程式碼裡讀圖秀圖, 還有對應的咒語

0. (安裝好 OpenCV) 重開 CodeBlocks 
1. 程式很簡單, 設定很複雜
2. File-New-EmptyFile, 存成 week09_opencv.cpp 程式很簡單
3. 設定很複雜: Setting-Compiler Setting 裡面 3個地方
4. (1) Search directories 的 Compiler 要 Add C:\OpenCV2.1\include
5. (2) Search directories 的 Linker 要 Add C:\OpenCV2.1\lib
6. (3) 設定很複雜: Setting-Compiler Setting 裡面 Linker setting 咒語: cv210 cxcore210 highgui210


```c++
#include <opencv/highgui.h>
int main()
{ /// Ipl 是 Intel performance library 的縮寫

	IplImage * img = cvLoadImage("檔名.png"); //讀圖
	cvShowImage("week09", img); //秀圖
	cvWaitKey(0); //等任意鍵繼續

}
```


## step02-2

老師解釋大家常見問題, 並逐一回答。像是圖檔的副檔名有錯(記得開檔案總管-檢視-副檔名)、像是咒語寫錯, 可以看 View-Log 下方的 Build Log 會講清楚錯在哪裡

## step03-1

step03-1_接下來,我們要把 OpenCV 及 OpenGL 的程式碼結合。結合的方式比較暴力,就直接在 glutMainLoop()之前, 呼叫我們的 myTexture()函式,而這個函式,會去讀入 earth.jpg 地球的地圖, 放在奇怪的目錄, 桌面的freeglut的 bin目錄裡面。這有點歷史遺毒的位置, 之後會介紹原因。

```c++
///請自己去你的blog裡貼出你的10行程式!!
#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()
{
    IplImage * img = cvLoadImage("earth.jpg");///去找地圖!!
    cvShowImage("img", img ); ///在 img視窗,放 img的圖
    cvWaitKey( 0 );///等任意鍵繼續
	//等一下這段會被改掉
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");

    glutDisplayFunc(display);
    myTexture();

    glutMainLoop();
}
```

## step03-2
最後要真的把 OpenCV讀的圖檔,與 OpenGL的貼圖整合, 我們寫 myTexture()函式, 裡面同時有 OpenCV 及 OpenGL的對應函式, 完成這個任務, 讓茶壼能貼上貼圖。

```c++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
	return id;
}
```

再把 int main() 裡面的 myTexture() 加上呼叫要用的函式

```c++
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");

    glutDisplayFunc(display);
    myTexture("earth.jpg");

    glutMainLoop();
}
```

# Week10

電腦圖學 Week09 2022-04-25

1. 討論: 期中考成績、校長的信/累/快篩/缺貨/APP/降價
2. 主題: 上週貼圖+貼到四邊形=背景
3. 主題: 上週貼圖+貼到圓球=會轉的地球
4. 主題: 上週貼圖+貼到模型=鋼彈模型

step01-0_上課前,講解期中考試的成績、校長的信、快篩相關資訊

## step01-1 先做好設定
這節課的主題,是要將上週的貼圖+貼到四邊形,成為背景,所以先安裝 freeglut 及 OpenCV, 再把 myTexture.txt 的程式先貼進程式碼
1. (在教室)安裝 freeglut (lib/libglut32.a)
2. (在教室)安裝 OpenCV 2.1.0 vs2008 setup (Add PATH)
3. (重開 CodeBlocks) File-New-Project, GLUT專案
4. 把上週的 myTexture.txt 裡面有 myTexture() 做好設定
5. OpenCV 設定: Setting-Compiler, search directories, Compiler加 C:\OpenCV2.1\include
6. OpenCV 設定: Setting-Compiler, search directories, Linker加 C:\OpenCV2.1\lib
7. OpenCV 設定: Setting-Compiler, Linker settings, 咒語 cv210 cxcore210 highgui210

```cpp
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
```

## step01-2
接下來將 OpenCV 的設定設好,包括2個目錄、3段咒語, 程式碼除了 myTexture.txt 的程式外, 再貼上10行的程式。最後, 在 working_dir 工作目錄中 (目前是桌面的freeglut的bin裡) , 放好你的圖,便能看到上週的進度,也就是茶壼表面有地球的貼圖.zip

1. 做好 OpenCV設定, 把我們的專案, 加上 10行程式
2. 配合 工作目錄 working_dir (現在在你的桌面的freeglut的bin裡) 裡面放圖檔!!!
3. 在 main() 裡面, 把 myTexture("圖檔"); 放好。小心副檔名不要錯了。

```cpp
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glutDisplayFunc(display);
    myTexture("earth.jpg");

    glutMainLoop();
}
```

## step01-3
step01-3_這節課的目標,是要把貼圖+貼到四邊形, 變成背景。所以如果 step01-2 可以看到茶壼表面有貼圖, 便可以開始 glBegin(GL_POLYGON) 開始畫, glTexCoord2f(tx,ty) 及 glVertex2f(x,y) 重覆4次,表示四邊形竹旳4個頂點及對應的貼圖座標,最後 glEnd() 結束畫。其中的貼圖座標有點難理解。你要了解Windows 圖左上角0,0

1. 加上 glBegin(GL_POLYGON);
2. 加上 glTexCoord2f( tx, ty );   glVertex2f( x, y ); 寫4次
3. 加上 glEnd();

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidTeapot(0.3);
    glBegin(GL_POLYGON);
    ///圖片的0,0在左上角
        glTexCoord2f( 0, 1 ); glVertex2f( -1, -1 );
        glTexCoord2f( 1, 1 ); glVertex2f( +1, -1 );
        glTexCoord2f( 1, 0 ); glVertex2f( +1, +1 );
        glTexCoord2f( 0, 0 ); glVertex2f( -1, +1 );
    glEnd();
    glutSwapBuffers();
}
```

## step02-1
想要貼到圓球上。BUT圓球的座標不太會用: cos(), sin() 圓球座標系統。
可以用 OpenGL User 函式來做到

step02-1_有貼圖能力, 想把貼到圓球,變成地球。程式碼有難度,先宣告一個 gluQuadric指標 sphere=NULL; 在 main() 的 glutMainLoop()之前 sphere=gluNewQuadric(); 新增一個二次曲面, 接下來 display()可用 gluQuadricTexture(sphere, 1); 建貼圖 gluSphere(sphere,1,30,30);

1. OpenGL 的函式, ex. glVertex3f()
2. OpenGL Utilities (GLU) 的函式, ex. gluSphere()
3. OpenGL User Tookit (GLUT) 的函式, ex. glutSolidTeapot()

開始寫程式吧!!!!
1. File-New-Project, GLUT專案, 存成 week10_texture_earth
2. 宣告指標`GLUquadric * sphere=NULL;` 有個指標,要給gluSphere()用
3. 在 main()裡, 將指標設好 `sphere = gluNewQuadric();`
4. 在 display()裡, 加入 `gluQuadricTexture(sphere, 1);`
5. 在 display()裡, 再加入 `gluSpher(sphere, 1, 30, 30);`

解釋一下 gluSphere()
1. `gluSphere( sphere, 半徑, 柳丁切經, 層層切緯);`
2. 老師都用 `gluSphere(sphere, 1, 30, 30);` 反正切一樣細就好


## step02-2
step02-2_最後我們把地球轉正囉!! 利用期中考考過的 glPushMatrix()及glPopMatrix()裡面多一行 glRotatef(角度,1,0,0)就可以了。記得 glutMainLoop()之前,要glEnable(GL_DEPTH_TEST)開啟3D深度測試的功能,才會正確畫出3D的前後關係

```cpp
//前面省略
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();//step02-2
        glRotatef(90, 1,0,0);//step02-2
        gluQuadricTexture(sphere, 1);
        gluSphere(sphere, 1, 30, 30);///glutSolidTeapot(0.3);
    glPopMatrix();//step02-2
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glutDisplayFunc(display);
    myTexture("earth.jpg");
    sphere = gluNewQuadric();
    glEnable(GL_DEPTH_TEST);//step02-2

    glutMainLoop();
}
```

## step03-1
讓地球可以轉動起來。我們利用 float angle=0; 有個變數會決定轉動的角度,一開始是0度。在display()的最後一行 angle++ 或 angle += 0.1 每次要多轉動多少。 glRotatef(angle, 0,-1,0) 會對著-Y軸轉動。最後 main()裡面要有glutIdleFunc(display)

```cpp
///全刪,拿剛剛的程式來用!!!
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere = NULL;///一個指到二次曲面的指標
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0,-1,0);
        glRotatef(90, 1,0,0);
        gluQuadricTexture(sphere, 1);
        gluSphere(sphere, 1, 30, 30);///glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("earth.jpg");
    sphere = gluNewQuadric();
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```

## step03-2
把模型讀進來: 結合前一個實作的「會旋轉的地球」的程式碼, 再使用week08教過的程式碼,配合對應的貼圖即可。

1. File-New-Project, GLUT專案, week10_texture_model
2. 模型放哪裡? 工作執行的目錄 ex. (in C:\Users\...\Desktop\freeglut\bin) 把老師的 myGundam.zip 的 data目錄,放進去
3. 加入我們的程式, glm.h glm.c(改成glm.cpp) 放在你的專案 week10_texture_model 裡 下載自 jsyeh.org/3dcg10 的 source.zip 的 glm.h glm.c (改成 glm.cpp)
4. 把 glm.cpp 加到專案裡Add Files...
5. 把 week08 的程式貼過來
6. 把 myTexture("earth.jpg") 改成 myTexture("data/Diffuse.jpg")

```cpp
//前面 include glm.h, 宣告模型的指標
#include "glm.h"
GLMmodel * pmodel = NULL;
```

```cpp
//中間讀入模型
    glPushMatrix();
        glRotatef(angle, 0,1,0);
        if( pmodel == NULL ){
            pmodel = glmReadOBJ("data/Gundam.obj");
            glmUnitize( pmodel );
            glmFacetNormals( pmodel );
            glmVertexNormals( pmodel, 90 );
        }
        glmDraw( pmodel, GLM_MATERIAL | GLM_TEXTURE);
    glPopMatrix();
```

```cpp
//記得在 main() 裡面將貼圖讀進來
    myTexture("data/Diffuse.jpg");
```

# Week11

## step01-1

1. 安裝 freeglut (1) libglut32.a (2) freeglut\bin
2. 安裝 OpenCV 2.1 (上週) 小心! Add PATH (其實就是 .dll 檔案)
3. (要重開)File-New-Project, GLUT專案 week11_gundam
4. 下載 jsyeh.org/3dcg10 的 source.zip 裡面 glm.h glm.c
5. 把 glm.h glm.cpp 放到 week11_gundam 專案 目錄 (main.cpp的鄰居)
6. myGundam.zip 的模型裡的 data\模型檔,放到 工作 目錄 freeglut\bin

講解意思:
1. compiler include .h 目錄
2. linker lib .lib 目錄
3. linker 咒語 要加入的檔案 一堆 .lib 檔
而 bin 裡的 .dll 檔案,是在 "工作執行目錄"

## step01-2
寫程式,先複習第09週的程式(貼圖)
1. 貼上你的程式
2. 配上你的咒語,只要寫一次就好
3. 咒語 Setting-Compiler-Search directories: Compiler include 目錄 C:\OpenCV2.1\include
4. 咒語 Setting-Compiler-Search directories: Linker lib 目錄 C:\OpenCV2.1\lib
5. 咒語 Setting-Compiler-Linker: cv210 cxcore210 highgui210
6. 執行可成功, 代表: (1) OpenCV的咒語設對了, (2) PATH 也對了, (3) 你的 gundam 的 data 也對了

```cpp
///當上面是彩色的,表示現在是可執行
///左邊的Projects裡的 week11_gundam 按右鍵 Add Files
#include <opencv/highgui.h>
int main()
{
	IplImage * img = cvLoadImage("data/Diffuse.jpg");
	cvShowImage("week11", img);
	cvWaitKey(0);//等任意鍵繼續
}
```

## step02-1
接續前面的專案,將 myTexture加到前面, 將 10行GLUT程式加到後面, 配上呼叫 myTexture(圖檔) 便可以看到 teapot 穿上 Diffuse的貼圖

1. 把 myTexture 放到程式的前面
2. 把 10行 GLUT 程式放進去
3. 在 main() 的 glutMainLoop()之前 myTexture("data/Diffuse.jpg");
4. 我們就可看到 teapot穿上 gundam 的 Diffuse貼圖


```cpp
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
	return id;
}  
```

## step02-2
step02-2_接續前一個案案,接下來是要將 glm 模型相關的程式拿來用。最後可以看到 Gundam模型哦!

把 glm 模型相關的程式 貼出來
1. `#include "glm.h" //使用同目錄中的 glm.h 外掛`
2. `GLMmodel * pmodel = NULL;`
3. display()裡面, 要有畫模型的程式

```cpp
#include "glm.h"
GLMmodel * pmodel = NULL;
```

在 display()裡面
```cpp
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	if( pmodel == NULL ){///程式放這裡
		pmodel = glmReadOBJ( "data/gundam.obj" ); ///讀入模型
		glmUnitize( pmodel ); ///把模型pmodel 調整成單位大小 -1...+1
		glmFacetNormals( pmodel ); ///把Facet面的法向量Normals算出來
		glmVertexNormals( pmodel , 90 ); ///把 Vertex的法向量,用面平均算出來,超過90度就分開
	}
	glmDraw(pmodel, GLM_TEXTURE);
	glutSwapBuffers();
}
```

## step02-3
剛剛看到3D模型,很開心。細看之後, 發現模型的貼圖好像上下倒過來了。所以 data目錄中的 Diffuse.jpg 圖檔需要「上下垂直翻轉」。

而且看起來,好像模型被壓扁了, 我們需要開啟 3D的功能!!

1. 利用小畫家,把 freeglut\bin\data\Diffuse.jpg 開起來, 上下「垂直翻轉」
2. 在 glutMainLoop()之前(可以讀圖,可以myTexture(), 可以打光, 可以做很多設定) 加 glEnable(GL_DEPTH_TEST); 開啟 3D深度測試功能,讓近的會蓋掉遠的,便是真3D
3. 我們想讓3D模型轉起來 glPushMatrix() ... glPopMatrix() 的中間,加上 glRotatef(angle, 0,1,0); 配上 angle+=1
4. 最後,加入 glutIdleFunc( display ) 有空就重畫畫面

```cpp
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
	return id;
}
float angle=0;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if( pmodel == NULL ){///程式放這裡
		pmodel = glmReadOBJ( "data/hand1.obj" ); ///讀入模型
		glmUnitize( pmodel ); ///把模型pmodel 調整成單位大小 -1...+1
		glmFacetNormals( pmodel ); ///把Facet面的法向量Normals算出來
		glmVertexNormals( pmodel , 90 ); ///把 Vertex的法向量,用面平均算出來,超過90度就分開
	}

	glPushMatrix();
        glRotatef(angle, 0,0,1);
        glScalef(2,2,2);
        glmDraw(pmodel, GLM_TEXTURE);
    glPopMatrix();
	glutSwapBuffers();
	angle+=1;
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11 gundam");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    myTexture("data/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```

## step03-0
老師講些故事, 鼓勵大家多練習、把握學習的機會。
- 蘇文鈺老師 [教真的，如果師父不狠心一點，徒弟是學不會的。](https://www.facebook.com/arwen.su.5/posts/2344128725740718)

## step03-1

利用Autodesk Maya 來切割3D模型、匯出 OBJ模型檔。老師介紹老師拍的影片給大家參考
- https://www.youtube.com/watch?v=D4a7cNFF9kQ
	- 如何使用 Maya 匯出 3D模型檔(OBJ) 觀看次數：11,717次
	
## step03-2
本來老師想要示範 T-R-T 的程式, 不過後來發現快下課了, 時間不夠,就下週再教

## step03-3
最後老師再示範「如何利用Git指令,將今天的程式上傳」其中比較重要的,如果電腦之前有 git clone 過,就可以不用再做這一步, 只要記得在目錄中 git pull 把雲端先拉下來同步。另外如果 git config 做過, 也可以不用做。只要檔案修改後, git pull, git add ., git commit -m, 最後 git push 即可


# Week12

## step01-1
看課本 Transformation.exe 裡面有: 移動、旋轉
step01-1_下載課本範例, 解壓縮, 執行 Transformation.exe 經由 Swap T R 來看它們的差別

1. jsyeh.org/3dcg10 下載 windows.zip data.zip
2. 解壓縮 下載\windows\Transformation.exe
3. 解壓縮 下載\windows\data\模型
4. 跑 Transformation.exe (要頻繁切換 Swap T R)

看起來像是放在右邊有個在轉動的車子
```cpp
glTranslatef( 0.8, 0.0, 0.0);//在右邊
glRotatef( angle, 0, 1, 0);//轉動
//有一台藍色的車子
```

好像車子在繞著中心點轉彎
```cpp
glRotatef( angle, 0, 1, 0);
glTranslatef( 0.8, 0.0, ,0.0);
//有一台藍色的車子
```

## step01-2
講解差別, 如何理解(用框框來解釋程式碼。越畫越大)
step01-2_老師用框框,從小到大,慢慢增加程式碼,方便大家理解程式碼怎麼看、怎麼理解

1. 老師將 Transformation.exe 範例執行後, 開始框程式碼
2. 最裡面的小框框

## step01-3
用老師的程式來理解
step01-3_利用老師的網頁小範例,讓大家看到,程式碼會影響到它下面的整個程式碼

1. https://120.125.80.50/GL (有期中考題、有小考考題)
2. OpenGL T-R-T函式: 對特定軸轉動練習
3. 滑鼠點擊 To Draw 後, 可以在左邊圈出一個形狀
4. 滑鼠點擊 angle 後, 再按空白鍵,可以讓 angle 值一直變動
5. 滑鼠點擊程式碼的方框後, 可以 drag 改變程式碼的位置
6. 滑鼠點擊 glTranslatef()程式的方框後,可在左邊drag改變東西的位置

## step02-1
step02-1_利用網頁中的圖,配合第一節課教的畫框框,從小到大,一步步了解T-R-T的操作


## step02-2
寫程式來理解

0. freeglut要裝好
1. File-New-Project, GLUT專案 week12_TRT
2. 用簡單的10行程式,配合 T-R-T函式

```cpp
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glutSolidTeapot( 0.3 );///大茶壼
    glPushMatrix();
        glTranslatef(0.3, 0, 0);///把下面旋轉中的東西 "掛在" 某處
        glRotatef( angle, 0,0,1 );///旋轉
        glTranslatef(0.2, 0, 0);///往右下移動(把把手移到中心)
        glColor3f(1,0,0);///紅色的
        glutSolidTeapot( 0.2 );///茶壼
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;
}
```

## step03-1
step03-1_與作業T-R-T相關的程式, 改寫成 TRT TRT 專案,看到很關節的轉動

1. File-New-Project, GLUT專案 week12_TRT_TRT
2. 把剛剛的程式拿來, 再變複雜


```cpp
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glutSolidTeapot( 0.3 );///大茶壼
    glPushMatrix();
        glTranslatef(0.3, 0, 0);///把下面旋轉中的東西 "掛在" 某處
        glRotatef( angle, 0,0,1 );///旋轉
        glTranslatef(0.2, 0, 0);///往右下移動(把把手移到中心)
        glColor3f(1,0,0);///紅色的
        glutSolidTeapot( 0.2 );///茶壼
        glPushMatrix();
            glTranslatef(0.2, 0, 0);///把下面旋轉中的東西 "掛在" 某處
            glRotatef( angle, 0,0,1 );///旋轉
            glTranslatef(0.2, 0, 0);///往右下移動(把把手移到中心)
            glColor3f(1,0,0);///紅色的
            glutSolidTeapot( 0.2 );///茶壼
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.03;
}
```

# Week13

電腦圖學 Week13 2022-05-16
1. 示範複習作業/考試的 TRT(實際例子)
2. TRT 的R角度
3. 利用 keyboard/mouse 來改變
4. 如何轉正模型、如何調整模型大小

```cpp
glPushMatrix();
	glTranslatef( x, y, z);
	glRotatef(angle, 0, 0, 1);//z軸
	glTranslatef( x2, y2, z2);
	//畫我們的手臂 用方塊 glRectf()
glPopMatrix();
```

## step01-1 
step01-1_第一節課想要讓大家用另一種方法練習TRT,所以要更簡化程式。我們先使用glRectf(x1,y1, x2,y2) 來畫出簡單的四邊形

用簡單的方塊,來做做看(考試相關)
1. File-New-Project, GLUT專案 week13_rect_TRT
2. 貼入10行程式, 加上 glRectf()
```cpp
///week13_rect_TRT
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glRectf(0.5, 0.5, -0.5, -0.5);
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutDisplayFunc(display);///不放Idle
    glutMainLoop();
}
```

## step01-2
step01-2_先準備好TRT的程式碼,把白色的身體、紅色的手臂都畫出來。等一下要教大家如何調到正確的技巧

1. 接剛剛的程式 把T-R-T 套上去
2. 還不知道要放多少的數值,就///先註解掉

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.5, 0.5, -0.5, -0.5);///身體
    glPushMatrix();
        ///glTranslatef( x, y, z);///等下要掛在0.5,0.5
        ///glRotatef(angle, 0, 0, 1);//z軸
        ///glTranslatef( x2, y2, z2);///????
        glColor3f(1,0,0);///紅色的
        glRectf(0.5, 0.5, 1.0, 0.3);///手臂
    glPopMatrix();

    glutSwapBuffers();
}
```

## step01-3

接下來的步驟,是先把TRT最下面的移動,把手臂的旋轉中心,放到畫面的世界中心。第二步,再把旋轉做出來。比如說float angle=45; 便轉動45度。

```cpp
float angle=45;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.5, 0.5, -0.5, -0.5);///身體
    glPushMatrix();
        ///glTranslatef( x, y, z);///等下要掛在0.5,0.5
        glRotatef(angle, 0, 0, 1);///(2) 旋轉
        glTranslatef( -0.5, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.5, 0.5, 1.0, 0.3);///手臂
    glPopMatrix();

    glutSwapBuffers();
}
```

## step02-1
剛剛 week13_rect_TRT要做最後收尾。把第三步(3)把會旋轉的手臂掛上去 0.5, 0.5 的位置, 其z的值是0,是因為剛好就在z=0的那個平面。接下來希望手臂可以利用mouse motion來揮動, 所以加上mouse() 及 motion() 函式, 並在 main()裡 設定好這兩個函式。有一行之前沒教過 glutPostRedisplay()會請GLUT重畫畫面

註: 在做動畫時, 通常動畫師做出的人體會2手張開, 擺成 T pose。人體站直, z在0的位置。

```cpp
///week13_rect_TRT
#include <GL/glut.h>
float angle=45, oldX=0;
void mouse(int button, int state, int x, int y){///mouse按下去
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.5, 0.5, -0.5, -0.5);///身體
    glPushMatrix();
        glTranslatef( 0.5, 0.5, 0);///(3) 等下要掛在0.5,0.5
        glRotatef(angle, 0, 0, 1);///(2) 旋轉
        glTranslatef( -0.5, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.5, 0.5, 1.0, 0.3);///手臂
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);///不放Idle
    glutMainLoop();
}
```


## step02-2
step02-2_接下來要畫下手肘。不過因為剛剛的程式有點太胖,所以重新開始,新開GLUT專案,存檔 week13_rect_TRT_TRT, 裡面程式和之前很像,但是稍微瘦身、改一下位置,以便畫出綠色的下手肘。

1. File-New-Project, GLUT專案 week13_rect_TRT_TRT
2. 類似剛剛的程式, 不過老師修一下
3. 先把 float angle=0;角度變0從頭做
4. 把下手臂也順利放上去

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3, 0.5, -0.3, -0.2);///身體,瘦身
    glPushMatrix();  ///掛的位置也改了
        glTranslatef( 0.3, 0.5, 0);///(3) 等下要掛在0.5,0.5
        ///glRotatef(angle, 0, 0, 1);///(2) 旋轉
        glTranslatef( -0.3, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3, 0.5, 0.8, 0.3);///上手臂
    glPopMatrix();

    glutSwapBuffers();
}
```

## step02-3
程式要結案了。我們把下手臂畫出來, 再從下到上, 把TRT也逐一做出來。其中比較特別的是, 我們把 angle值交給一個人畫,目前是下手臂,所以上手臂暫時就不轉動。

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3, 0.5, -0.3, -0.2);///身體,瘦身
    glPushMatrix();  ///掛的位置也改了
        glTranslatef( 0.3, 0.5, 0);///(3) 等下要掛在0.5,0.5
        ///glRotatef(angle, 0, 0, 1);///(2) 旋轉
        glTranslatef( -0.3, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3, 0.5, 0.8, 0.3);///上手臂
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0); ///(3) 把下手肘掛在關節上
            glRotatef( angle, 0, 0, 1); ///(2) 旋轉
            glTranslatef(-0.8, -0.4, 0 );///(1) 把下手肘的旋轉中心,放正中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.8, 0.5, 1.1, 0.3);///再畫下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
```


## step03-1

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3, 0.5, -0.3, -0.2);///身體,瘦身

    glPushMatrix();  ///右半邊
        glTranslatef( 0.3, 0.5, 0);///(3) 等下要掛在0.5,0.5
        glRotatef(angle, 0, 0, 1);///(2) 旋轉
        glTranslatef( -0.3, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3, 0.5, 0.8, 0.3);///右上手臂
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0); ///(3) 把下手肘掛在關節上
            glRotatef( angle, 0, 0, 1); ///(2) 旋轉
            glTranslatef(-0.8, -0.4, 0 );///(1) 把下手肘的旋轉中心,放正中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.8, 0.5, 1.1, 0.3);///再畫右下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();  ///左半邊
        glTranslatef( -0.3, 0.5, 0);///(3) 等下要掛在0.5,0.5
        glRotatef(angle, 0, 0, 1);///(2) 旋轉
        glTranslatef( +0.3, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3, 0.5, -0.8, 0.3);///左上手臂
        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0); ///(3) 把下手肘掛在關節上
            glRotatef( angle, 0, 0, 1); ///(2) 旋轉
            glTranslatef(+0.8, -0.4, 0 );///(1) 把下手肘的旋轉中心,放正中心
            glColor3f(0,1,0);///綠色的
            glRectf(-0.8, 0.5, -1.1, 0.3);///再畫左下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
```
## step03-2
可以利用 keyboard (來指定要轉動的)關節

step03-2_現在應該要有4個關節才對,但是float angle=0; 只有一個關節能用。所以我們用陣列來解決。float angle[20]; 準備20個關節, 把 disiplay()裡的 angle 依序變成 angle[0] ... angle[3], 再準備 void keyboard() 裡面 if(key=='0') angleID=0; if(key=='1')angleID=1; motion()也改裡面的 angle[angleID]=(x-oldX);

記得 main() 裡面要加 glutKeyboardFunc(keyboard)


關節的角度要分開。
```
float angle=0; 只有一個關節, 改成下面的陣列
float angle[20]; 就有20個關節!!!
```

之後, 要把 angle 都改成 angle[???]

```
angle[angleID] 其實是 
angleID=0  angle[0]
angleID=1  angle[1]
angleID=2  angle[2]
```

```cpp
///week13_rect_many_TRT
#include <GL/glut.h>
float angle[20], oldX=0;
int angleID=0;///0:第0個關節, 1:第1個關節, 2:第2個關節
void keyboard( unsigned char key, int x, int y){
    if( key=='0' ) angleID=0;///預設是這一個
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}///用keyboard的按鍵,來決定等一下 motion()裡要改的 angle[i] 是哪一個
void mouse(int button, int state, int x, int y){///mouse按下去
    oldX = x;
}
void motion(int x, int y){
    angle[angleID] += (x-oldX);
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3, 0.5, -0.3, -0.2);///身體,瘦身

    glPushMatrix();  ///右半邊
        glTranslatef( 0.3, 0.5, 0);///(3) 等下要掛在0.5,0.5
        glRotatef( angle[0], 0, 0, 1);///(2) 旋轉
        glTranslatef( -0.3, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3, 0.5, 0.8, 0.3);///右上手臂
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0); ///(3) 把下手肘掛在關節上
            glRotatef( angle[1], 0, 0, 1); ///(2) 旋轉
            glTranslatef(-0.8, -0.4, 0 );///(1) 把下手肘的旋轉中心,放正中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.8, 0.5, 1.1, 0.3);///再畫右下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();  ///左半邊
        glTranslatef( -0.3, 0.5, 0);///(3) 等下要掛在0.5,0.5
        glRotatef( angle[2], 0, 0, 1);///(2) 旋轉
        glTranslatef( +0.3, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3, 0.5, -0.8, 0.3);///左上手臂
        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0); ///(3) 把下手肘掛在關節上
            glRotatef( angle[3], 0, 0, 1); ///(2) 旋轉
            glTranslatef(+0.8, -0.4, 0 );///(1) 把下手肘的旋轉中心,放正中心
            glColor3f(0,1,0);///綠色的
            glRectf(-0.8, 0.5, -1.1, 0.3);///再畫左下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);///不放Idle
    glutMainLoop();
}
```

# Week14

## step01-1
step01-1_練習寫檔(fopen(), fprintf(), fclose())

練習寫檔
1. 開啟檔案 `fopen()` 要先有指標 `FILE * fout = fopen("file.txt", "w+");`
2. 印出來、寫出來 printf() 改裝 fprintf()
3. 關閉檔案 `fclose(fin)`

```cpp
///Week14-1.cpp step01-1
///練習開檔、寫檔、關檔
#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt", "w+");

     printf("Hello World\n");
    fprintf(fout, "Hello World\n");

    fclose(fout);
}
```

## step01-2
step01-2_加再上練習讀檔fscanf()

練習開檔、寫檔write、關檔
+ 練習開檔、讀檔read、關檔

```cpp
///Week14-2.cpp step01-2
///練習開檔、寫檔write、關檔
///練習開檔、讀檔read、關檔
#include <stdio.h>
int main()
{
    FILE * fout = fopen("file2.txt", "w+");
    fprintf(fout, "angle1 %d\n", 999);
    fclose(fout);

    char line[200];
    int a;
    FILE * fin = fopen("file2.txt", "r");
    fscanf(fin, "%s %d", line, &a);
    printf("讀到了字串:%s 及整數%d\n", line, a);
    fclose(fin);
}
```

## step01-3

step01-3_結合前面的寫檔、讀檔, 還有上週的 many TRT 範例, 我們想要把 float angle[20] 全部關節的座標都存檔存起來哦, 使用 void myWrite()函式, 裡面會適時 fopen()開檔, 再用 for迴圈把20個關節都印到檔案裡面

把上週你寫的 week13_rect_many_TRT拿來繼續寫
1. File-New-Project, GLUT專案, week14_TRT_angle_write
2. 貼上上週的最後程式
3. 要開檔、寫檔, 最後關檔

```cpp
///week14_TRT_angle_write 修改自 week13_rect_many_TRT
#include <GL/glut.h>
#include <stdio.h> ///為了 printf, fprintf, fopen, fclose ..
float angle[20], oldX=0;
int angleID=0;///0:第0個關節, 1:第1個關節, 2:第2個關節
FILE * fout = NULL;
void myWrite(){
    if(fout==NULL) fout = fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        fprintf(fout, "%.2f ", angle[i] );
    }
}
void keyboard( unsigned char key, int x, int y){
    if( key=='0' ) angleID=0;///預設是這一個
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}///用keyboard的按鍵,來決定等一下 motion()裡要改的 angle[i] 是哪一個
void mouse(int button, int state, int x, int y){///mouse按下去
    oldX = x;
}
void motion(int x, int y){
    angle[angleID] += (x-oldX);
    myWrite();
    oldX = x;
    glutPostRedisplay();
}
```

## step02-1
step02-1_新增專案week14_TRT_angle_write_and_read 要再把寫檔的結果,再重新讀進來、按下r鍵可以重播

我們想要讀進來!!!
要做一些修改
1. File-New-Project, GLUT專案, week14_TRT_angle_write_and_read
2. 要新加 `FILE * fin = NULL;`空指標
3. 寫自己的 void myRead() 裡面先將 fout 適時關起來, 再把 fin 開起來, 讀入20個關節, 並更新畫面
4. keyboard()函式中, 加入 if(key=='r') myRead(); 去呼叫myRead()並更新畫面
5. 所以在執行時, 先用 mouse motion + keyboard 做一些動作, 之後再一直按著'r' 來一行一行讀入剛剛錄下來的動作

```cpp
FILE * fout = NULL, * fin = NULL;
void myWrite(){
    if(fout==NULL) fout = fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
         printf(      "%.2f ", angle[i] );
        fprintf(fout, "%.2f ", angle[i] );
    }
    printf("\n");
    fprintf(fout, "\n");///少了fclose,因為不想要才印一行,就結束。想寫多行一些
}
void myRead(){
    if(fout!=NULL) { fclose(fout); fout=NULL; }///還在讀的檔案要關掉
    if(fin==NULL) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        fscanf(fin, "%f", &angle[i] );
    }
    glutPostRedisplay();///重畫畫面!!
}
void keyboard( unsigned char key, int x, int y){
    if( key=='r' ){
        myRead();
    }
    if( key=='0' ) angleID=0;///預設是這一個
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}
```

## step02-2
step02-2_修正我們的專案目錄。原本GLUT專案因為freeglut.dll在很奇怪的freeglut的bin目錄中,所以那裡被設成工作目錄working_dir, 但是那真的是很奇怪的位置, 所以我們利用 Notepad++開啟 .cbp專案檔, 把 wroking_dir右邊的值改成小數點,代表專案所在目錄。最後把freeglut.dll也放一份到你的專案中,便完成了這個移植的任務

修正我們的工作目錄
1. 現在工作目錄很怪 C:\Users\user\Desktop\freeglut\bin 
2. 我們希望它在 我們的程式碼的那個目錄 week14_TRT_angle_write 之類的
3. 所以我們要修改專案(.cbp CodeBlocks Project) 的工作目錄!!!!
4. 可以利用 Notepad++ 來修改 .cbp 檔 (TODO: 裝 Notepad++)
5. 看 .cbp 檔裡, 有 working_dir="." 改成(雙引號裡面加小數點), 存檔
6. 手動把 C:\Users\user\Desktop\freeglut\bin 裡的 freeglut.dll 複製到你的專案目錄中 week14_TRT_angle_write_and_read
7. CodeBlocks 裡 Reload Project 就可以改變工作目錄囉!!


## step03-1
step03-1_講解timer的機制, 老師每天早上起床,鬧鐘就一直響, 起床設好下個鬧鐘後,再安心回去睡。glutTimerFunc(300, timer, 0) 只會播第1個鬧鐘。所以timer()裡要再設定下一個鬧鐘,這樣就會有源源不絕的鬧鐘了

之前有用過 glutIdleFunc(display) 速度很怪(快慢不一樣)
所以,有一種鬧鐘/廚房計時器 timer 會定時把你叫起來做事(像早上起床設很多鬧鐘)

1. File-New-Project, GLUT專妹, week14_timer
2. 設定timer: glutTimerFunc( 時間, timer, 參數t )
3. void timer(int t) 函式

```cpp
#include <GL/glut.h>
#include <stdio.h>
void timer(int t){///t的單位是ms
    ///1000代表1秒, 1500代表1.5秒
    printf("鬧鐘%d, 我起床了\n", t);///起床做事情

    printf("設定下一個鬧鐘\n");
    glutTimerFunc( 2000, timer, t+1);///2秒後
    //printf("設好鬧鐘,再回去睡\n");
}
void display()
{

}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14 timer");

    glutTimerFunc(3000, timer, 0);///3秒後,叫timer()
    glutDisplayFunc(display);
    glutMainLoop();
}
```

## step03-2
step03-2_有了timer()會固定時間呼叫到, 我們增加 PlaySound(檔名,NULL,SND_ASYNC);來播放do.wav檔案

```cpp
void timer(int t){///t的單位是ms
    ///1000代表1秒, 1500代表1.5秒
    printf("鬧鐘%d, 我起床了\n", t);///起床做事情
    PlaySound("do.wav", NULL, SND_ASYNC);
    printf("設定下一個鬧鐘\n");
    glutTimerFunc( 2000, timer, t+1);///2秒後
}
```

# Week15
電腦圖學 Week15 2022-05-30
1. 播聲音、播MP3
2. 播放動畫、內插
3. 機器人擺動作、跳舞

## step01-1
上週教的聲音 PlaySound(檔名, NULL, SND_ASYNC);
今天要稍微講解 參數, 對應的 lib檔 專案檔

1. #include <windows.h> 或用上週教的 #include <mmsystem.h>
2. PlaySounc("檔名.wav", NULL, SND_SYNC);
3. Setting-Compiler Setting, Linker Setting 加上 winmm

```cpp
///Week15-1_PlaySound.cpp
///#include <mmsystem.h>///上週教
#include <windows.h>///另一種寫法,結果一樣
int main()
{           ///先放不存在的檔     上週教 SND_ASYNC
    ///PlaySound("badbadbad.wav", NULL, SND_SYNC );
    PlaySound("07042111.wav", NULL, SND_SYNC );
}///Compile成功,      但是 link 失敗!!
/// .c .cpp =compile=> .o  =link=> .exe
///Setting-Compiler Setting 的 Linker Setting 加 winmm
```


## step01-2
比較差別 SND_ASYNC vs. SND_SYNC

```cpp
///Week15-2 SND_SYNC要等待同步 vs.
///SND_ASYNC 不用等待、不同步
#include <windows.h>
#include <stdio.h> ///printf()
int main()
{
    printf("現在在PlaySound()前\n");
    PlaySound("07042111.wav", NULL, SND_ASYNC);
    printf("現在在PlaySound()後\n");
    int N;
    scanf("%d", &N);///等你輸入數字
}
```


## step01-3
比較後發現 
1. 下載 Teams 老師放的 CMP3_MCI.h 
2. #include "CMP3_MCI.h"
3. 宣告 CMP3_MCI mp3 這個物件變數
4. mp3.Load("檔名.mp3"); mp3.Play(); 播放

以上都是簡單的 .cpp 檔, 不需要開 GLUT專案
(GLUT專案開也沒關係, 不開也沒關係)

```cpp
///Week15-3 希望能播放 mp3
///MP3檔案小 vs. WAV 檔案大 PlaySound()
///有壓縮/難     原始資料
#include "CMP3_MCI.h" ///下載,放在同目錄
#include <stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();
    printf("現在正在播放羊的聲音\n");
    int N;///找一個人卡住,不要結束
    scanf("%d", &N);
}
```

## step02-1
接續上週的程式 week14_angles_TRT_write_and_read 要能擺動作,擺好動作 再存一行動作即可

1. File-New-Project, GLUT專案 week15_angles_TRT_again
2. 從你的 github 找到對應程式,copy, 貼來 main.cpp
3. myWrite()可以寫一行
4. 原本 motion()裡一直呼叫 myWrite(), 把它刪掉
5. keyboard() 裡 if(key=='s') myWrite();//Save
6. 執行時, motion不會存檔, 按下 's' 才會存1行動作
7. 按下 'r' 會讀一行!!!

```cpp
void keyboard( unsigned char key, int x, int y){
    if( key=='r' ) myRead();
    if( key=='s' ) myWrite();///save
    if( key=='0' ) angleID=0;///預設是這一個
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}///用keyboard的按鍵,來決定等一下 motion()裡要改的 angle[i] 是哪一個
void mouse(int button, int state, int x, int y){///mouse按下去
    oldX = x;
}
void motion(int x, int y){
    angle[angleID] += (x-oldX);
    ///myWrite();///沒有必要一直寫檔啦
    oldX = x;
    glutPostRedisplay();
}
```

## step02-2
剛剛的程式, 會在工作執行目錄中, 產生 file.txt
也就是我們按下 's' 存1行動作, 按下4次 's' 就會存4行動作

這時候, 如果在記事本中, 把 file.txt 裡的 4行變成 40行, 那我們之後按下 'r' 讀動作時, 便會看到我們的動作竟然就變多了。

今天可能來不及教 interpolation 內插動作。因為希望今天能開始第4個作業, 也就是"讓你的機器人可以擺動作"



## step03-1
最後一節課, 與本週的作業相關。老師想示範 如何把機器人組起來, 並且可以擺動作, 以便存檔、編輯後, 完成動畫播放。

1. File-New-Project, GLUT專案 week15_homework_gundam_parts
2. glm.cpp glm.h 和 freeglut.dll 及 gundam 的 data資料夾,都放在你程式的目錄
3. 左邊的專案,右鍵 Add ... 把 glm.cpp 加進去
4. 程式碼加進去 前 #include "glm.h" 及 GLMmodel * pmodel = NULL;
5. 新的display()裡, 加入模型的程式
6. 小心, working_dir 工作在荒山野嶺, 要用 Notepad++ 把 .cbp 裡面改成 working_dir = "." 存檔, Reload
7. 再執行,就可以看到gundam了

```cpp
///week15_homework_gundam_parts
///要把 Gundam做出來, 需要 glm.h glm.cpp 及 gundam 5個檔案
#include <GL/glut.h>
#include <stdio.h> ///為了 printf, fprintf, fopen, fclose ..
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * bot = NULL;
GLMmodel * arm1 = NULL;
GLMmodel * arm2 = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * hand2 = NULL;
```

再改一下如何讀檔

```cpp
GLMmodel * myReadOne(char * filename){
    GLMmodel * one = NULL;
    if( one == NULL ){
        one = glmReadOBJ(filename);
        glmUnitize(one);
        glmFacetNormals(one);
        glmVertexNormals(one, 90);
    }
    return one;
}
void display()///準備最新的 display(), 有把每一塊都讀進來
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(head==NULL) head=myReadOne("data/head.obj");

    glmDraw(head, GLM_SMOOTH);

    glutSwapBuffers();
}
void displayNotParts()///準備新的 display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if( pmodel == NULL ){
        pmodel = glmReadOBJ("data/Gundam.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90);
    }
    glmDraw(pmodel, GLM_SMOOTH);

    glutSwapBuffers();
}
```

# Week16

## step01-0
上課前,有同學問上週最後一節課 1小時,做的任務(與回家作業相關),老師逐步示範
week16_review_model_TRT_angles

1. 3D Model 讀入
2. 調整位置!!! TRT 最下面的T
3. 再旋轉
3. 再掛上去

## step01-1
利用Excel來學習如何進行alpha內插,使用的公式是 alpha乘新的+(1-alpha)乘舊的
Excel 學習內插
1. Excel or Google Spreadsheet
2. t: 0.0 .... 1.0
3. alpha: 0.0 ... 1.0
4. angle = 13 ... 90
5. 內插公式 alpha*新的 + (1-alpha)*舊的

## step01-2
從上週 week15_angles_TRT_again改成 week16_interpolation 想要練習內插。作法是先把 myRead()改寫, 再新增 myInterpolate()函式,進行內插, 最後用 'p' 鍵來逐步呼叫 myInterpolate()

```cpp
float NewAngle[20], OldAngle[20];
void myRead(){
    if(fout!=NULL) { fclose(fout); fout=NULL; }///還在讀的檔案要關掉
    if(fin==NULL) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        OldAngle[i] = NewAngle[i];
        fscanf(fin, "%f", &NewAngle[i] );
        ///fscanf(fin, "%f", &angle[i] );
    }
    glutPostRedisplay();///重畫畫面!!
}
void myInterpolate(float alpha){
    for(int i=0; i<20; i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
        printf("%.2f ", angle[i] );
    }
    printf("\n");
    glutPostRedisplay();
}
float alpha=0;
void keyboard( unsigned char key, int x, int y){
    if( key=='p' ){
        myInterpolate(alpha);
        alpha = (alpha+0.01);
        if(alpha>1) alpha = alpha-1;
    }
    if( key=='r' ) myRead();
    if( key=='s' ) myWrite();///save
    if( key=='0' ) angleID=0;///預設是這一個
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}///用keyboard的按鍵,來決定等一下 motion()裡要改的 angle[i] 是哪一個
```
## step02-1
前一個範例要一直接'p'不太好,這裡改用 timer 自動做內插
1. 先把程式存4個動作, 把程式關掉
2. 利用 glutTimerFunc(0, timer, 0); 開始播放
3. 在 if(key=='p') 進行play
4. 先 myRead(); 再註冊 timer
5. void timer(t) 裡面做的事有:
6. 依照時間,算出適當的 alpha
7. 再由 alpha值傳給myInterpolate(alpha)來內插

```cpp
void myInterpolate(float alpha){
    for(int i=0; i<20; i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
        printf("%.2f ", angle[i] );
    }
    printf("\n");
    glutPostRedisplay();
}
///float alpha=0;
void timer(int t){
    float alpha = (t%100)/100.0; ///算出alpha
    if(t%100==0) myRead();///遇到100整除時,做新舊交接
    myInterpolate(alpha);
    glutTimerFunc(10, timer, t+1);
}
void keyboard( unsigned char key, int x, int y){
    if( key=='p' ){///play
        myRead();///先讀1行
        glutTimerFunc(0, timer, 0);///馬上開始播動畫
        ///myInterpolate(alpha);
        ///alpha = (alpha+0.01);
        ///if(alpha>1) alpha = alpha-1;
    }
    if( key=='r' ) myRead();
    if( key=='s' ) myWrite();///save
    if( key=='0' ) angleID=0;///預設是這一個
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}
```
## step02-2
使用timer內插時,如果時間切得不夠細,會讓內插的動作卡卡的。所以可以修改 t%100 讓它在動作間切100格更細, 動作會更順暢。記得 timer()呼叫的時間也要更短,才不會太慢

```cpp
void timer(int t){
    float alpha = (t%100)/100.0; ///算出alpha
    if(t%100==0) myRead();///遇到100整除時,做新舊交接
    myInterpolate(alpha);
    glutTimerFunc(10, timer, t+1);
}
```

## step03-1
最後一節課,介紹課本 Projection.exe 這個範例,裡面有 gluPerspective()及gluLookAt()這兩個函式。先介紹gluLookAt()的參數的,eye位置, center位置, up向量等, 再介紹gluPerspective()裡面 aspect ratio的意思。最後拿CodeBlocks的GLUT範例的glutReshapeFunc()來講解,並在motion()中持續修改camera的位置
1. File-New-Project, GLUT專案, week16_camera_lookat
2. 備份GLUT專案範例的 resize()函式, 改成 void reshape(int w, int h)
3. 我們10行 GLUT範例中, 加入 glutReshapeFunc(reshape) 讓視窗改變大小時, 會做對應修正
4. reshape()裡面,改用課本 gluPerspective() 的作法
5. 最後利用 motion() 在 mouse motion時, 移動 camera的位置

```cpp
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(2);///大茶壼
    glutSwapBuffers();
}
void motion(int x, int y)
{
    glMatrixMode(GL_MODELVIEW);///3D經過轉換到你最後的攝影機
    glLoadIdentity();
    gluLookAt( (x-150)/15.0, (y-150)/15.0, 3, ///eye
              0, 0, 0, ///center
              0, 1, 0);///up
    glutPostRedisplay();
}
void reshape(int w, int h)
{    const float ar = (float) w / (float) h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);///投影,把3D投射到2D畫面
    glLoadIdentity();
    gluPerspective(60, ar, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);///3D經過轉換到你最後的攝影機
    glLoadIdentity() ;
    gluLookAt( 0, 0, 3,   0, 0, 0,     0, 1, 0);
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week16 camera lookat");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMotionFunc(motion);

    glutMainLoop();
}
```

# Week17
電腦圖學 Week17 2022-06-13
1. 期末作品繳交方式
2. 期末作品評分方式
3. 網友問 push matrix 和 pop matrix 事件
4. 整學期大複習-示範期末作品怎麼做

## step01
介紹 Moodle 繳交期末作品的3個檔案, 其中圖檔會變成 slido 手機投票的縮圖。下下週上課時, 請用電腦 Teams 分享桌面, 再用 

## step02
老師想要示範如何完成期末作品,一步步慢慢來。
不要改別人的程式, 因為會改不出來。
(貼別人的程式 倒是還不錯) 5-10行

2022電腦圖學 Computer Graphics 授課教師: 葉正聖 銘傳大學資訊傳播工程系 每週主題: 程式環境、點線面顏色、移動/旋轉/縮放與矩陣(Matrix)、階層性關節轉動(T-R-T)、做出機器人、打光、貼圖、glu/glut函式、鍵盤、滑鼠、計時器(timer)、讀入3D模型、粒子系統、聲音、特效、投影矩陣、攝影機與運鏡、機器人2.0、期末作品


程式環境: Week01(freeglut,GLUT專案), Week10(OpenCV的設定), Week16(改 CBP 的 working_dir)

點線面顏色: 10行程式碼  display() main()前3行設定, 最後一行glutMainLoop()

打光: 8行 + 10多行

讀入3D模型:  模型在工作目錄, glm.h glm.cpp 加進去 #include "glm.h" 再 GLMmodel * body; 再...

貼圖: OpenCV 及 myTexture範例, 還有圖 而且畫 glmDraw(pmodel, GLM_TEXTURE | GLM_SMOOTH);

攝影機與運鏡: 透視投影法 gluPerspective,配上 glutReshapeFunc() 再上 gluLookAt()

兩張貼圖: Gundam, 木紋, 宣告2個整數 GLuint tex1, tex2; 在 main() 裡 
tex1 = myTexture("data/Diffuse.jpg"); 
tex2 = myTexture("data/wood.png");
在 display() 裡
glBindTexture(GL_TEXTURE_2D, tex1) 及 glBindTexture(GL_TEXTURE_2D, tex2) 來切換

把全部的模型讀入: 改寫 myReadGundam()改成 myReadOne() 及 myReadAll();

TRT: 必須要有中心點 才能把每個部位放好, 才能正確轉,才能掛在對的地方
可以使用 mouse motion 來知道值在哪裡
要經常註解程式,才能找到 T-R-T 的值