<!--

    DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER.

    Copyright (c) 2013 Oracle and/or its affiliates. All rights reserved.

    The contents of this file are subject to the terms of either the GNU
    General Public License Version 2 only ("GPL") or the Common Development
    and Distribution License("CDDL") (collectively, the "License").  You
    may not use this file except in compliance with the License.  You can
    obtain a copy of the License at
    https://glassfish.dev.java.net/public/CDDL+GPL_1_1.html
    or packager/legal/LICENSE.txt.  See the License for the specific
    language governing permissions and limitations under the License.

    When distributing the software, include this License Header Notice in each
    file and include the License file at packager/legal/LICENSE.txt.

    GPL Classpath Exception:
    Oracle designates this particular file as subject to the "Classpath"
    exception as provided by Oracle in the GPL Version 2 section of the License
    file that accompanied this code.

    Modifications:
    If applicable, add the following below the License Header, with the fields
    enclosed by brackets [] replaced by your own identifying information:
    "Portions Copyright [year] [name of copyright owner]"

    Contributor(s):
    If you wish your version of this file to be governed by only the CDDL or
    only the GPL Version 2, indicate your decision by adding "[Contributor]
    elects to include this software in this distribution under the [CDDL or GPL
    Version 2] license."  If you don't indicate a single choice of license, a
    recipient has the option to distribute your version of this file under
    either the CDDL, the GPL Version 2 or to extend the choice of license to
    its licensees as provided above.  However, if you add GPL Version 2 code
    and therefore, elected the GPL Version 2 license, then the option applies
    only if the new code is made subject to such option by the copyright
    holder.

-->

<!-- concurrent/managedExecutorService.inc -->

