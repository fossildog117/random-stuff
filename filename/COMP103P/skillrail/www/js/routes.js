angular.module('app.routes', [])

.config(function($stateProvider, $urlRouterProvider) {

  // Ionic uses AngularUI Router which uses the concept of states
  // Learn more here: https://github.com/angular-ui/ui-router
  // Set up the various states which the app can be in.
  // Each state's controller can be found in controllers.js
  $stateProvider



    .state('login', {
      url: '/login',
      templateUrl: 'templates/login.html',
      controller: 'loginCtrl'
    })

    .state('side-menu21.home', {
      url: '/businessMenu',
      views: {
        'side-menu21': {
          templateUrl: 'templates/home.html',
          controller: 'homeCtrl'
        }
      }
    })

    .state('side-menu21.listings', {
      url: '/listings',
      views: {
        'side-menu21': {
          templateUrl: 'templates/listings.html',
          controller: 'listingsCtrl'
        }
      }
    })

    .state('side-menu21.profile', {
      url:'/profile',
      views: {
        'side-menu21': {
          templateUrl: 'templates/profile.html',
          controller: 'profileCtrl'
        }
      }
    })

    .state('side-menu21.newListing', {
      url: '/newListing',
      views: {
        'side-menu21': {
          templateUrl: 'templates/newListing.html',
          controller: 'newListingCtrl'
        }
      }
    })

    .state('side-menu21', {
      url: '/side-menu',
      abstract:true,
      templateUrl: 'templates/side-menu21.html'
    })
    ;

  // if none of the above states are matched, use this as the fallback
  $urlRouterProvider.otherwise('/login');

});
