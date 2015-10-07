#include <stdio.h>
#include <fstream>
#include <iostream>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Tree.H>

void TreeCallback(Fl_Widget *w, void *data) {
  Fl_Tree *tree = (Fl_Tree*)w;
  Fl_Tree_Item *item = (Fl_Tree_Item*)tree->callback_item();
  if ( ! item ) return;
  switch ( tree->callback_reason() ) {
    case FL_TREE_REASON_SELECTED: {
      char pathname[256];
      tree->item_pathname(pathname, sizeof(pathname), item);
      fprintf(stderr, "TreeCallback: Item selected='%s', Full pathname='%s'\n", item->label(), pathname);
      break;
    }
    case FL_TREE_REASON_DESELECTED:
      // fprintf(stderr, "TreeCallback: Item '%s' deselected\n", item->label());
      break;
    case FL_TREE_REASON_OPENED:
      // fprintf(stderr, "TreeCallback: Item '%s' opened\n", item->label());
      break;
    case FL_TREE_REASON_CLOSED:
      // fprintf(stderr, "TreeCallback: Item '%s' closed\n", item->label());
      break;
    default:
      break;
  }
}

int main(int argc, char *argv[]) {
  Fl::scheme("gtk+");
  Fl_Double_Window *win = new Fl_Double_Window(250, 400, "Simple Tree");

  std::ifstream test("test.json");
  std::string str((std::istreambuf_iterator<char>(test)),
                   std::istreambuf_iterator<char>());
  rapidjson::Document doc;
  doc.Parse(str.c_str());

  win->begin();
  {
    // Create the tree
    Fl_Tree *tree = new Fl_Tree(10, 10, win->w()-20, win->h()-20);
    tree->showroot(0);				// don't show root of tree
    tree->callback(TreeCallback);		// setup a callback for the tree

    for (auto it = doc.Begin(); it != doc.End(); it++) {
        for (auto mit = it->MemberBegin(); mit != it->MemberEnd(); mit++) {
            std::cout << mit->name.GetString();
            tree->add(mit->value.GetString());
        }
    }
  }
  win->end();
  win->resizable(win);
  win->show(argc, argv);
  return(Fl::run());
}

//
// End of "$Id: tree-simple.cxx 10015 2013-11-06 20:12:08Z greg.ercolano $".
//
