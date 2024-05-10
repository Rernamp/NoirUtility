#include "imgui.h"
#include <implot.h>

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

class Application {
public:	
	static float function(float x) {
		return 2 * x * x + 5 * x - 3;
	}
	static float dFunction(float x) {
		return 4 * x + 5;
	}
	Application() {
		updateArray();
	}
	void update() {
		if (ImGui::Begin("My First ImGui Window", nullptr, ImGuiWindowFlags_NoCollapse)) {
			if (ImGui::SliderInt("Iteration", &_iteration, 1, 1000)) {
				updateArray();
			}
			if (ImPlot::BeginPlot("My Plot")) {
				ImPlot::PlotLine("My Line Plot", timePoints.data(), yData.data(), timePoints.size());
				ImPlot::EndPlot();
			}
			ImGui::End();
		}
	}
private:
	void updateArray() {
		static constexpr float pi = 3.14159265358979f;
		static constexpr float deltaTime = 1e-3f;
		static constexpr float startTime = -10.f;
		static constexpr float stopTime = 10.f;
		static constexpr float plotTime = 1.f;

		std::size_t numberData = (stopTime - startTime) / deltaTime;
		yData.clear();
		timePoints.clear();
		for (std::size_t i = 0; i < numberData; i++) {
			float timePoint = startTime + static_cast<float>(i) * deltaTime;
			yData.push_back(function(timePoint));
			timePoints.push_back(timePoint);
		}
	}
	int _iteration = 1;
	std::vector<float> timePoints {};
	std::vector<float> yData{};
};