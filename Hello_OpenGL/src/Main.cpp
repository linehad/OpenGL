#include <iostream>
#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
using namespace std;

void OnFramebufferSizeChange(GLFWwindow* window, int width, int height) {
    SPDLOG_INFO("framebuffer size changed: ({} x {})", width, height);
    glViewport(0, 0, width, height); // OpenGL의 뷰포트를 윈도우 크기에 맞게 조정
}

void OnKeyEvent(GLFWwindow* window,
    int key, int scancode, int action, int mods) {
    SPDLOG_INFO("key: {}, scancode: {}, action: {}, mods: {}{}{}",
        key, scancode,
        action == GLFW_PRESS ? "Pressed" :
        action == GLFW_RELEASE ? "Released" :
        action == GLFW_REPEAT ? "Repeat" : "Unknown",
        mods & GLFW_MOD_CONTROL ? "C" : "-",
        mods & GLFW_MOD_SHIFT ? "S" : "-",
        mods & GLFW_MOD_ALT ? "A" : "-");
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void Render() {
	
}

int main(int argc, const char** argv) {
	SPDLOG_INFO("Start Program");

	// GLFW 라이브러리 초기화, 실패하면 에러 출력후 종료.
	if (!glfwInit()) {
		const char* description = nullptr;
		glfwGetError(&description);
		SPDLOG_ERROR("Failed to initialize GLFW: {}", description);
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// GLFW 윈도우 생성
	SPDLOG_INFO("Create GLFW window");
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,WINDOW_NAME, nullptr, nullptr);
	if (!window) {
		SPDLOG_ERROR("Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// glad를 활용한 OpenGL 함수 로딩
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		SPDLOG_ERROR("failed to initialize glad");
		glfwTerminate();
		return -1;
	}
	auto glVersion = glGetString(GL_VERSION);
	SPDLOG_INFO("OpenGL context version: {}", reinterpret_cast<const char*>(glVersion));

	OnFramebufferSizeChange(window, WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwSetFramebufferSizeCallback(window, OnFramebufferSizeChange);
	glfwSetKeyCallback(window, OnKeyEvent);

	// GLFW 루프 실행, 윈도우 close 버튼을 누르면 정상 종료
	SPDLOG_INFO("Start main Loop");
	while (!glfwWindowShouldClose(window)) {
		//이벤트(키보드 입력이나 마우스 이동 이벤트)가 발생하였는지 확인하고 윈도우 상태를 업데이트 하며 정해진 함수(콜백 함수를 통해 등록할 수 있는)를 호출.
		glfwPollEvents();
		glClearColor(0.0f, 0.1f, 0.2f, 1.0f); // 화면을 지울 색상을 지정
		glClear(GL_COLOR_BUFFER_BIT); // 색상 버퍼를 비움
		glfwSwapBuffers(window); // 더블 버퍼링을 사용하는 경우, 프론트 버퍼와 백 버퍼를 교체
	}

	// GLFW 라이브러리 종료
	SPDLOG_INFO("Terminate GLFW");
	glfwTerminate();
	return 0;
}