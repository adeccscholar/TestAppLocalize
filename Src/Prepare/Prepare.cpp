// Prepare.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pugixml.hpp"

#include "MyTools.h"

#include <iostream>
#include <string>
#include <memory>
#include <tuple>
#include <map>
#include <vector>
#include <algorithm>
#include <boost/locale.hpp>




// Bezeichner, Typ, Align, Caption, Hint, ID
using tplFormElements    = std::tuple<std::string, int, int, std::string, std::string, int>;
using vecFormElements    = std::vector<tplFormElements>;
using tplFormInformation = std::tuple<std::string, int>;
using tplFormData = std::tuple<tplFormInformation, vecFormElements>;
//using mapForms = std::map<std::string, tplFormData>;
using mapForms = std::vector<std::pair<std::string, tplFormData>>;

using tplTableCaptions = std::tuple<std::string, int, int>;
using vecTableCaptions = std::vector<tplTableCaptions>;
//using mapTableCaptions = std::map<std::string, vecTableCaptions>;
using mapTableCaptions = ::std::vector<std::pair<std::string, vecTableCaptions>>;

using tplRepositories = std::tuple<std::string, int>;
using vecRepositories = std::vector<tplRepositories>;
//using mapRepositories = std::map<std::string, vecRepositories>;
using mapRepositories = std::vector<std::pair<std::string, vecRepositories>>;


mapForms form_data = {   
 { "frmMain", { { "Testanwendung für Programmieren mit C++", 100 },  {
 { "btnPersonNew", 3, 3, "Person neuanlegen ...", "", 101 },
 { "memOutput", 7, 1, "", "", 102 },
 { "memError", 7, 1, "", "", 103 },
 { "btnPersonEdit", 3, 3, "Person bearbeiten ...", "", 104 },
 { "btnEmployeeNew", 3, 3, "Angestellter anlegen ...", "", 105 },
 { "btnEmployeeEdit", 3, 3, "Angestellter bearbeiten ...", "", 106 },
 { "btnPersonList", 3, 3, "Personenliste ...", "", 107 },
 { "btnRollDice", 3, 3, "Würfeln ...", "", 108 },
 { "edtValues", 0, 1, "", "", 109 },
 { "btnWork", 3, 3, "Bearbeiten ...", "", 110 },
 { "btnClose", 3, 3, "Schließen                ", "", 111 },
 { "sbMain", 8, 1, "Fertig", "", 112 }
} } },

 { "frmAddress", { { "Adressdaten", 120 },  {
 { "grpAddress", 2, 1, "Adresse", "", 121 },
 { "lblZipCodeCity", 1, 1, "PLZ / Ort:", "", 122 },
 { "lblStreetExtension", 1, 1, "Straße / Nummer:", "", 123 },
 { "edtZipCode", 0, 1, "", "", 124 },
 { "edtCity", 0, 1, "", "", 125 },
 { "edtStreet", 0, 1, "", "", 126 },
 { "edtStreetNumber", 0, 1, "", "", 127 }
} } },

 { "frmBanking", { { "Bankverbindung", 130 },  {
 { "grpBankingAccount", 2, 1, "Bankverbindung", "", 131 },
 { "lblBankName", 1, 1, "Name der Bank:", "", 132 },
 { "lblIBANNumber", 1, 1, "IBAN", "", 133 },
 { "lblBIC", 1, 1, "BIC", "", 134 },
 { "lblAccountHolder", 1, 1, "Kontoinhaber", "", 135 },
 { "edtBankName", 0, 1, "", "", 136 },
 { "edtIBANNumber", 0, 1, "", "", 137 },
 { "edtBIC", 0, 1, "", "", 138 },
 { "edtAccountHolder", 0, 1, "", "", 139 }
} } },

 { "frmPerson", { { "Personendatendialog", 150 },  {
 { "grpPerson", 2, 1, "Persondaten", "", 151 },
 { "lblSalutation", 1, 1, "Anrede:", "", 152 },
 { "lblFirstName", 1, 1, "Vorname:", "", 153 },
 { "lblName", 1, 1, "Name:", "", 154 },
 { "cbxSalutation", 6, 1, "", "", 155 },
 { "edtFirstName", 0, 1, "", "", 156 },
 { "edtName", 0, 1, "", "", 157 },
 { "btnOk", 3, 3, "Speichern", "", 158 },
 { "btnCancel", 3, 3, "Abbrechen", "", 159 }
} } },

 { "frmEmployee", { { "Angestelltendatendialog", 160 },  {
 { "grpEmployee", 2, 1, "Angestellter", "", 161 },
 { "lblDepartment", 1, 1, "Abteilung:", "", 162 },
 { "lblJobDescription", 1, 1, "Beschreibung:", "", 163 },
 { "lblSalary", 1, 1, "Gehalt:", "", 164 },
 { "lblTaxNumber", 1, 1, "Steuernummer:", "", 165 },
 { "lblSocialSecurityNumber", 1, 1, "Versicherungsnummer:", "", 166 },
 { "edtJobDescription", 0, 1, "", "", 167 },
 { "edtSalary", 0, 2, "", "", 168 },
 { "edtTaxNumber", 0, 1, "", "", 169 },
 { "edtSocialSecurityNumber", 0, 1, "", "", 170 },
 { "cbxDepartment", 6, 1, "", "", 171 },
 { "chkActive", 5, 1, "Aktiv", "", 172 },
 { "btnOk", 3, 3, "Speichern", "", 173 },
 { "btnCancel", 3, 3, "Abbrechen", "", 174 }
} } },

 { "frmPersonList", { { "Personen anzeigen ...", 180 },  {
 { "lvPersons", 9, 1, "", "", 181 },
 { "btnOk", 3, 1, "Speichern", "", 182 }
} } },

 { "frmWork", { { "Formular zum Verarbeiten der Daten ...", 190 },  {
 { "lblFile", 1, 1, "Datendatei:", "", 191 },
 { "edtFile", 0, 1, "", "", 192 },
 { "lvData", 9, 1, "", "", 193 },
 { "memError", 7, 1, "", "", 194 },
 { "btnSelect", 3, 1, "Auswahl ...", "", 195 },
 { "btnStart", 3, 1, "Auswertung", "", 196 },
 { "btnClose", 3, 1, "Schließen", "", 197 }
} } }
};

