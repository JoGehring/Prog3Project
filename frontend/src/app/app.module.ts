import { HttpClientModule } from '@angular/common/http';
import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { BrowserModule } from '@angular/platform-browser';
import { FlaggedComponent } from 'src/lib/ui/flagged/flagged.component';
import { ListComponent } from 'src/lib/ui/list/list.component';
import { ReminderComponent } from 'src/lib/ui/reminder/reminder.component';
import { ReminderAppComponent } from 'src/lib/ui/reminderApp/reminderApp.component';
import { TodayComponent } from 'src/lib/ui/today/today.component';
import { ToolbarComponent } from 'src/lib/ui/toolbar/toolbar.component';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';


@NgModule({
  declarations: [AppComponent, ToolbarComponent, ReminderAppComponent, ReminderComponent, ListComponent, TodayComponent, FlaggedComponent],
  imports: [BrowserModule, AppRoutingModule, FormsModule, HttpClientModule],
  providers: [],
  bootstrap: [AppComponent],
})
export class AppModule {}
