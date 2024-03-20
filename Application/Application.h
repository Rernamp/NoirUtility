#include "imgui.h"

#include <iostream>
#include <string>

class Application {
public:
	void update() {
		ImGui::Begin("My First ImGui Window");

		ImGui::Text("Game field");
		ImGui::BeginTable("Persons", columns);
		for (std::size_t column = 0; column < columns; ++column) {
			ImGui::TableNextRow();
			for (std::size_t row = 0; row < rows; ++row) {
				ImGui::TableNextColumn();
				std::string data = "column: " + std::to_string(column) + " row: " + std::to_string(row);
				ImGui::Text(data.c_str());
			}
		}
		ImGui::EndTable();

		

		ImGui::End();
	}
private:
	std::size_t rows = 5;
	std::size_t columns = 5;
};