<sun:propertySheet id="propertySheet">
    <sun:propertySheetSection id="propertSectionTextField">
        <sun:property id="nameNew"  rendered="#{!edit}" labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18n.common.jndiName}">
            <sun:textField id="name" styleClass="required"  required="#{true}" columns="$int{30}" maxLength="#{sessionScope.fieldLengths['maxLength.common.jndiName']}" text="#{pageSession.valueMap['name']}" >
                <!afterCreate
                    getClientId(component="$this{component}" clientId=>$page{resCompId});
                />
            </sun:textField>
        </sun:property>
        <sun:property id="name"  rendered="#{edit}" labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18n.common.jndiName}">
            <sun:staticText id="name" text="#{pageSession.Name}"  rendered="#{Edit}" />
        </sun:property>
                
        <sun:property id="contextInfo"  labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18ncon.contextInfoLabel}" helpText="$resource{i18ncon.contextInfoLabelHelp}">
            <sun:listbox id="contextInfo" immediate="#{true}"  rows="$int{6}" multiple="#{true}"
                labels="#{pageSession.ctxInfoOptions}" selected="#{pageSession.contextInfo}" >
                <!beforeCreate
                    getListBoxOptions(
                        availableList={ "Classloader", "JNDI", "Security", "WorkArea" },
                        selectedCommaString="#{pageSession.valueMap['contextInfo']}",
                        availableListResult="#{pageSession.ctxInfoOptions}",
                        selectedOptions="#{pageSession.contextInfo}"
                        addEmptyFirstChoice="true");
                />
            </sun:listbox>
        </sun:property>
                
        <sun:property id="statusProp"  rendered="#{useCheckBox}" labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18n.common.status}">
            <sun:checkbox label="$resource{i18n.common.Enabled}" selected="#{pageSession.valueMap['enabled']}" selectedValue="true" visible="#{false}" />
            <sun:checkbox id="enabled" label="$resource{i18n.common.Enabled}" selected="#{pageSession.valueMap2['enabled']}" selectedValue="true" />
        </sun:property>
        <sun:property id="statusProp2" rendered="#{useString}"  labelAlign="left" noWrap="#{true}" overlapLabel="#{false}"
            label="$resource{i18n.common.status}" helpText="$resource{i18n.application.EnableTargetHelp}">
            <sun:staticText  id="enabledStr" text="#{requestScope.enabledString}" >
                <!beforeCreate
                    gf.getTargetEnableInfo(appName="#{pageSession.encodedName}" isApp="#{false}" status="#{requestScope.enabledString}");
                />
           </sun:staticText>
       </sun:property>
                
       <sun:property id="threadPriorityProp" labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18ncon.threadPriorityLabel}"  helpText="$resource{i18ncon.threadPriorityLabelHelp}">
            <sun:textField id="threadPriorityProp" columns="$int{55}" maxLength="#{sessionScope.fieldLengths['maxLength.common.description']}" text="#{pageSession.valueMap['threadPriority']}" />      
       </sun:property>
       
       <sun:property id="longrunningtasks"  labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18ncon.longRunningTasks}">
            <sun:checkbox label="$resource{i18n.common.Enabled}" selected="#{pageSession.valueMap['longRunningTasks']}" selectedValue="true"  />
       </sun:property>
       
       <sun:property id="hungafter" labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18ncon.hungAfterSeconds}"  helpText="$resource{i18ncon.hungAfterSecondsHelp}">
            <sun:textField id="hungafter" columns="$int{55}" maxLength="#{sessionScope.fieldLengths['maxLength.common.description']}" text="#{pageSession.valueMap['hungAfterSeconds']}" />      
            <sun:staticText id="sec" style="padding: 8pt" text="$resource{i18n.common.Seconds}"/>
       </sun:property>
   </sun:propertySheetSection>
                
   <sun:propertySheetSection id="poolSettingsPropertySheet" label="$resource{i18ncon.propertySheetSection.poolSettings}">         
                
       <sun:property id="coresize" labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18ncon.corePoolSize}"  helpText="$resource{i18ncon.corePoolSizeHelp}">
            <sun:textField id="coresize" columns="$int{55}" maxLength="#{sessionScope.fieldLengths['maxLength.common.description']}" text="#{pageSession.valueMap['corePoolSize']}" />      
       </sun:property>
                
       <sun:property id="maximumPoolSize" labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18ncon.maximumPoolSize}"  helpText="$resource{i18ncon.maximumPoolSizeHelp}">
            <sun:textField id="maximumSize" columns="$int{55}" maxLength="#{sessionScope.fieldLengths['maxLength.common.description']}" text="#{pageSession.valueMap['maximumPoolSize']}" />      
       </sun:property>
                
       <sun:property id="keepAlive" labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18ncon.keepAliveSeconds}"  helpText="$resource{i18ncon.keepAliveSecondsHelp}">
            <sun:textField id="keepAlive" columns="$int{55}" maxLength="#{sessionScope.fieldLengths['maxLength.common.description']}" text="#{pageSession.valueMap['keepAliveSeconds']}" />      
            <sun:staticText id="sec" style="padding: 8pt" text="$resource{i18n.common.Seconds}"/>
       </sun:property>
                
       <sun:property id="threadLifetime" labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18ncon.threadLifetimeSeconds}"  helpText="$resource{i18ncon.threadLifetimeSecondsHelp}">
            <sun:textField id="threadLifetime" columns="$int{55}" maxLength="#{sessionScope.fieldLengths['maxLength.common.description']}" text="#{pageSession.valueMap['threadLifetimeSeconds']}" />      
            <sun:staticText id="sec" style="padding: 8pt" text="$resource{i18n.common.Seconds}"/>
       </sun:property>
                
       <sun:property id="taskQueueCapacity" labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18ncon.taskQueueCapacity}"  helpText="$resource{i18ncon.taskQueueCapacityHelp}">
            <sun:textField id="taskQueueCapacity" columns="$int{55}" maxLength="#{sessionScope.fieldLengths['maxLength.common.description']}" text="#{pageSession.valueMap['taskQueueCapacity']}" />      
       </sun:property>   
                
       <sun:property id="descProp" labelAlign="left" noWrap="#{true}" overlapLabel="#{false}" label="$resource{i18n.common.description}">
            <sun:textField id="desc" columns="$int{55}" maxLength="#{sessionScope.fieldLengths['maxLength.common.description']}" text="#{pageSession.valueMap['description']}" />      
       </sun:property>
        "<br /><br />
    </sun:propertySheetSection>
</sun:propertySheet>