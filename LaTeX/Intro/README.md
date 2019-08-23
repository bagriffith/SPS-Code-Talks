LaTeX is a markup language used to format documents, and is especcially useful when whriting academic papers or formatting math. This code talk is a basic overview of LaTeX relevant to math and physics students. The actual demo created during the talk is in the demo folder. These notes are also available as a pdf and LaTeX document to provide more exaples of using LaTeX.

# Running this demo

All options are discussed at greater length bellow, but the easiest way to get started is to copy it into an [Overleaf](https://www.overleaf.com/) project.
1. You will need to create an account, click register ang sign up.
1. Click New Project and give this demo a name ("Code talk LaTeX Demo" for example)
1. Click upload in the upper left area of the screen and upload "demo.tex" and "example.png"
1. Hit Recompile and a pdf will be created on the the right side of the webpage

# Notes

## Editors

LaTeX is not a specific program, but a markup language for preparing documents. Because of this, there are multiple ways to use it.

### Dedicated LaTeX Editors

There are many, but notably TeXworks. Opening the program will open a blank LaTeX document. Just begin typing.
A useful feature is that it shows the rendered PDF in another window.

### Web Editors

There are also many of these, but [Overleaf](https://www.overleaf.com/) is the most popular. You begin by creating a new project. The file will be prefiled with text. You can clear it to follow along.

It doesn't store the files on your computer, but it can be used on any device without installing anything. It also displays the rendered PDF to the side.

### Text Editors and Terminal

And text editor can be used to create LaTeX files. The files are then rendered using a terminal command (Discussed Below). This is preferred setup for using LaTeX. I use the Emacs editor. The rendered PDFs can then be viewed as PDFs are normally.

## Basic Outline

The fundamental structure for LaTeX has 2 parts.

Firstly, a format must be specified with
```LaTeX
\documentclass{article}
```

```LaTeX
\begin{document}
  Some text goes here.
\end{document}
```

## Compiling/Rendering

A LaTeX file is used as instructions to create a PDF. The process of making the PDF is called compiling/rendering. The process of doing this depends on the editor used.

For TeXworks, you press the green play button at the top. This will generate a PDF and update the document display.

On [Overleaf](https://www.overleaf.com/) you hit the Recompile button. This will generate a PDF and update the document display, and provide a button to download the PDF.

When using a text editor and a terminal you compile used a command. Go to the location of the \LaTeX\ file in the terminal and execute the command `pdflatex your-file.tex`. 'your-file' should be replaced with the actual file name. This will generate the PDF which can be viewed as normal.

## Titles

To format a title, place the following above the document section.

```LaTeX
\title{\LaTeX \ Example}
\author{Brady Griffith}
\date{October 18, 2017}
```

And at the beginning of the document section add

```LaTeX
\maketitle
\newpage
```

## Sections

Note that the star suppresses auto-numbering

```LaTeX
\section*{Question 1}
\subsection*{Part A}
```

## Math

```LaTeX
  The velocity of the particle is given by $v(t) = at$.

  To find the position, velocity is integrated with respect to time.

  $$ x(t) = \int_{t_0}^{t_1} v(t) dt = \frac{a}{2} t^2 + x_0 $$
```

## Custom Headers and Footers

I prefer to have my name, the assignment, and the page number in the header of my homeworks. You do that by firstly importing the fancyhdr package

```LaTeX
\usepackage{fancyhdr}
```

And then you define the format by having the following before the document section.

```LaTeX
\pagestyle{fancy}
\fancyhead{}
\fancyfoot{}
\fancyhead[L]{Brady Griffith}
\fancyhead[C]{\LaTeX \ Example}
\fancyhead[R]{\thepage}
```

## Tables

```LaTeX
\subsection*{Part B}
The positions for 1s and 2s are given. \\
\begin{tabular}{ l | l }
  t (s) & x (m) \\ \hline
  1 & $\frac{1}{2}$ \\
  2 & 2 \\
\end{tabular}
```

## Graphics
In the header

```LaTeX
\usepackage{graphicx}
```

In the body, where example is the image without an extention

```LaTeX
\includegraphics[width=2in]{example}
```

## Matrices
In the header

```LaTeX
\section*{Question 3}
The following equations
$$ 2x + 3y $$
$$ 4x + 5y $$
are given by the following matrix
\[
\begin{bmatrix}
  2 & 3 \\
  4 & 5
\end{bmatrix}
\]
```

## Aligned Equations
Aligned equations are helpful way to show a lot of algebra. To use them in the heading

```LaTeX
\usepackage{amsmath}
```

In the body an ampridant align together

```LaTeX
\section*{Question 4}
\begin{align*}
  a &= 2x + 2y \\
    &= 2(x + y)
\end{align*}
```

## Intro to Tikz and Circuits

Tikz is a procedural graphics tool built into LaTeX, and circuitikz is an implementation of it. There are many. Chess Patterns, Feynman Diagrams, and more. Google them and read their docs

To generate a diagram

```LaTeX
\begin{circuitikz} \draw
(0,0) to[short, o-] (-6,0)
      to[american voltage source,l=$V$] (-6,4) -- (-4,4)
      to[short, -o] (0,4)
      (-2,0) to[R, l=$R_1$] (-2,4)
      ;
\end{circuitikz}
```

## Code Snippets
Code listings support many languages, including Mathematica, C, and Matlab. To use this, in the header

```LaTeX
\usepackage{listings}
```

In the body

```LaTeX
\section*{Question 6}
\begin{lstlisting}[language=FORTRAN, caption=FORTRAN example]
  PROGRAM EXAMPLE
    INTEGER :: N = 3 
    N = N + 1
    PRINT *, N
  END PROGRAM EXAMPLE
\ end{lstlisting}
```

## More Resources

Google is usually the best way to find resources, but when choosing links, I find that the best answers are on the following sites

* https://www.sharelatex.com/learn
* https://en.wikibooks.org/wiki/LaTeX
* https://tex.stackexchange.com/
