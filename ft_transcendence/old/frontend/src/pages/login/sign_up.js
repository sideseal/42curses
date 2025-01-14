export function pageSignUp() {
  const page = document.createElement('div');
  page.setAttribute('class', 'full-screen');
  const content = `
		<main class="form-signup text-center">
		  <p class="signup fw-bold">Sign Up</p>
		  <form id="signup-form" enctype="multipart/form-data">
			<div class="form-floating mb-3">
			  <input
				type="text"
				class="form-control"
				id="usernameInput"
				placeholder="Username"
				required
			  />
			  <label for="usernameInput" class="text-secondary">사용자 이름</label>
			</div>
			<div id="usernameError" class="text-danger"></div>
			<div class="form-floating mb-3">
			  <input
				type="password"
				class="form-control"
				id="passwordInput"
				placeholder="Password"
				required
			  />
			  <label for="passwordInput" class="text-secondary">비밀번호</label>
			</div>
			<div id="passwordError" class="text-danger"></div>
			<div class="mb-3">
			  <label for="imageInput" class="form-label text-secondary">프로필 이미지 선택</label>
			  <input
				type="file"
				class="form-control"
				id="imageInput"
				accept="image/*"
			  />
			</div>
			<div class="form-group">
				<input type="checkbox" id="agree" name="agree">
				<label for="agree"><a href="privacy_policy.html" target="_blank">개인정보 처리방침</a>에 동의합니다.</label>
			</div>
			<button type="submit" class="btn btn-outline-light form-signup">
			  Sign Up
			</button>
		  </form>
		</main>
	  `;

  page.innerHTML = content;
  return page;
}
