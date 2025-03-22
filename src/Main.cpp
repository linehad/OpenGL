#include <iostream>
#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>
using namespace std;

int main(int argc, const char** argv) {
	SPDLOG_INFO("Start Program");

	// GLFW 라이브러리 초기화, 실패하면 에러 출력후 종료.
	if (!glfwInit()) {
		const char* description = nullptr;
		glfwGetError(&description);
		SPDLOG_ERROR("Failed to initialize GLFW: {}", description);
		return -1;
	}

	// GLFW 윈도우 생성
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,WINDOW_NAME, nullptr, nullptr);
	if (!window) {
		SPDLOG_ERROR("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}

	// GLFW 루프 실행, 윈도우 close 버튼을 누르면 정상 종료
	SPDLOG_INFO("Start main Loop");
	while (!glfwWindowShouldClose(window)) {
		//이벤트(키보드 입력이나 마우스 이동 이벤트)가 발생하였는지 확인하고 윈도우 상태를 업데이트 하며 정해진 함수(콜백 함수를 통해 등록할 수 있는)를 호출.
		glfwPollEvents();
	}

	// GLFW 라이브러리 종료
	SPDLOG_INFO("Terminate GLFW");
	glfwTerminate();
	return 0;
}