mapTableCaptions table_captions = {
{ "person_list", {
   { "Anrede", 120, 1 },
   { "Vorname", 200, 1 },
   { "Name", 200, 1 },
   { "Alter", 110, 2 }
} },

{ "address_list", {
   { "PLZ   ", 150, 3 },
   { "Ort", 250, 1 },
   { "Stadtbezirk", 250, 1 },
   { "Straße", 250, 1 },
   { "Nummer ", 150, 2 },
   { "Entfernung", 200, 2 },
   { "Winkel", 200, 2 }
} }
};

mapRepositories repositories = {
{ "Salutations", {
   { "Herr", 1 },
   { "Frau", 2 },
   { "Diverse", 3 },
   { "unbekannt", 9 }
} },

{ "Departments", {
   { "Buchhaltung", 1 },
   { "Controlling", 2 },
   { "Personal", 3 },
   { "Marketing", 4 },
   { "EDV", 5 },
   { "Einkauf", 6 },
   { "Produktion 1", 7 },
   { "Produktion 2", 8 },
   { "Verkauf", 9 },
   { "Unterstützung", 10 },
   { "Produktionshilfe", 11 }
} }
};


void read(std::string const& strFile) {
   auto error_message = [&strFile](pugi::xml_parse_result const& result) {
      std::cerr << "XML [" << strFile << "] parsed with errors\n";
      std::cerr << "Error description: " << result.description() << "\n";
      std::cerr << "Error offset: " << result.offset
         << " (error at [..." << (strFile.c_str() + result.offset) << "]\n\n";
   };

   pugi::xml_document doc;
   pugi::xml_parse_result result = doc.load_file(strFile.c_str(), pugi::parse_default | pugi::parse_fragment, pugi::encoding_latin1);
   if (!result) error_message(result);

   pugi::xml_node forms = doc.find_node([](pugi::xml_node& node) { return strcmp(node.name(), "forms") == 0; });
   for (pugi::xml_node form : forms.children()) {
      std::cout << form.name() << " " << form.attribute("name").value() << std::endl;
      std::cout << form.child("caption").child_value() << std::endl;
      for (pugi::xml_node comp : form.child("components").children()) {
         std::cout << comp.attribute("name").value() << " -- ";
         std::cout << comp.child("text").child_value() << std::endl;
         }
      }
}

