import { userState } from '../../../lib/state/state.js';
import { redirectRoute, route } from '../../../lib/router/router.js';
import { setCookie } from '../../../src/utils/cookie.js';
import {
  validateUsername,
  validatePassword,
} from '../../utils/formValidator.js';

async function requestSignUp(formData) {
  try {
    const response = await fetch('http://localhost:8000/api/account/signup/', {
      method: 'POST',
      body: formData, // JSON 대신 formData 사용
    });

    if (response.status !== 201) {
      throw new Error(response.status);
    }

    const data = await response.json();

    console.log('sign up data:', data);
    console.log('sign up data:', data.username);
    console.log('sign up data:', data.email);
    userState.setState({
      isLoggedIn: true,
      username: data.username,
      userEmail: data.email,
    });
    redirectRoute('/twofa');
  } catch (e) {
    switch (e.message) {
      case '400':
        alert(
          '400: Failed to fetch 42 authentication token. Try logging in again.'
        );
        break;
      case '415':
        alert('415: Unsupported Media Type. Try logging in again.');
        break;
      default:
        alert('Failed to proceed sign up process. Please login again.');
    }
    redirectRoute('/login');
  }
}

function checkAgree() {
  document
    .getElementById('signup-form')
    .addEventListener('submit', function (event) {
      var agreeCheckbox = document.getElementById('agree');
      if (!agreeCheckbox.checked) {
        alert('You must agree to the privacy policy.');
        event.preventDefault();
      }
    });
}

function handleSignUpSubmit() {
  document
    .getElementsByClassName('form-signup')[0]
    .addEventListener('submit', function (e) {
      e.preventDefault();

      const username = document.getElementById('usernameInput').value;
      const usernameError = document.getElementById('usernameError');
      if (!validateUsername(username, usernameError)) {
        return;
      }

      const password = document.getElementById('passwordInput').value;
      const passwordError = document.getElementById('passwordError');
      if (!validatePassword(password, passwordError)) {
        return;
      }

      const code = localStorage.getItem('code').replace('?code=', '');
      localStorage.removeItem('code');
      const image = document.getElementById('imageInput').files[0];

      const formData = new FormData();

      formData.append('username', username);
      formData.append('password', password);
      formData.append('code', code);
      if (image !== undefined) {
        formData.append('image', image);
      } else {
        formData.append('image', '');
      }

      for (let [key, value] of formData.entries()) {
        console.log(`${key}: ${value}`);
      }

      requestSignUp(formData);
    });
}

export function signUp() {
  handleSignUpSubmit();
  checkAgree();
}
