
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// mi-am zis ca ar fi o aplicatie practica draguta un parser basic de html asa ca am scris si niste clase mici ajutatoare pentru asta.
#include "html.cpp"
#include "tree.cpp"

int main (int argc, char const *argv[])
{
  // exemple conform cerintei
  Tree ex0(Tag("0")), ex1(Tag("1")), ex2(Tag("2")), ex3(Tag("3")), ex4(Tag("4")), ex5(Tag("5")), ex6(Tag("6"));
  
  ex0 += ex1;
  ex0 += ex4;
  ex1 += ex2;
  ex1 += ex3 += ex5 += ex6;
  
  cout << "Breadth first search: " << ex0.bfs() << endl;
  cout << "Depth first search: " << ex0.dfs() << endl;
  
  cout << ex0;
  
  cout << "Height: " << ex0.get_height() << endl;
  
  // iar acum, o pagina web, in afara cerintei problemei
  
  Tree dom(Tag("html"));
  
  // head
  Tree head(Tag("head"));
  
  Tree title(Tag("title"));
  Tree title_content(Tag("Yay! Output!", 1));
  title += title_content;
  head += title;
  
  Tree bootstrap(Tag("link").attr("href", "http://twitter.github.io/bootstrap/assets/css/bootstrap.css").attr("rel", "stylesheet"));
  head += bootstrap;
  
  dom += head;
  
  // body
  Tree body(Tag("body"));
  
  Tree container(Tag("div").attr("class", "container"));
  
  Tree hero(Tag("div").attr("class", "hero-unit"));
  Tree greeting(Tag("h1"));
  Tree greeting_content(Tag("Hello!", 1));
  greeting += greeting_content;
  hero += greeting;
  Tree paragraph(Tag("p"));
  Tree paragraph_content(Tag("Pagina asta probabil ca nu o sa arate ok daca nu exista o conexiune activa la net. Si fiindca nu am stiut ce sa scriu mai departe aici, am pus programul sa isi outputeze codul sursa. Aproape, ar mai trebui si global substitution pentru &lt; si &gt;.", 1));
  paragraph += paragraph_content;
  hero += paragraph;
  container += hero;
  
  Tree pre(Tag("pre"));
  string quine;
  ifstream in ("main.cpp");
  while (in) {
    string line; getline (in, line);
    quine += line + "\n";
  }
  in.close ();
  Tree pre_content(Tag(quine, 1));
  pre += pre_content;
  container += pre;
  
  body += container;
  
  dom += body;
  
  ofstream out ("index.html");
  out << "<!DOCTYPE html>\n";
  out << dom;
  out.close ();
  
  return 0;
}