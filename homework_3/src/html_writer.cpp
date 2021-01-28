#include "../include/html_writer.hpp"
#include <iomanip>
#include <iostream>
#include <string>

void html_writer::OpenDocument() {
  std::cout << "<!DOCTYPE html>" << std::endl;
  std::cout << "<html>" << std::endl;
}

void html_writer::CloseDocument() { std::cout << "/html" << std::endl; }

void html_writer::AddCSSStyle(const std::string &stylesheet) {
  std::cout << "<head>" << std::endl;
  std::string rel = R"("stylesheet")";
  std::string type = R"("text/css")";

  std::cout << "<link rel=" << rel << " "
            << "type=" << type << " "
            << "href=" << stylesheet << " />" << std::endl;
  std::cout << "</head>" << std::endl;
}
void html_writer::AddTitle(const std::string &title) {
  std::cout << "<title>" << title << title << "</title>" << std::endl;
}
void html_writer::OpenBody() { std::cout << "<body>" << std::endl; }
void html_writer::CloseBody() { std::cout << "</body>" << std::endl; }
void html_writer::OpenRow() {
  std::cout << R"("<div class= "row">)" << std::endl;
}
void html_writer::CloseRow() { std::cout << "</div>" << std::endl; }
void AddImage(const std::string &img_path, const std::string &image_name,
              float &score, bool highlight = false) {
  if (highlight) {
    std::cout << "<div class="
              << R"("column")"
              << "style="
              << R"("border: 5px solid green>")" << std::endl;
  } else {
    std::cout << "<div class="
              << R"("column">)" << std::endl;
  }
  std::cout << "<h2>" << image_name << "</h>" << std::endl;
  std::cout << "<img src ="
            << "\"" << img_path << "\""
            << " />" << std::endl;
  float non_const_imagescore = score;
  std::cout << "<p>score = " << std::setprecision(2) << std::fixed
            << non_const_imagescore << "</p>" << std::endl;
  std::cout << "</div>" << std::endl;
}
