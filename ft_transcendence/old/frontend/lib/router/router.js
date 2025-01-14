// pages
import { pageLogIn } from '../../src/pages/login/sign_in.js';
import { pageSignUp } from '../../src/pages/login/sign_up.js';
import { pageProfile } from '../../src/pages/profile.js';
import { pageGame } from '../../src/pages/game.js';
import { pageTournament } from '../../src/pages/tournament.js';
import { pageSwitch } from '../../src/pages/switch.js';
import { pageTwoFA } from '../../src/pages/login/twofa.js';
import { PageNotFound } from '../../src/pages/404.js';
// state
import {
  gameState,
  globalState,
  routeState,
  userState,
} from '../state/state.js';
// render
import { renderAll } from '../render/render.js';
// router
import { navigate } from './navigate.js';
// utils
import { initUserInfo } from '../../src/utils/initUser.js';

export const routes = {
  '/login': { name: 'Login', page: pageLogIn, component: [], onRender: [] },
  '/signup': {
    name: 'Signup',
    page: pageSignUp,
    component: [],
    onRender: [],
  },
  '/profile': {
    name: 'Profile',
    page: pageProfile,
    component: [],
    onRender: [],
  },
  '/game': { name: 'Game', page: pageGame, component: [], onRender: [] },
  '/tournament': {
    name: 'Tournament',
    page: pageTournament,
    component: [],
    onRender: [],
  },
  '/logout': {
    name: 'Logout',
    page: pageSwitch,
    component: [],
    onRender: [],
  },
  '/twofa': { name: 'TwoFA', page: pageTwoFA, component: [], onRender: [] },
  '/switch': {
    name: 'Switch',
    page: pageSwitch,
    component: [],
    onRender: [],
  },
  '/404': { name: '404', page: PageNotFound, component: [], onRender: [] },
};

export function routeByState(href) {
    return href;
}

// 기본 경로를 설정. (/ -> /profile)
export function setDefaultPath(href = window.location.pathname) {
  routes['/'] = routes['/profile']; // navbar에 경로 추가가 되지 않도록 함

  if (href === '/' || href === '/login') {
    return '/';
  } else {
    return href;
  }
}

export function redirectRoute(path) {
  const target = navigate(routes, path, true);
  renderAll(target);

  routeState.setState({ currentRoute: target }, false); // 무한 루프 방지

  if (globalState.getState().isLoggedIn) {
    userState.ping(); // userBox 업데이트
  }

  if (target.onRender) {
    target.onRender.forEach((func) => {
      func();
    });
  }
}

let previousPath = '';

export function route(
  path = window.location.pathname,
  updateHistory = true,
  callListeners = true
) {
  // 이전 경로와 동일한지 확인하여 중복 네비게이션 방지
  if (path === previousPath) return;
  previousPath = path;

  // 경로에 해당하는 라우트 객체 가져오기. 없으면 404
  const target = routes[path] || routes['/404'];

  // 히스토리 업데이트가 필요한 경우에만 pushState 호출
  if (updateHistory) {
    window.history.pushState({}, '', path);
  }
  // 페이지 컴포넌트 렌더링
  renderAll(target);
//
  routeState.setState({ currentRoute: target }, callListeners);
//  gameState.setState({ currentGameStatus: 'idle' });
//  userState.ping(); // userBox 업데이트
//
  // 라우트 객체에 onRender 콜백이 있으면 호출
  if (target.onRender) {
    target.onRender.forEach((func) => {
      func();
    });
  }
}

export function firstRoute(path) {
  const target = navigate(routes, path, false);
  renderAll(target);

  routeState.setState({ currentRoute: target });
  gameState.setState({ currentGameStatus: 'idle' });

      if (target.onRender) {
        target.onRender.forEach((func) => {
          func();
        });
    }

//  if (globalState.getState().isLoggedIn) {
//    initUserInfo().then(() => {
//      userState.ping(); // userBox 업데이트
//      if (target.onRender) {
//        target.onRender.forEach((func) => {
//          func();
//        });
//      }
//    });
//  }
  // console.log(path, target);
}
