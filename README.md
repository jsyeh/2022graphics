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