void write(std::string const& strFile) {
   pugi::xml_document doc;
   auto declarationNode = doc.append_child(pugi::node_declaration);
   declarationNode.append_attribute("version") = "1.0";
   declarationNode.append_attribute("encoding") = "ISO-8859-1"; // "UTF-8";
   declarationNode.append_attribute("standalone") = "yes";

   auto root_forms = doc.append_child("forms");
   auto root_lists = doc.append_child("lists");
   auto root_repos = doc.append_child("repositories");

   //for (auto [key, data] : form_data) {
   std::for_each(form_data.cbegin(), form_data.cend(), [&root_forms](auto value) {
      std::string key;
      tplFormData data;
      std::tie(key, data) = value;
      auto node_form = root_forms.append_child("form");
      node_form.append_attribute("name") = key.c_str();
      node_form.append_attribute("id") = std::get<1>(std::get<0>(data));
      auto node_caption = node_form.append_child("caption");
      node_caption.append_child(pugi::node_pcdata).set_value(std::get<0>(std::get<0>(data)).c_str());
      auto node_components = node_form.append_child("components");
      for (auto component : std::get<1>(data)) {
         auto node_name = node_components.append_child("component");
         node_name.append_attribute("name") = std::get<0>(component).c_str();
         node_name.append_attribute("ID") = std::get<5>(component);
         node_name.append_attribute("type") = std::get<1>(component);
         node_name.append_attribute("alignment") = std::get<2>(component);
         auto node_text = node_name.append_child("text");
         node_text.append_child(pugi::node_pcdata).set_value(std::get<3>(component).c_str());
         auto node_hint = node_name.append_child("hint");
         node_hint.append_child(pugi::node_pcdata).set_value(std::get<4>(component).c_str());
      }
      });

   std::for_each(table_captions.cbegin(), table_captions.cend(), [&root_lists](auto value) {
      auto const& [key, data] = value;
      auto node_list = root_lists.append_child("list");
      node_list.append_attribute("name") = key.c_str();
      auto node_captions = node_list.append_child("cols");
      std::for_each(data.cbegin(), data.cend(), [&node_captions](auto const& val) {
         auto node_row = node_captions.append_child("col");
         node_row.append_attribute("name") = std::get<0>(val).c_str();
         node_row.append_attribute("width") = std::get<1>(val);
         node_row.append_attribute("alignment") = std::get<2>(val);
         });
      });

   std::for_each(repositories.cbegin(), repositories.cend(), [&root_repos](auto value) {
      auto const& [key, data] = value;
      auto node_repo = root_repos.append_child("repository");
      node_repo.append_attribute("name") = key.c_str();
      auto node_items = node_repo.append_child("items");
      std::for_each(data.cbegin(), data.cend(), [&node_items](auto const& val) {
         auto node_item = node_items.append_child("item");
         node_item.append_attribute("name") = std::get<0>(val).c_str();
         node_item.append_attribute("ID") = std::get<1>(val);
         });
      });

   doc.save_file(strFile.c_str(), PUGIXML_TEXT("  "), pugi::format_no_declaration, pugi::encoding_latin1);

}

int main() {

   write("D:\\Test\\LocalizeFirstApp.xml");
   read("D:\\Test\\LocalizeFirstApp.xml");

}



