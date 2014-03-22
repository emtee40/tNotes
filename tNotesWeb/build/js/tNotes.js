define("setting",[],function(){var e=Backbone.Model.extend({localStorage:new Backbone.LocalStorage("setting"),defaults:{id:0,folderId:1,noteId:1,style:"default",contentViewerStyle:"default"},initialize:function(){this.bind("change",function(){this.save()})}}),t=new e;return localStorage.setting?t.fetch():t.save(),t}),define("contentViewer",["setting"],function(e){var t=Backbone.View.extend({el:$("#content"),$noteContent:$("#note-content"),events:{"click .change-style":"changeStyleClicked"},initialize:function(){var t=e.get("contentViewerStyle");this.changeStyle(t)},changeStyle:function(t){this.$noteContent.attr("class","panel-body "+t),e.set("contentViewerStyle",t)},changeStyleClicked:function(e){var t=$(e.target);style=t.attr("data-style"),this.changeStyle(style)}}),n=new t;return n}),define("hint",[],function(){var e=Backbone.View.extend({el:$("#hint"),$hintContent:$("#hint-content"),$hintTitle:$("#hint-title"),autoDismiss:!0,events:{"click .close":"close"},initialize:function(){this.setType("info").setTitle("提示").setContent("提示信息")},close:function(){return this.$el.slideUp("fast"),this},setAutoDismiss:function(e){return this.autoDismiss=e,this},setContent:function(e){return this.$hintContent.html(e),this},setTitle:function(e){return this.$hintTitle.html(e),this},setType:function(e){return this.$el.attr("class","alert alert-dismissable display-none alert-"+e),this},show:function(){return this.$el.slideDown("fast"),this.autoDismiss&&setTimeout($.proxy(this.close,this),3e3),this}}),t=new e;return t}),define("contentViewerRouter",["contentViewer","hint"],function(e,t){var n=Backbone.Router.extend({routes:{}}),r=new n;return r}),define("folderListRouter",[],function(){var e=Backbone.Router.extend({routes:{}}),t=new e;return t}),define("noteListRouter",[],function(){var e=Backbone.Router.extend({routes:{}}),t=new e;return t}),define("navbarRouter",[],function(){var e=Backbone.Router.extend({routes:{}}),t=new e;return t}),require.config({paths:{Database:"db/Database",folderDb:"db/folderDb",noteDb:"db/noteDb",FolderModel:"model/FolderModel",NoteModel:"model/NoteModel",setting:"model/setting",folderCollection:"collection/folderCollection",noteCollection:"collection/noteCollection",contentViewer:"view/contentViewer",folderList:"view/folderList",noteList:"view/noteList",navbar:"view/navbar",hint:"view/hint",contentViewerRouter:"router/contentViewerRouter",folderListRouter:"router/folderListRouter",noteListRouter:"router/noteListRouter",navbarRouter:"router/navbarRouter",util:"util/util"}}),require(["contentViewerRouter","folderListRouter","noteListRouter","navbarRouter"],function(e,t,n,r){Backbone.history.start()}),define("main",function(){});