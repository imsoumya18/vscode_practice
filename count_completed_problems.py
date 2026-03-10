#!/usr/bin/env python3
"""
Script to count completed problems per week from README.md
Separates new and revision problems with total and solved counts
"""

import re


def count_problems_by_section(section_content):
    """
    Count total and solved problems in a section.
    
    Args:
        section_content (str): Content of the section (New or Revision)
    
    Returns:
        tuple: (total_count, solved_count)
    """
    # Count total problems (lines that start with | and have problem data)
    # Pattern: | `X.X.X` | Problem name | Difficulty | ...
    # The problem IDs can have 1-2 digits for each part
    total_problems = len(re.findall(r'\|\s*`\d+\.\d+\.\d+`\s*\|', section_content))
    
    # Count solved problems (lines with ✅ in the Solved column)
    solved_problems = len(re.findall(r'\|\s*✅\s*\|', section_content))
    
    return total_problems, solved_problems



def count_completed_problems(file_path):
    """
    Count the number of completed problems in each week from the README.md file.
    Separates new and revision problems.
    
    Args:
        file_path (str): Path to the README.md file
    
    Returns:
        dict: Dictionary with week numbers as keys and problem counts as values
    """
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Dictionary to store counts for each week
    week_data = {}
    
    # Find all week sections
    for week_num in range(1, 17):  # Weeks 1-16
        # Match the specific week section
        if week_num < 16:
            pattern = rf'## 📆 Week {week_num}\n(.*?)## 📆 Week {week_num + 1}'
        else:
            pattern = rf'## 📆 Week {week_num}\n(.*?)## 💡 Tips'
        
        week_match = re.search(pattern, content, re.DOTALL)
        
        if not week_match:
            # Try alternative end pattern for last week
            pattern = rf'## 📆 Week {week_num}\n(.*?)(?:---\n\n## |$)'
            week_match = re.search(pattern, content, re.DOTALL)
        
        if week_match:
            week_content = week_match.group(1)
            
            # Find New Problems section
            new_match = re.search(r'### 🆕 New Problems(.*?)### 🔄 Revision', 
                                 week_content, re.DOTALL)
            # Find Revision section - ends with newline followed by ---
            revision_match = re.search(r'### 🔄 Revision(.*?)(?:\n---|\Z)', 
                                      week_content, re.DOTALL)
            
            new_total, new_solved = 0, 0
            revision_total, revision_solved = 0, 0
            
            if new_match:
                new_total, new_solved = count_problems_by_section(new_match.group(1))
            
            if revision_match:
                revision_total, revision_solved = count_problems_by_section(revision_match.group(1))
            
            week_data[week_num] = {
                'new': {'total': new_total, 'solved': new_solved},
                'revision': {'total': revision_total, 'solved': revision_solved}
            }
    
    return week_data



def display_results(week_data):
    """
    Display the results in the requested format.
    
    Args:
        week_data (dict): Dictionary with week numbers and problem counts
    """
    print("\n" + "=" * 60)
    print("📊 COMPLETED PROBLEMS PER WEEK")
    print("=" * 60)
    
    total_new_problems = 0
    total_new_solved = 0
    total_revision_problems = 0
    total_revision_solved = 0
    
    for week_num in sorted(week_data.keys()):
        data = week_data[week_num]
        new_total = data['new']['total']
        new_solved = data['new']['solved']
        rev_total = data['revision']['total']
        rev_solved = data['revision']['solved']
        
        # Accumulate totals
        total_new_problems += new_total
        total_new_solved += new_solved
        total_revision_problems += rev_total
        total_revision_solved += rev_solved
        
        print(f"\nWeek {week_num}:")
        
        # Determine status emoji for New section
        if new_total > 0 and new_solved == new_total:
            new_status = "☑️  "
        elif new_solved > 0:
            new_status = "🔄 "
        else:
            new_status = "   "
        
        # Determine status emoji for Revision section
        if rev_total > 0 and rev_solved == rev_total:
            rev_status = "☑️  "
        elif rev_solved > 0:
            rev_status = "🔄 "
        else:
            rev_status = "   "
        
        print(f"  {new_status}New:      total: {new_total:3d}, solved: {new_solved:3d}")
        print(f"  {rev_status}Revision: total: {rev_total:3d}, solved: {rev_solved:3d}")
    
    print("\n" + "=" * 60)
    print("OVERALL SUMMARY:")
    print(f"  New:      total: {total_new_problems:3d}, solved: {total_new_solved:3d}")
    print(f"  Revision: total: {total_revision_problems:3d}, solved: {total_revision_solved:3d}")
    print(f"  TOTAL:    total: {total_new_problems + total_revision_problems:3d}, solved: {total_new_solved + total_revision_solved:3d}")
    print("=" * 60)
    print()


def main():
    """Main function to run the script."""
    file_path = '/Users/soumya/VS Code Projects/vscode_practice/README.md'
    
    print("🔍 Analyzing README.md file...")
    
    try:
        week_data = count_completed_problems(file_path)
        display_results(week_data)
        
    except FileNotFoundError:
        print(f"❌ Error: File not found at {file_path}")
    except Exception as e:
        print(f"❌ Error: {e}")


if __name__ == "__main__":
    main()
